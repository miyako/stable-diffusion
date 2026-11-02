//%attributes = {}
#DECLARE($status : Object; $options : Object)

If ($status.success)
	
Else 
	
	var $error : cs:C1710.event.error
	var $message : Text
	$message:=$status.message
	If ($message="")
		$message:="Failed to download model"
	End if
	$error:=cs:C1710.event.error.new(2; $message; This:C1470.that.models())
	
	If (This:C1470.event#Null:C1517) && (OB Instance of:C1731(This:C1470.event; cs:C1710.event.event))
		var $report : Object
		$report:=sdDownloadIO(Formula:C1597(This:C1470.event.onError.call(This:C1470.that; $options; $error)); This:C1470)
		If (Not:C34($report.success))
			LOG EVENT:C667(Into 4D debug message:K38:5; "Model error callback failed: "+$message)
		End if
	End if 
	
	var $workers : cs:C1710.workers.workers
	$workers:=cs:C1710.workers.workers.new()
	$workers.remove($options.port)
	
End if 