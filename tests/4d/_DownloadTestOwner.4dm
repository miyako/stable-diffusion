// Test-only class: install in the component source tree of a disposable test copy.
Class extends _models

property starts; failures : Integer
property failureMessage : Text

Class constructor($destination : 4D:C1709.File; $case : Text)
	var $source : cs:C1710.event.huggingface
	$source:=cs:C1710.event.huggingface.new($destination; "fixture/models"; ""; "image"; "model.bin")
	Super:C1705(8080; cs:C1710.event.huggingfaces.new([$source]); {fixture_case: $case}; Formula:C1597(This:C1470.that.recordFailure($1)); cs:C1710.event.event.new())

Function metadataURL($repo : Text) : Text
	return "http://127.0.0.1:40480/metadata/"+This:C1470.options.fixture_case

Function prepare($source : cs:C1710.event.huggingface)
	Super:C1706.prepare($source)
	var $file : Object
	For each ($file; This:C1470.files)
		$file.url:="http://127.0.0.1:40480/download/"+This:C1470.options.fixture_case
	End for each

Function recordFailure($status : Object)
	This:C1470.failures+=1
	This:C1470.failureMessage:=$status.message

Function start()
	This:C1470.starts+=1

Function run()
	This:C1470.download()
	var $deadline : Real
	$deadline:=Milliseconds+60000
	While (Not:C34(This:C1470.failed)) && (Not:C34(This:C1470.completed)) && (Milliseconds<$deadline)
		If (This:C1470.active#Null:C1517) && (This:C1470.active.request#Null:C1517)
			This:C1470.active.request.wait(1)
		Else
			IDLE:C311
		End if
	End while
	ASSERT:C1129(This:C1470.failed || This:C1470.completed; "Download queue hung")
