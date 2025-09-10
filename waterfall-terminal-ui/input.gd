extends LineEdit

func submit():
	if get_parent().shell:
		var result = get_parent().shell.send_command(self.text)
		var output = clean_output(result["output"])
		print(result)
		if result["success"]:
			get_parent().update_output(output)
		else:
			get_parent().update_output("Error: " + output)
		self.editable = !editable


func clean_output(output: String) -> String:
	var raw_lines := output.replace("\r\n", "\n").split("\n")
	if raw_lines.size() >= 3:
		var trimmed_lines := raw_lines.slice(1, raw_lines.size() - 2)
		return "\r\n".join(trimmed_lines)
	return output
