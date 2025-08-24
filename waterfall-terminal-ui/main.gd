extends Node

func _ready(): 
	var term = Terminal.new() 
	term.start("/bin/bash") 
	term.send_input("ls -l\n") 
	await get_tree().create_timer(0.1).timeout 
	print(term.read_output())
