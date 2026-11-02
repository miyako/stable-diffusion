// Test-only method: run in a worker in a disposable component project copy.
// Start scripts/tests/download_fixture.py first; stage sd-cache in /RESOURCES/bin/{platform}.
var $root : 4D:C1709.Folder
$root:=Folder:C1567(fk temporary folder).folder("sd-download-tests-"+Generate UUID:C1066)
$root.create()
var $owner : cs:C1710._DownloadTestOwner
var $file : 4D:C1709.File
$file:=$root.file("model.bin")
$owner:=cs:C1710._DownloadTestOwner.new($file; "success")
$owner.run()
ASSERT:C1129($owner.starts=1; "Successful transfer must start once")
ASSERT:C1129($owner.failures=0; "Successful transfer must not fail")
ASSERT:C1129($file.getText("UTF-8"; Document with LF)="fixture model\n"; "Content differs")

$owner:=cs:C1710._DownloadTestOwner.new($file; "http-500")
$owner.run()
ASSERT:C1129($owner.starts=1; "Verified cache must bypass failing download endpoint")

$owner:=cs:C1710._DownloadTestOwner.new($file; "transport")
$owner.run()
ASSERT:C1129($owner.offline && ($owner.starts=1); "Verified offline cache must work")
$file.setText("corrupt cache!")
$owner:=cs:C1710._DownloadTestOwner.new($file; "transport")
ASSERT:C1129($owner.failed && ($owner.failures=1); "Corrupt offline cache must fail once")

var $case : Text
For each ($case; ["http-401"; "http-403"; "http-404"; "http-429"; "http-500"; "corrupt"; "truncated"; "wrong-length"])
	$file.setText("previous good model")
	$owner:=cs:C1710._DownloadTestOwner.new($file; $case)
	$owner.run()
	ASSERT:C1129($owner.failed && ($owner.failures=1) && ($owner.starts=0); "Download failure must terminate once: "+$case)
	ASSERT:C1129($file.getText()="previous good model"; "Failed candidate replaced existing cache: "+$case)
	$owner.fail("Duplicate failure"; "test")
	ASSERT:C1129($owner.failures=1; "Duplicate failure callback")
End for each

For each ($case; ["metadata-http-401"; "metadata-http-403"; "metadata-http-404"; "metadata-http-429"; "metadata-http-500"; "invalid"; "empty"; "missing"])
	$owner:=cs:C1710._DownloadTestOwner.new($file; $case)
	ASSERT:C1129($owner.failed && ($owner.failures=1) && ($owner.starts=0); "Metadata failure must terminate once: "+$case)
End for each

$file.delete()
$owner:=cs:C1710._DownloadTestOwner.new($file; "transport")
ASSERT:C1129($owner.failed && ($owner.failures=1); "Missing offline file must fail")
$owner:=cs:C1710._DownloadTestOwner.new($file; "no-length")
$owner.run()
ASSERT:C1129($owner.starts=1; "A valid GET without Content-Length must work")
$owner.onDownload("1")
ASSERT:C1129($owner.starts=1; "Duplicate completion must not start again")
$owner:=cs:C1710._DownloadTestOwner.new($root.file("unverified.bin"); "transport")
ASSERT:C1129($owner.failed && ($owner.failures=1); "No offline receipt must fail")
var $empty : cs:C1710._models
var $emptyFailures : Object
$emptyFailures:={count: 0}
$empty:=cs:C1710._models.new(8080; cs:C1710.event.huggingfaces.new([]); {}; Formula:C1597($emptyFailures.count+=1); cs:C1710.event.event.new())
ASSERT:C1129($empty.failed && ($emptyFailures.count=1); "An empty request must fail exactly once")
LOG EVENT:C667(Into 4D debug message:K38:5; "PASS: real 4D download callbacks, cache/offline, HTTP/transport failures and terminal propagation")
