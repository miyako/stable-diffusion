property huggingfaces : cs:C1710.event.huggingfaces
property files; _models; plans : Collection
property options : Object
property event : cs:C1710.event.event
property _onResponse : 4D:C1709.Function
property offline; failed; completed; advancing : Boolean
property cache : cs:C1710._DownloadCache
property active : cs:C1710._Download

Class constructor($port : Integer; $huggingfaces : cs:C1710.event.huggingfaces; $options : Object; $formula : 4D:C1709.Function; $event : cs:C1710.event.event)
	This:C1470.huggingfaces:=$huggingfaces
	If (Not:C34(OB Instance of:C1731($event; cs:C1710.event.event)))
		$event:=cs:C1710.event.event.new()
	End if
	This:C1470.event:=$event
	This:C1470._onResponse:=$formula
	This:C1470.options:=$options#Null:C1517 ? $options : {}
	This:C1470.options.onTerminate:=$event.onTerminate
	This:C1470.options.onStdErr:=$event.onStdErr
	This:C1470.options.onStdOut:=$event.onStdOut
	This:C1470.options.port:=$port
	This:C1470.files:=[]
	This:C1470.plans:=[]
	This:C1470._models:=[]
	This:C1470.cache:=cs:C1710._DownloadCache.new()
	This:C1470.offline:=False:C215
	This:C1470.failed:=False:C215
	This:C1470.completed:=False:C215

	If ($huggingfaces=Null:C1517) || ($huggingfaces.huggingfaces.length=0)
		This:C1470.fail("No model files were requested"; "metadata")
		return
	End if
	var $huggingface : cs:C1710.event.huggingface
	For each ($huggingface; $huggingfaces.huggingfaces)
		If (This:C1470.failed)
			break
		End if
		This:C1470.prepare($huggingface)
	End for each

Function prepare($source : cs:C1710.event.huggingface)
	var $descriptor; $result; $io; $requestOptions : Object
	var $request : 4D:C1709.HTTPRequest
	var $paths : Collection
	var $isFile : Boolean
	$isFile:=OB Instance of:C1731($source.folder; 4D:C1709.File)
	If (Not:C34($isFile)) && (Not:C34(OB Instance of:C1731($source.folder; 4D:C1709.Folder)))
		This:C1470.fail("A model destination must be a 4D.File or 4D.Folder"; "metadata")
		return
	End if
	If (Not:C34(["image"; "diffusion"; "vae"; "clip_l"; "t5xxl"; "llm"].includes($source.domain)))
		This:C1470.fail("Unsupported model domain: "+$source.domain; "metadata")
		return
	End if
	$paths:=$isFile ? [$source.name] : $source.paths
	$descriptor:={repo: $source.URL; destination: $source.folder.platformPath; is_file: $isFile; paths: $paths; domain: $source.domain}
	// Validate the descriptor before constructing an authenticated metadata URL.
	$result:=This:C1470.cache.call({operation: "descriptor"; descriptor: $descriptor})
	If (Not:C34($result.success))
		This:C1470.fail($result.message; "metadata")
		return
	End if
	$descriptor:=$result.descriptor
	$requestOptions:={dataType: "text"; timeout: 60; automaticRedirections: False:C215; headers: {Accept: "application/json"}}
	If (Value type:C1509(This:C1470.options.HF_TOKEN)=Is text:K8:3) && (This:C1470.options.HF_TOKEN#"")
		$requestOptions.headers.Authorization:="Bearer "+This:C1470.options.HF_TOKEN
	End if
	$io:=sdDownloadIO(Formula:C1597(4D:C1709.HTTPRequest.new(This:C1470.metadataURL($descriptor.repo); $requestOptions)); This:C1470)
	$request:=$io.value
	If ($io.success) && ($request#Null:C1517)
		$io:=sdDownloadIO(Formula:C1597($request.wait()))
	End if
	var $transportFailed : Boolean
	$transportFailed:=Not:C34($io.success) || ($request=Null:C1517)
	If ($request#Null:C1517)
		$transportFailed:=$request.response=Null:C1517
	End if
	If ($transportFailed)
		$result:=This:C1470.cache.call({operation: "load-plan"; descriptor: $descriptor})
		If (Not:C34($result.success))
			This:C1470.fail("Metadata transport failure for "+$descriptor.repo+". "+$result.message; "offline")
			return
		End if
		This:C1470.offline:=True:C214
	Else
		If ($request.response.status#200)
			This:C1470.fail(This:C1470.httpError($request.response.status; $request.response.headers)+" Repository: "+$descriptor.repo; "metadata")
			return
		End if
		If (Not:C34($io.success))
			This:C1470.fail("Invalid or interrupted metadata response for "+$descriptor.repo; "metadata")
			return
		End if
		If ($request.errors#Null:C1517) && ($request.errors.length#0)
			This:C1470.fail("Metadata transfer/JSON decoding failed for "+$descriptor.repo; "metadata")
			return
		End if
		$result:=This:C1470.cache.call({operation: "plan"; descriptor: $descriptor; metadata: $request.response.body})
		If (Not:C34($result.success))
			This:C1470.fail($descriptor.repo+": "+$result.message; "metadata")
			return
		End if
	End if
	var $primary : Text
	If ($isFile)
		$primary:=$result.plan.files.first().path
	Else
		$primary:=$source.name
		If ($primary="") && ($source.paths.length#0)
			$primary:=$source.paths.first()
		End if
		If ($primary="")
			var $weights : Collection
			$weights:=[]
			var $candidate : Object
			For each ($candidate; $result.plan.files)
				If (Match regex:C1019("(?i)\\.(gguf|safetensors|ckpt|bin|pt)$"; $candidate.path))
					$weights.push($candidate.path)
				End if
			End for each
			If ($weights.length=1)
				$primary:=$weights.first()
			End if
		End if
	End if
	If ($primary="") || ($result.plan.files.query("path == :1"; $primary).length#1)
		This:C1470.fail("Select one primary model filename with name/paths or use a 4D.File destination"; "metadata")
		return
	End if
	If ($result.plan.files.query("path == :1"; $primary).first().size=0)
		This:C1470.fail("The primary model file is empty: "+$primary; "metadata")
		return
	End if
	var $file; $existing : Object
	For each ($file; $result.plan.files)
		$existing:=This:C1470.files.query("destination == :1"; $file.destination).first()
		If ($existing#Null:C1517)
			This:C1470.fail("Conflicting model destinations: "+$file.path; "metadata")
			return
		End if
		$file.id:=String:C10(This:C1470.files.length+1)
		var $queued : Object
		$queued:=OB Copy:C1225($file)
		$queued.offline:=$transportFailed
		$queued.bind:=$file.path=$primary
		This:C1470.files.push($queued)
		OB REMOVE:C1226($file; "id")
	End for each
	This:C1470.plans.push({plan: $result.plan; offline: $transportFailed})
	This:C1470._models.push($descriptor.repo)

Function metadataURL($repo : Text) : Text
	return "https://huggingface.co/api/models/"+$repo+"/revision/main?blobs=true"

Function download()
	If (This:C1470.failed) || (This:C1470.completed) || (This:C1470.active#Null:C1517) || (This:C1470.advancing)
		return
	End if
	This:C1470.advancing:=True:C214
	var $file; $result : Object
	While (This:C1470.files.length#0) && (Not:C34(This:C1470.failed))
		$file:=This:C1470.files.first()
		$result:=This:C1470.cache.call({operation: "verify"; file: $file})
		If (This:C1470.failed)
			break
		End if
		If (Not:C34($result.success))
			This:C1470.fail($result.message; "cache")
			break
		End if
		If ($result.valid)
			This:C1470.onDownload($file.id)
		Else
			If ($file.offline)
				This:C1470.fail("Offline cache changed after verification: "+$file.path; "offline")
			Else
				This:C1470.active:=cs:C1710._Download.new(This:C1470; $file)
				This:C1470.active.head()
			End if
			break
		End if
	End while
	This:C1470.advancing:=False:C215
	If (This:C1470.files.length=0) && (Not:C34(This:C1470.failed))
		This:C1470.finish()
	End if

Function onDownload($id : Text)
	If (This:C1470.failed) || (This:C1470.completed)
		return
	End if
	If (This:C1470.files.length=0) || (This:C1470.files.first().id#$id)
		This:C1470.fail("Unexpected or duplicate download completion"; "completion")
		return
	End if
	This:C1470.files.shift()
	This:C1470.active:=Null:C1517
	This:C1470.download()

Function finish()
	If (This:C1470.failed) || (This:C1470.completed)
		return
	End if
	If (This:C1470.plans.length=0)
		This:C1470.fail("Model metadata produced an empty download queue"; "completion")
		return
	End if
	var $plan; $result : Object
	For each ($plan; This:C1470.plans)
		If ($plan.offline)
			continue
		End if
		$result:=This:C1470.cache.call({operation: "save-plan"; plan: $plan.plan})
		If (This:C1470.failed)
			return
		End if
		If (Not:C34($result.success))
			This:C1470.fail($result.message; "receipt")
			return
		End if
	End for each
	This:C1470.completed:=True:C214
	This:C1470.start()

Function fail($message : Text; $stage : Text)
	If (This:C1470.failed) || (This:C1470.completed)
		return
	End if
	This:C1470.failed:=True:C214
	LOG EVENT:C667(Into 4D debug message:K38:5; "Stable Diffusion download ["+$stage+"]: "+$message)
	var $report : Object
	If (OB Instance of:C1731(This:C1470._onResponse; 4D:C1709.Function))
		$report:=sdDownloadIO(Formula:C1597(This:C1470._onResponse.call({that: This:C1470; event: This:C1470.event}; {success: False:C215; message: $message; stage: $stage}; This:C1470.options)); This:C1470)
	Else
		$report:=sdDownloadIO(Formula:C1597(This:C1470.event.onError.call(This:C1470; This:C1470.options; cs:C1710.event.error.new(2; $message; This:C1470.models()))); This:C1470)
	End if
	If (Not:C34($report.success))
		LOG EVENT:C667(Into 4D debug message:K38:5; "Download failure callback raised an error: "+$message)
	End if

Function httpError($status : Integer; $headers : Object)->$message : Text
	$message:="HTTP "+String:C10($status)+". "
	Case of
		: ([401; 403].includes($status))
			$message+="Check HF_TOKEN and model access/license acceptance."
		: ($status=404)
			$message+="Check repository, revision and filename."
		: ($status=429)
			$message+="Rate limited; retry later."
			If ($headers#Null:C1517) && (Value type:C1509($headers["retry-after"])=Is text:K8:3)
				$message+=" Retry-After: "+$headers["retry-after"]
			End if
		: ($status>=500)
			$message+="Hugging Face or its download service is unavailable; retry later."
		Else
			$message+="Unexpected response; download was not accepted."
	End case

Function models() : cs:C1710.event.models
	return cs:C1710.event.models.new()

Function start()
	// Implemented by the concrete model class.
