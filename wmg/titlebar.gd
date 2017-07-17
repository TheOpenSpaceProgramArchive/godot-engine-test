extends Control

var dragging = false

func _ready():
	set_process_input(true)

func _input_event(ev):
	if ev.type == InputEvent.MOUSE_BUTTON and ev.button_index == BUTTON_LEFT:
		dragging = ev.pressed

func _input(ev):
	if ev.type == InputEvent.MOUSE_MOTION and dragging:
		get_node("..").set_pos(get_node("..").get_pos() + ev.relative_pos)