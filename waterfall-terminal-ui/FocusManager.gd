extends Node

var focusables = []
var current_index := -1
var current_node

# This script is to process hotkeys to put in focus the objects we want to action on.

func _ready():
	set_process_input(true)

func register_focusable(node: Node):
#	upon creation of a new object make sure to call this function in that object to add it to the focusable list
	if node not in focusables:
		focusables.append(node)
		if node is Control:
			node.connect("focus_entered", Callable(func(): _on_node_focus_entered(node)))

func unregister_focusable(node: Node):
#	if deletion is ever needed make sure to call this to delete from focusables else hotkeys will get janky
	focusables.erase(node)

func _input(event):
	if event is InputEventKey and event.pressed:
		if event.keycode == KEY_TAB:
			if event.shift_pressed:
				cycle_focus(true)
			else:
				cycle_focus()

func _on_node_focus_entered(node: Node):
	var index = focusables.find(node)
	if index != -1:
		current_index = index
		current_node = node

func cycle_focus(backward := false):
#	this manages tabbing forward and back of focable nodes.
	if focusables.size() == 0:
		return

	if backward:
		current_index = (current_index - 1 + focusables.size()) % focusables.size()
	else:
		current_index = (current_index + 1) % focusables.size()

	var node = focusables[current_index]

	if node is Control:
		node.grab_focus()
	elif node.has_method("on_focus"):
		node.call("on_focus")
		
	current_node = node

# Will need cursor location script to understand highlighting in output boxes and input boxes.
