#include <array>
#include <algorithm>
#include <cctype>
#include <climits>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "json.hpp"
#ifdef _WIN32
#include <windows.h>
#include <bcrypt.h>
#else
#include <CommonCrypto/CommonDigest.h>
#include <fcntl.h>
#include <unistd.h>
#endif

using json = nlohmann::json;
namespace fs = std::filesystem;

static void require(bool condition, const std::string& message) {
    if (!condition) throw std::runtime_error(message);
}

class Digest {
#ifdef _WIN32
    BCRYPT_ALG_HANDLE algorithm_ = nullptr;
    BCRYPT_HASH_HANDLE hash_ = nullptr;
    std::vector<unsigned char> object_;
#else
    CC_SHA256_CTX sha256_{};
    CC_SHA1_CTX sha1_{};
#endif
    bool sha256_mode_;
public:
    explicit Digest(bool sha256_mode) : sha256_mode_(sha256_mode) {
#ifdef _WIN32
        require(BCryptOpenAlgorithmProvider(&algorithm_, sha256_mode ? BCRYPT_SHA256_ALGORITHM : BCRYPT_SHA1_ALGORITHM,
                                            nullptr, 0) >= 0, "Cannot open digest provider");
        DWORD length = 0, result = 0;
        if (BCryptGetProperty(algorithm_, BCRYPT_OBJECT_LENGTH, reinterpret_cast<PUCHAR>(&length),
                              sizeof(length), &result, 0) < 0) {
            BCryptCloseAlgorithmProvider(algorithm_, 0);
            throw std::runtime_error("Cannot query digest provider");
        }
        object_.resize(length);
        if (BCryptCreateHash(algorithm_, &hash_, object_.data(), length, nullptr, 0, 0) < 0) {
            BCryptCloseAlgorithmProvider(algorithm_, 0);
            throw std::runtime_error("Cannot create digest");
        }
#else
        if (sha256_mode_) CC_SHA256_Init(&sha256_);
        else CC_SHA1_Init(&sha1_);
#endif
    }
    Digest(const Digest&) = delete;
    Digest& operator=(const Digest&) = delete;
    ~Digest() {
#ifdef _WIN32
        if (hash_) BCryptDestroyHash(hash_);
        if (algorithm_) BCryptCloseAlgorithmProvider(algorithm_, 0);
#endif
    }
    void update(const void* data, size_t length) {
#ifdef _WIN32
        require(length <= ULONG_MAX && BCryptHashData(hash_, reinterpret_cast<PUCHAR>(const_cast<void*>(data)),
                                                      static_cast<ULONG>(length), 0) >= 0, "Cannot update digest");
#else
        if (sha256_mode_) CC_SHA256_Update(&sha256_, data, static_cast<CC_LONG>(length));
        else CC_SHA1_Update(&sha1_, data, static_cast<CC_LONG>(length));
#endif
    }
    std::string finish() {
        std::array<unsigned char, 32> bytes{};
        const size_t length = sha256_mode_ ? 32 : 20;
#ifdef _WIN32
        require(BCryptFinishHash(hash_, bytes.data(), static_cast<ULONG>(length), 0) >= 0, "Cannot finish digest");
#else
        if (sha256_mode_) CC_SHA256_Final(bytes.data(), &sha256_);
        else CC_SHA1_Final(bytes.data(), &sha1_);
#endif
        std::ostringstream result;
        for (size_t i = 0; i < length; ++i)
            result << std::hex << std::setw(2) << std::setfill('0') << static_cast<unsigned>(bytes[i]);
        return result.str();
    }
};

static bool hex(const std::string& value, size_t length) {
    return value.size() == length && value.find_first_not_of("0123456789abcdef") == std::string::npos;
}

static bool safe_path(const std::string& value) {
    if (value.empty() || value.front() == '/' || value.find_first_of("\\:\r\n\0", 0, 5) != std::string::npos)
        return false;
    std::istringstream input(value);
    std::string part;
    while (std::getline(input, part, '/')) {
        if (part.empty() || part == "." || part == ".." || part.back() == '.' || part.back() == ' ') return false;
        std::string upper = part.substr(0, part.find('.'));
        for (auto& c : upper) c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        if (upper == "CON" || upper == "PRN" || upper == "AUX" || upper == "NUL" ||
            (upper.size() == 4 && (upper.substr(0, 3) == "COM" || upper.substr(0, 3) == "LPT") &&
             upper[3] >= '0' && upper[3] <= '9')) return false;
    }
    return value.back() != '/' && value.find_first_of("\"<>|?*") == std::string::npos;
}

static std::string encode(const std::string& path) {
    std::ostringstream result;
    for (unsigned char c : path) {
        if (std::isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || c == '/') result << c;
        else result << '%' << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << unsigned(c);
    }
    return result.str();
}

static fs::path absolute(const std::string& path) {
    auto result = fs::u8path(path);
    require(result.is_absolute(), "Cache paths must be absolute");
    return result.lexically_normal();
}

static void no_symlinks(const fs::path& path) {
    auto current = path;
    while (!current.empty()) {
        require(!fs::is_symlink(fs::symlink_status(current)), "Symlink cache paths are not supported");
        auto parent = current.parent_path();
        if (parent == current) break;
        current = parent;
    }
}

static json identity(const json& request) {
    std::string repo = request.at("repo").get<std::string>();
    const std::string prefix = "https://huggingface.co/";
    if (repo.compare(0, prefix.size(), prefix) == 0) repo.erase(0, prefix.size());
    require(safe_path(repo), "Invalid Hugging Face repository");
    const auto slash = repo.find('/');
    require(slash != std::string::npos, "Expected owner/repository");
    repo = repo.substr(0, repo.find('/', slash + 1));
    for (unsigned char c : repo)
        require(std::isalnum(c) || c == '/' || c == '-' || c == '_' || c == '.', "Invalid repository name");
    auto destination = absolute(request.at("destination").get<std::string>());
    const bool is_file = request.at("is_file").get<bool>();
    require(!is_file || !fs::is_symlink(fs::symlink_status(destination)), "Model files cannot be symlinks");
    // Resolve the explicitly chosen root (including macOS /var and /tmp aliases),
    // then reject any symlink introduced below that root when planning/verifying files.
    destination = is_file ? fs::weakly_canonical(destination.parent_path()) / destination.filename()
                          : fs::weakly_canonical(destination);
    no_symlinks(destination);
    auto paths = request.at("paths");
    require(paths.is_array(), "Expected paths array");
    std::set<std::string> seen;
    for (const auto& path : paths) {
        const auto text = path.get<std::string>();
        require(safe_path(text) && seen.insert(text).second, "Unsafe or duplicate selected path");
    }
    require(!is_file || paths.size() == 1, "A file destination requires exactly one upstream filename");
    return {{"repo", repo}, {"destination", destination.u8string()}, {"is_file", is_file},
            {"paths", paths}, {"domain", request.at("domain")}};
}

static fs::path receipt_path(const json& id) {
    Digest digest(true);
    const std::string serialized = id.dump();
    digest.update(serialized.data(), serialized.size());
    auto root = absolute(id.at("destination"));
    if (id.at("is_file")) root = root.parent_path();
    return root / (".sd-download-" + digest.finish() + ".json");
}

static json plan(const json& id, const json& metadata) {
    require(metadata.is_object() && metadata.contains("sha") && metadata.contains("siblings"),
            "Missing repository revision/file metadata");
    std::string revision = metadata.at("sha");
    require(hex(revision, 40), "Invalid repository revision");
    require(metadata.at("siblings").is_array() && !metadata.at("siblings").empty(), "Empty repository metadata");
    const auto root = absolute(id.at("destination"));
    const auto selected = id.at("paths").get<std::vector<std::string>>();
    json files = json::array();
    std::set<std::string> seen;
    for (const auto& entry : metadata.at("siblings")) {
        require(entry.is_object() && entry.contains("rfilename"), "Invalid file metadata");
        std::string path = entry.at("rfilename");
        require(safe_path(path) && seen.insert(path).second, "Unsafe or duplicate repository path");
        if (!selected.empty() && std::find(selected.begin(), selected.end(), path) == selected.end()) continue;
        require(entry.contains("size") && entry.at("size").is_number_integer() &&
                entry.at("size").get<int64_t>() >= 0, "Missing or invalid file size: " + path);
        const auto size = entry.at("size").get<uint64_t>();
        std::string algorithm = "git-sha1";
        std::string digest = entry.value("blobId", "");
        if (entry.contains("lfs")) {
            const auto& lfs = entry.at("lfs");
            require(lfs.is_object() && lfs.contains("size") && lfs.at("size") == entry.at("size"),
                    "Invalid LFS size: " + path);
            algorithm = "sha256";
            digest = lfs.value("sha256", "");
        }
        require(hex(digest, algorithm == "sha256" ? 64 : 40), "Missing authoritative file hash: " + path);
        const auto destination = id.at("is_file").get<bool>() ? root : root / fs::u8path(path);
        no_symlinks(destination);
        files.push_back({{"path", path}, {"destination", destination.u8string()}, {"size", size},
                         {"algorithm", algorithm}, {"digest", digest}, {"domain", id.at("domain")},
                         {"url", "https://huggingface.co/" + id.at("repo").get<std::string>() +
                                 "/resolve/" + revision + "/" + encode(path)}});
    }
    require(!files.empty() && (selected.empty() || files.size() == selected.size()),
            "Requested model file(s) are missing from repository metadata");
    return {{"version", 1}, {"identity", id}, {"metadata", metadata}, {"files", files}};
}

static bool verify(const fs::path& path, const json& file) {
    no_symlinks(path);
    require(file.at("size").is_number_integer() && file.at("size").get<int64_t>() >= 0, "Invalid expected size");
    const auto size = file.at("size").get<uint64_t>();
    const std::string algorithm = file.at("algorithm");
    const std::string expected = file.at("digest");
    require((algorithm == "sha256" && hex(expected, 64)) || (algorithm == "git-sha1" && hex(expected, 40)),
            "Unsupported or invalid content identity");
    if (!fs::exists(path) || !fs::is_regular_file(path) || fs::file_size(path) != size) return false;
    std::ifstream input(path, std::ios::binary);
    require(input.good(), "Cannot read cache file");
    Digest digest(algorithm == "sha256");
    if (algorithm == "git-sha1") {
        std::string header = "blob " + std::to_string(size);
        header.push_back('\0');
        digest.update(header.data(), header.size());
    }
    std::vector<char> buffer(1024 * 1024);
    uint64_t count = 0;
    while (input) {
        input.read(buffer.data(), buffer.size());
        const auto read = input.gcount();
        if (read > 0) {
            count += static_cast<uint64_t>(read);
            if (count > size) return false;
            digest.update(buffer.data(), static_cast<size_t>(read));
        }
    }
    require(!input.bad() && input.eof(), "Cache file read failed");
    return count == size && digest.finish() == expected;
}

static void replace(const fs::path& source, const fs::path& destination) {
    require(source.parent_path() == destination.parent_path() && source != destination,
            "Atomic promotion requires distinct files in the same directory");
    no_symlinks(source);
    no_symlinks(destination);
#ifdef _WIN32
    require(MoveFileExW(source.c_str(), destination.c_str(), MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH) != 0,
            "Atomic cache replacement failed");
#else
    int fd = ::open(source.c_str(), O_RDONLY);
    require(fd >= 0, "Cannot open cache candidate for sync");
    const int synced = ::fsync(fd);
    ::close(fd);
    require(synced == 0, "Cannot sync cache candidate");
    require(::rename(source.c_str(), destination.c_str()) == 0, "Atomic cache replacement failed");
#endif
}

static void save(const fs::path& destination, const json& value) {
    fs::create_directories(destination.parent_path());
    no_symlinks(destination);
    auto temporary = destination;
    temporary += ".tmp";
    require(!fs::exists(temporary), "Cache receipt is locked by another writer; inspect stale .tmp file");
    // Exclusive creation prevents concurrent receipt writers from sharing a temporary file.
#ifdef _WIN32
    HANDLE handle = CreateFileW(temporary.c_str(), GENERIC_WRITE, 0, nullptr, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, nullptr);
    require(handle != INVALID_HANDLE_VALUE, "Cannot reserve cache receipt");
    CloseHandle(handle);
#else
    int fd = ::open(temporary.c_str(), O_CREAT | O_EXCL | O_WRONLY, 0600);
    require(fd >= 0, "Cannot reserve cache receipt");
    ::close(fd);
#endif
    try {
        {
            std::ofstream output(temporary, std::ios::binary | std::ios::trunc);
            output << value.dump();
            output.close();
            require(!output.fail(), "Cannot write cache receipt");
        }
        replace(temporary, destination);
    } catch (...) {
        std::error_code error;
        fs::remove(temporary, error);
        throw;
    }
}

static json execute(const json& request) {
    const std::string operation = request.at("operation");
    if (operation == "descriptor") return {{"descriptor", identity(request.at("descriptor"))}};
    if (operation == "plan" || operation == "load-plan") {
        const auto id = identity(request.at("descriptor"));
        if (operation == "plan") {
            const auto& supplied = request.at("metadata");
            const auto metadata = supplied.is_string() ? json::parse(supplied.get<std::string>()) : supplied;
            return {{"plan", plan(id, metadata)}};
        }
        const auto receipt = receipt_path(id);
        no_symlinks(receipt);
        require(fs::is_regular_file(receipt) && fs::file_size(receipt) <= 20 * 1024 * 1024,
                "Offline cache has no verified metadata receipt; connect once to verify existing files");
        std::ifstream input(receipt, std::ios::binary);
        const auto stored = json::parse(input);
        require(stored.at("version") == 1 && stored.at("identity") == id, "Offline cache receipt identity mismatch");
        const auto restored = plan(id, stored.at("metadata"));
        require(restored.at("files") == stored.at("files"), "Offline cache receipt was modified");
        for (const auto& file : restored.at("files"))
            require(verify(absolute(file.at("destination")), file), "Offline cache is missing or corrupt: " +
                    file.at("path").get<std::string>());
        return {{"plan", restored}};
    }
    if (operation == "verify") {
        const auto file = request.at("file");
        return {{"valid", verify(absolute(file.at("destination")), file)}};
    }
    if (operation == "commit") {
        const auto file = request.at("file");
        const auto candidate = absolute(request.at("candidate"));
        require(verify(candidate, file), "Downloaded content failed size/hash verification");
        replace(candidate, absolute(file.at("destination")));
        return {{"valid", true}};
    }
    if (operation == "save-plan") {
        const auto supplied = request.at("plan");
        const auto id = identity(supplied.at("identity"));
        const auto checked = plan(id, supplied.at("metadata"));
        require(checked == supplied, "Invalid cache receipt");
        for (const auto& file : checked.at("files"))
            require(verify(absolute(file.at("destination")), file), "Cannot record unverified cache content");
        save(receipt_path(id), checked);
        return {{"saved", true}};
    }
    if (operation == "redirect") {
        std::string location = request.at("location");
        require(!location.empty() && location.find_first_of("\r\n\\") == std::string::npos &&
                location.find('\0') == std::string::npos, "Invalid redirect");
        if (location.front() == '/' && location.compare(0, 2, "//") != 0) {
            const std::string base = request.value("base", "https://huggingface.co/");
            require(base.compare(0, 8, "https://") == 0, "Invalid redirect base");
            location = base.substr(0, base.find('/', 8)) + location;
        }
        require(location.compare(0, 8, "https://") == 0, "Download redirects must use HTTPS");
        require(std::all_of(location.begin(), location.end(), [](unsigned char c) {
            return c > 0x20 && c != 0x7f;
        }), "Invalid redirect characters");
        const auto host_end = location.find('/', 8);
        const auto host = location.substr(8, host_end - 8);
        require(!host.empty() && host.find_first_of("@?#: ") == std::string::npos, "Invalid redirect authority");
        return {{"url", location}, {"authorize", host == "huggingface.co"}};
    }
    throw std::runtime_error("Unknown cache operation");
}

int main() {
    try {
        std::string input;
        std::array<char, 8192> buffer{};
        while (std::cin) {
            std::cin.read(buffer.data(), buffer.size());
            input.append(buffer.data(), static_cast<size_t>(std::cin.gcount()));
            require(input.size() <= 20 * 1024 * 1024, "Cache request is too large");
        }
        auto result = execute(json::parse(input));
        result["success"] = true;
        std::cout << result.dump() << '\n';
        return 0;
    } catch (const std::exception& error) {
        std::cout << json({{"success", false}, {"message", error.what()}}).dump() << '\n';
        return 1;
    }
}
