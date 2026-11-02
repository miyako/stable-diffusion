property that : cs:C1710._models
property entry; range; headers : Object
property file; candidate : 4D:C1709.File
property event : cs:C1710.event.event
property request : 4D:C1709.HTTPRequest
property _fileHandle : 4D:C1709.FileHandle
property URL; method; dataType : Text
property automaticRedirections; returnResponseBody; decodeData; done; accepted : Boolean
property timeout : Real
property redirects; generation : Integer

Class constructor($owner : cs:C1710._models; $entry : Object)
	This:C1470.that:=$owner
	This:C1470.entry:=$entry
	This:C1470.file:=File:C1566($entry.destination; fk platform path:K87:2)
	This:C1470.event:=$owner.event
	This:C1470.URL:=$entry.url
	This:C1470.method:="GET"
	This:C1470.dataType:="blob"
	This:C1470.automaticRedirections:=False:C215
	This:C1470.returnResponseBody:=False:C215
	This:C1470.decodeData:=False:C215
	This:C1470.timeout:=1800
	This:C1470.headers:={Accept: "application/octet-stream"}
	This:C1470.headers["Accept-Encoding"]:="identity"
	This:C1470.range:={length: $entry.size; start: 0; end: 0; ranges: False:C215}

Function head()
	// Retain the shared downloader entry-point name, but do not require HEAD/range support.
	var $io : Object
	$io:=sdDownloadIO(Formula:C1597(This:C1470.file.parent.create()); This:C1470)
	If (Not:C34($io.success)) || (Not:C34(This:C1470.file.parent.exists))
		This:C1470.fail("Cannot create model cache directory")
		return
	End if
	This:C1470.candidate:=This:C1470.file.parent.file(".sd-part-"+Generate UUID:C1066)
	$io:=sdDownloadIO(Formula:C1597(This:C1470.candidate.create()); This:C1470)
	If (Not:C34($io.success)) || ($io.value#True:C214)
		This:C1470.fail("Cannot reserve a temporary model download")
		return
	End if
	$io:=sdDownloadIO(Formula:C1597(This:C1470.candidate.open("write")); This:C1470)
	This:C1470._fileHandle:=$io.value
	If (Not:C34($io.success)) || (This:C1470._fileHandle=Null:C1517)
		This:C1470.fail("Cannot open a temporary model download")
		return
	End if
	This:C1470.send()

Function send()
	This:C1470.accepted:=False:C215
	This:C1470.generation+=1
	OB REMOVE:C1226(This:C1470.headers; "Authorization")
	If (Position:C15("https://huggingface.co/"; This:C1470.URL)=1)
		If (Value type:C1509(This:C1470.that.options.HF_TOKEN)=Is text:K8:3) && (This:C1470.that.options.HF_TOKEN#"")
			This:C1470.headers.Authorization:="Bearer "+This:C1470.that.options.HF_TOKEN
		End if
	End if
	var $io; $options : Object
	$options:={owner: This:C1470; generation: This:C1470.generation; method: This:C1470.method; headers: This:C1470.headers; \
	dataType: This:C1470.dataType; automaticRedirections: This:C1470.automaticRedirections; \
	returnResponseBody: This:C1470.returnResponseBody; decodeData: This:C1470.decodeData; timeout: This:C1470.timeout}
	$options.onHeaders:=Formula:C1597(This:C1470.owner.onHeaders($1; $2))
	$options.onData:=Formula:C1597(This:C1470.owner.onData($1; $2))
	$options.onResponse:=Formula:C1597(This:C1470.owner.onResponse($1; $2))
	$options.onError:=Formula:C1597(This:C1470.owner.onError($1; $2))
	// Each options object keeps its generation when a redirect starts a new request.
	$options.onTerminate:=Formula:C1597(This:C1470.owner.onTerminate($1; $2; This:C1470.generation))
	$io:=sdDownloadIO(Formula:C1597(4D:C1709.HTTPRequest.new(This:C1470.URL; $options)); This:C1470)
	This:C1470.request:=$io.value
	If (Not:C34($io.success)) || (This:C1470.request=Null:C1517)
		This:C1470.fail("Cannot start HTTP download")
	End if

Function onHeaders($request : 4D:C1709.HTTPRequest; $event : Object)
	If (This:C1470.done) || ($request.response.status#200)
		return
	End if
	var $length; $encoding : Variant
	$length:=$request.response.headers["content-length"]
	$encoding:=$request.response.headers["content-encoding"]
	If ($encoding#Null:C1517) && ($encoding#"identity")
		This:C1470.fail("Unexpected Content-Encoding in model response")
		$request.terminate()
		return
	End if
	If ($length#Null:C1517)
		If (Value type:C1509($length)#Is text:K8:3)
			This:C1470.fail("Invalid Content-Length in model response")
			$request.terminate()
			return
		End if
		If (Not:C34(Match regex:C1019("^[0-9]+$"; $length))) || (Num:C11($length)#This:C1470.entry.size)
			This:C1470.fail("Model response length differs from authoritative metadata")
			$request.terminate()
			return
		End if
	End if
	This:C1470.accepted:=True:C214

Function onData($request : 4D:C1709.HTTPRequest; $event : Object)
	If (This:C1470.done) || (Not:C34(This:C1470.accepted)) || ($event.data=Null:C1517)
		return
	End if
	var $io : Object
	$io:=sdDownloadIO(Formula:C1597(This:C1470._fileHandle.writeBlob($event.data)); This:C1470)
	If (Not:C34($io.success))
		This:C1470.fail("Cannot write model download (check disk space/permissions)")
		$request.terminate()
		return
	End if
	$io:=sdDownloadIO(Formula:C1597(This:C1470._fileHandle.getSize()); This:C1470)
	If (Not:C34($io.success))
		This:C1470.fail("Cannot measure temporary model download")
		$request.terminate()
		return
	End if
	This:C1470.range.end:=$io.value
	If (This:C1470.range.end>This:C1470.entry.size)
		This:C1470.fail("Model response exceeds authoritative size")
		$request.terminate()
		return
	End if
	$io:=sdDownloadIO(Formula:C1597(This:C1470.event.onData.call(This:C1470; $request; $event)); This:C1470)
	If (Not:C34($io.success))
		This:C1470.fail("Model progress callback failed")
		$request.terminate()
	End if

Function onResponse($request : 4D:C1709.HTTPRequest; $event : Object)
	If (This:C1470.done)
		return
	End if
	var $status : Integer
	$status:=$request.response.status
	If ([301; 302; 303; 307; 308].includes($status))
		This:C1470.redirects+=1
		If (This:C1470.redirects>5)
			This:C1470.fail("Too many model download redirects")
			return
		End if
		var $redirect : Object
		$redirect:=This:C1470.that.cache.call({operation: "redirect"; base: $request.url; location: $request.response.headers.location})
		If (Not:C34($redirect.success))
			This:C1470.fail($redirect.message)
			return
		End if
		This:C1470.URL:=$redirect.url
		This:C1470.send()
		return
	End if
	If ($status#200)
		This:C1470.fail(This:C1470.that.httpError($status; $request.response.headers))
		return
	End if
	If (Not:C34(This:C1470.accepted))
		This:C1470.fail("Model response headers were not accepted")
		return
	End if
	var $result; $io : Object
	$io:=sdDownloadIO(Formula:C1597(This:C1470.closeFile()); This:C1470)
	If (Not:C34($io.success))
		This:C1470.fail("Cannot close temporary model download")
		return
	End if
	$result:=This:C1470.that.cache.call({operation: "commit"; file: This:C1470.entry; candidate: This:C1470.candidate.platformPath})
	If (Not:C34($result.success))
		This:C1470.fail($result.message)
		return
	End if
	This:C1470.done:=True:C214
	$io:=sdDownloadIO(Formula:C1597(This:C1470.event.onResponse.call(This:C1470; $request; $event)); This:C1470)
	If (Not:C34($io.success))
		This:C1470.that.fail("Model response callback failed"; "callback")
		return
	End if
	This:C1470.that.onDownload(This:C1470.entry.id)

Function onError($request : 4D:C1709.HTTPRequest; $event : Object)
	If ($request.response#Null:C1517) && ($request.response.status#200)
		This:C1470.fail(This:C1470.that.httpError($request.response.status; $request.response.headers))
	Else
		This:C1470.fail("HTTP transport failed (connection/TLS/timeout); retry the download")
	End if

Function onTerminate($request : 4D:C1709.HTTPRequest; $event : Object; $generation : Integer)
	If (Not:C34(This:C1470.done)) && ($generation=This:C1470.generation)
		This:C1470.fail("HTTP request terminated before verified completion")
	End if

Function fail($message : Text)
	If (This:C1470.done)
		return
	End if
	This:C1470.done:=True:C214
	var $io : Object
	$io:=sdDownloadIO(Formula:C1597(This:C1470.closeFile()); This:C1470)
	If (Not:C34($io.success))
		LOG EVENT:C667(Into 4D debug message:K38:5; "Could not close temporary model download")
	End if
	If (This:C1470.candidate#Null:C1517)
		$io:=sdDownloadIO(Formula:C1597(This:C1470.candidate.delete()); This:C1470)
		If (Not:C34($io.success))
			LOG EVENT:C667(Into 4D debug message:K38:5; "Could not remove temporary model file: "+This:C1470.candidate.platformPath)
		End if
	End if
	This:C1470.that.fail(This:C1470.entry.path+": "+$message; "download")

Function closeFile()
	This:C1470._fileHandle:=Null:C1517
