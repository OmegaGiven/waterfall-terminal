extends LineEdit

var term = Terminal.new()
@onready var ouput_module = self.get_parent().get_parent().get_child(0)

func _ready(): 
	FocusManager.register_focusable(self)

func submit():
	var result = term.run_command(self.text)
	print(result)
#	input history keeping thing here
	self.clear()
	ouput_module.text = result
