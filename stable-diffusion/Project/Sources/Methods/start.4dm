//%attributes = {"invisible":true,"preemptive":"capable"}
#DECLARE($options : Object; $formula : 4D:C1709.Function)

$options.options:=$options.options#Null:C1517 ? $options.options : {}
$options.options.HOME:=$options.HOME

var $model : cs:C1710._Model
$model:=cs:C1710._Model.new($options.port; $options.huggingfaces; $options.options; $formula; $options.event)
