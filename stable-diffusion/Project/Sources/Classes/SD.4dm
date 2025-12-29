Class extends _interface

Class constructor($port : Integer; $huggingfaces : cs:C1710.event.huggingfaces; $options : Object; $event : cs:C1710.event.event)
	
	Super:C1705()
	
	var $SD : cs:C1710.workers.worker
	$SD:=cs:C1710.workers.worker.new(cs:C1710._server)
	
	If (Not:C34($SD.isRunning($port)))
		
		var $homeFolder : 4D:C1709.Folder
		$homeFolder:=Folder:C1567(fk home folder:K87:24).folder(".Stable-Diffusion")
		
		If ($huggingfaces=Null:C1517) || (Not:C34(OB Instance of:C1731($huggingfaces; cs:C1710.event.huggingfaces))) || ($huggingfaces.huggingfaces.length=0)
			$model:=$homeFolder.file("gpustack/stable-diffusion-xl-1.0-turbo/stable-diffusion-xl-1.0-turbo-Q4_0.gguf")
			$path:=""
			$URL:="gpustack/stable-diffusion-xl-1.0-turbo-GGUF/stable-diffusion-xl-1.0-turbo-Q4_0.gguf"
			$image:=cs:C1710.event.huggingface.new($model; $URL; $path; "image")
			$huggingfaces:=cs:C1710.event.huggingfaces.new([$image])
		End if 
		
		If ($port=0) || ($port<0) || ($port>65535)
			$port:=8080
		End if 
		
		This:C1470._main($port; $huggingfaces; $options; $event)
		
	End if 
	
Function _main($port : Integer; $huggingfaces : cs:C1710.event.huggingfaces; $options : Object; $event : cs:C1710.event.event)
	
	main({name: Split string:C1554(Current method name:C684; "."; sk trim spaces:K86:2).first(); port: $port; huggingfaces: $huggingfaces; options: $options; event: $event}; This:C1470._onTCP)