TRACE:C157
var $SD : cs:C1710.SD

If (False:C215)
	$SD:=cs:C1710.SD.new()  //default
Else 
	var $homeFolder : 4D:C1709.Folder
	$homeFolder:=Folder:C1567(fk home folder:K87:24).folder(".Stable-Diffusion")
	var $URL : Text
	var $port : Integer
	
	var $event : cs:C1710.event.event
	$event:=cs:C1710.event.event.new()
/*
Function onError($params : Object; $error : cs.event.error)
Function onSuccess($params : Object; $models : cs.event.models)
Function onData($request : 4D.HTTPRequest; $event : Object)
Function onResponse($request : 4D.HTTPRequest; $event : Object)
Function onTerminate($worker : 4D.SystemWorker; $params : Object)
*/
	
	$event.onError:=Formula:C1597(ALERT:C41($2.message))
	$event.onSuccess:=Formula:C1597(ALERT:C41($2.models.extract("name").join(",")+" loaded!"))
	$event.onData:=Formula:C1597(LOG EVENT:C667(Into 4D debug message:K38:5; This:C1470.file.fullName+":"+String:C10((This:C1470.range.end/This:C1470.range.length)*100; "###.00%")))
	$event.onData:=Formula:C1597(MESSAGE:C88(This:C1470.file.fullName+":"+String:C10((This:C1470.range.end/This:C1470.range.length)*100; "###.00%")))
	$event.onResponse:=Formula:C1597(LOG EVENT:C667(Into 4D debug message:K38:5; This:C1470.file.fullName+":download complete"))
	$event.onResponse:=Formula:C1597(MESSAGE:C88(This:C1470.file.fullName+":download complete"))
	$event.onTerminate:=Formula:C1597(LOG EVENT:C667(Into 4D debug message:K38:5; (["process"; $1.pid; "terminated!"].join(" "))))
	
	$port:=8080
	
	$model:=$homeFolder.file("gpustack/stable-diffusion-xl-1.0-turbo/stable-diffusion-xl-1.0-turbo-Q4_0.gguf")
	$path:=""
	$URL:="gpustack/stable-diffusion-xl-1.0-turbo-GGUF/stable-diffusion-xl-1.0-turbo-Q4_0.gguf"
	$image:=cs:C1710.event.huggingface.new($model; $URL; $path; "image"; "stable-diffusion-xl-1.0-turbo-Q4_0.gguf")
	
	$options:={host: "0.0.0.0"}
	var $huggingfaces : cs:C1710.event.huggingfaces
	$huggingfaces:=cs:C1710.event.huggingfaces.new([$image])
	
	$SD:=cs:C1710.SD.new($port; $huggingfaces; $options; $event)
	
End if 