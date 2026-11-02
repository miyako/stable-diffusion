//%attributes = {"invisible":true,"preemptive":"capable"}
#DECLARE($operation : 4D:C1709.Function; $context : Object)->$result : Object

var SDDownloadErrors : Collection
var $previousErrors : Collection
var $previousHandler : Text
$previousErrors:=SDDownloadErrors
$previousHandler:=Method called on error
SDDownloadErrors:=[]
ON ERR CALL:C155("sdDownloadError")
$result:={success: False:C215}
$result.value:=$operation.call($context)
$result.errors:=SDDownloadErrors
$result.success:=SDDownloadErrors.length=0
ON ERR CALL:C155($previousHandler)
SDDownloadErrors:=$previousErrors
