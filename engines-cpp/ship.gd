extends RigidBody

func _ready():
	set_fixed_process(true)

func _fixed_process(dt):
	print(get_linear_velocity().y, get_translation().y)
