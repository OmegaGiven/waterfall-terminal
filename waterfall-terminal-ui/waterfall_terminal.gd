extends Node2D

@onready var in_out_container = $VBoxContainer
@onready var shell = Terminal.new()
var Bubble = preload("res://Bubble.tscn")

func _ready():
	shell.start_shell()
	spawn_bubble()
	return

# 1. <TODO: LOAD HISTORY>
func load_history():	
	return

# 2. Open a new Bubble
func spawn_bubble():
	var bubble = Bubble.instantiate()
	bubble.shell = self.shell
	add_child(bubble)
	return
