property image_generation_model : 4D:C1709.Folder
property diffusion_model : 4D:C1709.Folder

Class extends _models

Class constructor($port : Integer; $huggingfaces : cs:C1710.event.huggingfaces; $options : Object; $formula : 4D:C1709.Function; $event : cs:C1710.event.event)
	
	Super:C1705($port; $huggingfaces; $options; $formula; $event)
	
	If (Not:C34(This:C1470.offline))
		This:C1470.download()
	End if 
	
Function models() : cs:C1710.event.models
	
	var $models : Collection
	$models:=[]
	
	var $_model : Text
	For each ($_model; This:C1470._models)
		$models.push(cs:C1710.event.model.new($_model; True:C214))
	End for each 
	
	return cs:C1710.event.models.new($models)
	
Function onDownload($oid : Text)
	
	var $downloaded : cs:C1710.event.huggingface
	$downloaded:=This:C1470.files.query("oid == :1"; $oid).first()
	
	If ($downloaded#Null:C1517)
		var $model : Object
		$model:=OB Instance of:C1731($downloaded.folder; 4D:C1709.Folder)\
			 ? $downloaded.folder.folder($downloaded.path).parent : $downloaded.folder
		
		Case of 
			: ($downloaded.domain="image")
				This:C1470.options.image_generation_model:=$model
			: ($downloaded.domain="diffusion")
				This:C1470.options.diffusion_model:=$model
			: (["vae"; "clip_l"; "t5xxl"; "llm"]).includes($downloaded.domain)
				This:C1470.options[$downloaded.domain]:=$model
		End case 
	End if 
	
	Super:C1706.onDownload($oid)
	
Function start()
	
	var $SD : cs:C1710.workers.worker
	$SD:=cs:C1710.workers.worker.new(cs:C1710._server)
	$SD.start(This:C1470.options.port; This:C1470.options)
	
	If (This:C1470.event#Null:C1517) && (OB Instance of:C1731(This:C1470.event; cs:C1710.event.event))
		This:C1470.event.onSuccess.call(This:C1470; This:C1470.options; This:C1470.models())
	End if 