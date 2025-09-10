extends TextEdit

func _ready():
	self.wrap_mode = TextEdit.LINE_WRAPPING_BOUNDARY  
	connect("text_changed", Callable(self, "_resize_to_fit"))
	
func _resize_to_fit():
	var font := get_theme_font("font")
	if font == null:
		return
	var line_height := font.get_height() + font.get_spacing(TextServer.SPACING_BOTTOM)
	var new_height := get_line_count() * line_height
	
	custom_minimum_size.y = new_height
