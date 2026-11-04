Class extends _SD

Class constructor($controller : 4D:C1709.Class)
	
	Super:C1705("sd-server"; $controller)
	
Function start($option : Object) : 4D:C1709.SystemWorker
	
	This:C1470.bind($option; ["onTerminate"])
	This:C1470.onData:=$option.onStdOut
	This:C1470.onDataError:=$option.onStdErr
	
	var $command : Text
	$command:=This:C1470.escape(This:C1470.executablePath)
	
	If (Value type:C1509($option.image_generation_model)=Is object:K8:27)\
		 && (OB Instance of:C1731($option.image_generation_model; 4D:C1709.File))\
		 && ($option.image_generation_model.exists)
		$command+=" --model "
		$command+=This:C1470.escape(This:C1470.expand($option.image_generation_model).platformPath)
		$command+=" "
	End if 
	
	If (Value type:C1509($option.diffusion_model)=Is object:K8:27)\
		 && (OB Instance of:C1731($option.diffusion_model; 4D:C1709.File))\
		 && ($option.diffusion_model.exists)
		$command+=" --diffusion-model "
		$command+=This:C1470.escape(This:C1470.expand($option.diffusion_model).platformPath)
		$command+=" "
	End if 
	
	$command+=" --listen-port "+String:C10($option.port)+" "
	
	var $arg : Object
	var $valueType : Integer
	var $key : Text
	
	For each ($arg; OB Entries:C1720($option))
		Case of 
			: (["HOME"; "HF_TOKEN"; "version"; "help"; "port"; "diffusion_model"; "image_generation_model"].includes($arg.key))
				continue
		End case 
		$valueType:=Value type:C1509($arg.value)
		$key:=Replace string:C233($arg.key; "_"; "-"; *)
		If (["clip_l"; "clip_g"; "llm_vision"].includes($arg.key))
			$key:=$arg.key
		End if
		Case of 
			: ($valueType=Is real:K8:4) || ($valueType=Is integer:K8:5)
				$command+=(" --"+$key+" "+_argNumber($arg.value)+" ")
			: ($valueType=Is text:K8:3)
				$command+=(" --"+$key+" "+This:C1470.escape($arg.value)+" ")
			: ($valueType=Is boolean:K8:9) && ($arg.value)
				$command+=(" --"+$key+" ")
			: ($valueType=Is object:K8:27) && (OB Instance of:C1731($arg.value; 4D:C1709.File))
				$command+=(" --"+$key+" "+This:C1470.escape(This:C1470.expand($arg.value).platformPath))
			Else 
				//
		End case 
	End for each 
	
	If (OB Instance of:C1731($option.HOME; 4D:C1709.Folder)) && ($option.HOME.exists)
		This:C1470.controller.currentDirectory:=$option.HOME
	End if
	
	//SET TEXT TO PASTEBOARD($command)
	
	return This:C1470.controller.execute($command).worker