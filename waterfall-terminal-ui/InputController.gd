extends Control

func _input(event: InputEvent) -> void:
	if event is InputEventKey and event.pressed:
		var focus_node = FocusManager.current_node
		
		if event.keycode == KEY_ENTER:
			print("Enter")
			if focus_node and focus_node.has_method("submit"):
				print("executing submit for:", focus_node)
				focus_node.submit()
