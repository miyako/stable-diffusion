---
layout: default
---

![version](https://img.shields.io/badge/version-20%2B-E23089)
![platform](https://img.shields.io/static/v1?label=platform&message=mac-intel%20|%20mac-arm%20|%20win-64&color=blue)
[![license](https://img.shields.io/github/license/miyako/stable-diffusion)](LICENSE)
![downloads](https://img.shields.io/github/downloads/miyako/stable-diffusion/total)

# Use Stable Diffusion from 4D

#### Abstract

T.B.D.

#### Usage

Instantiate `cs.SD.SD` in your *On Startup* database method:

```4d
var $SD : cs.SD.SD

If (False)
    $SD:=cs.SD.SD.new()  //default
Else 
    var $homeFolder : 4D.Folder
    $homeFolder:=Folder(fk home folder).folder(".Stable-Diffusion")
    var $URL : Text
    var $port : Integer
    
    var $event : cs.event.event
    $event:=cs.event.event.new()
    /*
        Function onError($params : Object; $error : cs.event.error)
        Function onSuccess($params : Object; $models : cs.event.models)
        Function onData($request : 4D.HTTPRequest; $event : Object)
        Function onResponse($request : 4D.HTTPRequest; $event : Object)
        Function onTerminate($worker : 4D.SystemWorker; $params : Object)
    */
    
    $event.onError:=Formula(ALERT($2.message))
    $event.onSuccess:=Formula(ALERT($2.models.extract("name").join(",")+" loaded!"))
    $event.onData:=Formula(LOG EVENT(Into 4D debug message; This.file.fullName+":"+String((This.range.end/This.range.length)*100; "###.00%")))
    $event.onData:=Formula(MESSAGE(This.file.fullName+":"+String((This.range.end/This.range.length)*100; "###.00%")))
    $event.onResponse:=Formula(LOG EVENT(Into 4D debug message; This.file.fullName+":download complete"))
    $event.onResponse:=Formula(MESSAGE(This.file.fullName+":download complete"))
    $event.onTerminate:=Formula(LOG EVENT(Into 4D debug message; (["process"; $1.pid; "terminated!"].join(" "))))
    
    $port:=8080
    
    $model:=$homeFolder.file("gpustack/stable-diffusion-xl-1.0-turbo/stable-diffusion-xl-1.0-turbo-Q4_0.gguf")
    $path:=""
    $URL:="gpustack/stable-diffusion-xl-1.0-turbo-GGUF/stable-diffusion-xl-1.0-turbo-Q4_0.gguf"
    $image:=cs.event.huggingface.new($model; $URL; $path; "image"; "stable-diffusion-xl-1.0-turbo-Q4_0.gguf")
    
    $options:={listen_ip: "0.0.0.0"}
    var $huggingfaces : cs.event.huggingfaces
    $huggingfaces:=cs.event.huggingfaces.new([$image])
    
    $SD:=cs.SD.SD.new($port; $huggingfaces; $options; $event)
    
End if 
```

Unless the server is already running (in which case the costructor does nothing), the following procedure runs in the background:

1. The specified model is downloaded via HTTP
2. The `sd-server` program is started

Now you can test the server:

```
curl http://localhost:8080/v1/images/generations \
  -H "Content-Type: application/json" \
  -d '{
    "prompt": "A futuristic city with flying cars, cyberpunk style, cinematic lighting",
    "size": "512x512",
    "n": 1,
    "response_format": "url"
  }' > response.json
```

Or, use AI Kit:

```4d
var $AIClient : cs.AIKit.OpenAI
$AIClient:=cs.AIKit.OpenAI.new()

$AIClient.baseURL:="http://localhost:8080/v1/images/generations"
$AIClient.apiKey:=""

var $text : Text
$text:="A futuristic city with flying cars, cyberpunk style, cinematic lighting"

var $parameters : cs.AIKit.OpenAIImageParameters
$parameters:=cs.AIKit.OpenAIImageParameters.new()
$parameters.size:="512x512"
$parameters.model:=""

var $result : cs.AIKit.OpenAIImagesResult
$result:=$AIClient.images.generate($text; $parameters)

Case of 
    : ($parameters.response_format="b64_json")
        var $data : Blob
         Case of 
    : ($result.image.b64_json#Null)
        BASE64 DECODE($result.image.b64_json; $data)
        Folder(fk desktop folder).file("skylinecity."+$parameters.model+".jpeg").setContent($data)
    : ($result.image.url#Null)
        If (200=HTTP Get($result.image.url; $data))
            Folder(fk desktop folder).file("skylinecity."+$parameters.model+".jpeg").setContent($data)
        End if 
         End case 
    Else 
        $result.image.saveToDisk(Folder(fk desktop folder).file("skylinecity."+$parameters.model+".png"))
End case
```

Finally to terminate the server:

```4d
var $SD : cs.SD
$SD:=cs.SD.new()
$SD.terminate()
```

#### Models

T.B.D.

#### AI Kit compatibility

The API is compatibile with [Open AI](https://platform.openai.com/docs/api-reference/embeddings). 

|Class|API|Availability|
|-|-|:-:|
|Models|`/v1/models`|✅|
|Chat|`/v1/chat/completions`||
|Images|`/v1/images/generations`|✅|
|Moderations|`/v1/moderations`||
|Embeddings|`/v1/embeddings`||
|Files|`/v1/files`||
