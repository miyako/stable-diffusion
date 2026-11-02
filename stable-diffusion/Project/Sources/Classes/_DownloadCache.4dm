property CLI : cs:C1710._CLI

Class constructor()
	This:C1470.CLI:=cs:C1710._CLI.new("sd-cache")

Function call($operation : Object)->$result : Object
	If (Not:C34(This:C1470.CLI.executableFile.exists))
		return {success: False:C215; message: "Missing sd-cache integrity helper; build and stage the current native resource package"}
	End if
	var $worker : 4D:C1709.SystemWorker
	var $io : Object
	$io:=sdDownloadIO(Formula:C1597(4D:C1709.SystemWorker.new(This:C1470.CLI.escape(This:C1470.CLI.executablePath); {timeout: 1800})); This:C1470)
	$worker:=$io.value
	If (Not:C34($io.success)) || ($worker=Null:C1517)
		return {success: False:C215; message: "Cannot start sd-cache integrity helper"}
	End if
	$io:=sdDownloadIO(Formula:C1597($worker.postMessage(JSON Stringify:C1217($operation))))
	If (Not:C34($io.success))
		$worker.terminate()
		return {success: False:C215; message: "Cannot send integrity request to sd-cache"}
	End if
	$io:=sdDownloadIO(Formula:C1597($worker.closeInput()))
	If (Not:C34($io.success))
		$worker.terminate()
		return {success: False:C215; message: "Cannot close sd-cache input stream"}
	End if
	$io:=sdDownloadIO(Formula:C1597($worker.wait()))
	If (Not:C34($io.success))
		$worker.terminate()
		return {success: False:C215; message: "sd-cache integrity check failed to complete"}
	End if
	If ($worker.errors#Null:C1517) && ($worker.errors.length#0)
		return {success: False:C215; message: "sd-cache system worker reported an execution error"}
	End if
	$io:=sdDownloadIO(Formula:C1597(JSON Parse:C1218($worker.response)))
	If (Not:C34($io.success)) || (Value type:C1509($io.value)#Is object:K8:27)
		return {success: False:C215; message: "Invalid or missing sd-cache response; check native package and filesystem access"}
	End if
	$result:=$io.value
	If (Value type:C1509($result.success)#Is Boolean:K8:6)
		return {success: False:C215; message: "sd-cache response has no valid completion status"}
	End if
	If (Not:C34($result.success)) && (Value type:C1509($result.message)#Is text:K8:3)
		return {success: False:C215; message: "sd-cache failed without an error message"}
	End if
	If ($worker.exitCode#0) && ($result.success=True:C214)
		$result:={success: False:C215; message: "sd-cache process did not complete successfully"}
	End if
