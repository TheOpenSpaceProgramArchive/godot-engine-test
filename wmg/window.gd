extends Control

func _ready():
	pass

func _notification(what):
	if what == 30:
		var stylebox = get_theme().get_stylebox("WindowDialog", "panel")