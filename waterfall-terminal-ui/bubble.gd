extends Node2D

var shell
@onready var output_module = $Output
@onready var input_module = $Input
@onready var mm_toggle = $MMToggle

var bubble_output = ""

func _ready(): 
	FocusManager.register_focusable(self.output_module)
	FocusManager.register_focusable(self.input_module)
	output_module.visible = false
	mm_toggle.visible = false

func update_output(new_value: String):
	bubble_output = new_value
	output_module.text = bubble_output
	output_module.visible = !output_module.visible
	mm_toggle.visible = !mm_toggle.visible
	FocusManager.register_focusable(self.mm_toggle)

func _on_mm_toggle_toggled(toggled_on: bool) -> void:
	output_module.visible = !output_module.visible
