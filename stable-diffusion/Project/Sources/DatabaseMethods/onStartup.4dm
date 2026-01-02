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
	
	var $huggingfaces : cs:C1710.event.huggingfaces
	
	Case of 
		: (False:C215)
			
			//vae [335 MB]
			$model:=$homeFolder.file("second-state/FLUX.1-dev-GGUF/ae.safetensors")
			$path:=""
			$URL:="second-state/FLUX.1-dev-GGUF/ae.safetensors"
			$vae:=cs:C1710.event.huggingface.new($model; $URL; $path; "vae"; "ae.safetensors")
			
			//clip_l [246 MB]
			$model:=$homeFolder.file("second-state/FLUX.1-dev-GGUF/clip_l.safetensors")
			$path:=""
			$URL:="second-state/FLUX.1-dev-GGUF/clip_l.safetensors"
			$clip_l:=cs:C1710.event.huggingface.new($model; $URL; $path; "clip_l"; "clip_l.safetensors")
			
			//t5xxl [2.75 GB]
			$model:=$homeFolder.file("second-state/FLUX.1-dev-GGUF/t5xxl-Q4_0.gguf")
			$path:=""
			$URL:="second-state/FLUX.1-dev-GGUF/t5xxl-Q4_0.gguf"
			$t5xxl:=cs:C1710.event.huggingface.new($model; $URL; $path; "t5xxl"; "t5xxl-Q4_0.gguf")
			
			$model:=$homeFolder.file("leejet/FLUX.1-schnell-gguf/flux1-schnell-q4_k.gguf")
			$path:=""
			$URL:="leejet/FLUX.1-schnell-gguf/flux1-schnell-q4_k.gguf"
			$image:=cs:C1710.event.huggingface.new($model; $URL; $path; "diffusion"; "flux1-schnell-q4_k.gguf")
			
			$options:={listen_ip: "0.0.0.0"; cfg_scale: "1.0"; sampling_method: "euler"; steps: 4; vae_tiling: True:C214}
			$huggingfaces:=cs:C1710.event.huggingfaces.new([$vae; $clip_l; $t5xxl; $image])
			
		: (False:C215)
			
			$model:=$homeFolder.file("gpustack/stable-diffusion-xl-1.0-turbo/stable-diffusion-xl-1.0-turbo-Q4_0.gguf")
			$path:=""
			$URL:="gpustack/stable-diffusion-xl-1.0-turbo-GGUF/stable-diffusion-xl-1.0-turbo-Q4_0.gguf"
			$image:=cs:C1710.event.huggingface.new($model; $URL; $path; "image"; "stable-diffusion-xl-1.0-turbo-Q4_0.gguf")
			
			$options:={listen_ip: "0.0.0.0"; cfg_scale: "1.0"}
			$huggingfaces:=cs:C1710.event.huggingfaces.new([$image])
			
		: (True:C214)
			
			$model:=$homeFolder.file("gpustack/stable-diffusion-v2-1-turbo-GGUF/stable-diffusion-v2-1-turbo-FP16.gguf")
			$path:=""
			$URL:="gpustack/stable-diffusion-v2-1-turbo-GGUF/stable-diffusion-v2-1-turbo-FP16.gguf"
			$image:=cs:C1710.event.huggingface.new($model; $URL; $path; "image"; "stable-diffusion-v2-1-turbo-FP16.gguf")
			
			$options:={listen_ip: "0.0.0.0"; cfg_scale: "1.0"}
			$huggingfaces:=cs:C1710.event.huggingfaces.new([$image])
			
		: (False:C215)
			
			//vae [335 MB]
			$model:=$homeFolder.file("second-state/FLUX.1-dev-GGUF/ae.safetensors")
			$path:=""
			$URL:="second-state/FLUX.1-dev-GGUF/ae.safetensors"
			$vae:=cs:C1710.event.huggingface.new($model; $URL; $path; "vae"; "ae.safetensors")
			
			//clip_l [246 MB]
			$model:=$homeFolder.file("second-state/FLUX.1-dev-GGUF/clip_l.safetensors")
			$path:=""
			$URL:="second-state/FLUX.1-dev-GGUF/clip_l.safetensors"
			$clip_l:=cs:C1710.event.huggingface.new($model; $URL; $path; "clip_l"; "clip_l.safetensors")
			
			//t5xxl [2.75 GB]
			$model:=$homeFolder.file("second-state/FLUX.1-dev-GGUF/t5xxl-Q4_0.gguf")
			$path:=""
			$URL:="second-state/FLUX.1-dev-GGUF/t5xxl-Q4_0.gguf"
			$t5xxl:=cs:C1710.event.huggingface.new($model; $URL; $path; "t5xxl"; "t5xxl-Q4_0.gguf")
			
			$model:=$homeFolder.file("silveroxides/Chroma-GGUF/chroma-unlocked-v50/chroma-unlocked-v50-Q4_0.gguf")
			$path:=""
			$URL:="silveroxides/Chroma-GGUF/chroma-unlocked-v50/chroma-unlocked-v50-Q4_0.gguf"
			$image:=cs:C1710.event.huggingface.new($model; $URL; $path; "diffusion"; "chroma-unlocked-v50/chroma-unlocked-v50-Q4_0.gguf")
			
			$options:={listen_ip: "0.0.0.0"; cfg_scale: "1.0"; sampling_method: "euler"; steps: 12}
			$huggingfaces:=cs:C1710.event.huggingfaces.new([$vae; $clip_l; $t5xxl; $image])
			
		: (False:C215)
			
			//ovis.llm [5.14 GB]
			$model:=$homeFolder.file("Ovis-Image/ovis_2.5.safetensors")
			$path:=""
			$URL:="Comfy-Org/Ovis-Image/ovis_2.5.safetensors"
			$llm:=cs:C1710.event.huggingface.new($model; $URL; $path; "llm"; "split_files/text_encoders/ovis_2.5.safetensors")
			
			//ovis [4.2 GB]
			$model:=$homeFolder.file("leejet/Ovis-Image-7B-GGUF/ovis_image-Q4_0.gguf")
			$path:=""
			$URL:="leejet/Ovis-Image-7B-GGUF/ovis_image-Q4_0.gguf"
			$image:=cs:C1710.event.huggingface.new($model; $URL; $path; "diffusion"; "ovis_image-Q4_0.gguf")
			
			$options:={listen_ip: "0.0.0.0"; cfg_scale: "1.0"; sampling_method: "euler"; steps: 8}
			$huggingfaces:=cs:C1710.event.huggingfaces.new([$vae; $llm; $image])
			
		: (False:C215)
			
			//vae [335 MB]
			$model:=$homeFolder.file("second-state/FLUX.1-dev-GGUF/ae.safetensors")
			$path:=""
			$URL:="second-state/FLUX.1-dev-GGUF/ae.safetensors"
			$vae:=cs:C1710.event.huggingface.new($model; $URL; $path; "vae"; "ae.safetensors")
			
			//z-image.llm [2.5 GB]
			$model:=$homeFolder.file("llmware/qwen3-4b-instruct-gguf/Qwen3-4B-Q4_K_M.gguf")
			$path:=""
			$URL:="llmware/qwen3-4b-instruct-gguf/Qwen3-4B-Q4_K_M.gguf"
			$llm:=cs:C1710.event.huggingface.new($model; $URL; $path; "llm"; "Qwen3-4B-Q4_K_M.gguf")
			
			//z-image [3.68 GB]
			$model:=$homeFolder.file("leejet/Z-Image-Turbo-GGUF/z_image_turbo-Q4_0.gguf")
			$path:=""
			$URL:="leejet/Z-Image-Turbo-GGUF/z_image_turbo-Q4_0.gguf"
			$image:=cs:C1710.event.huggingface.new($model; $URL; $path; "diffusion"; "z_image_turbo-Q4_0.gguf")
			
			$options:={listen_ip: "0.0.0.0"; cfg_scale: "1.0"; sampling_method: "euler"; steps: 8}
			$huggingfaces:=cs:C1710.event.huggingfaces.new([$vae; $llm; $image])
			
	End case 
	
	$SD:=cs:C1710.SD.new($port; $huggingfaces; $homeFolder; $options; $event)
	
End if 