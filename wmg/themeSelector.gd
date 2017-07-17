extends OptionButton

var themeIds = {
    "Default": "default",
    "Blue": "blue"
}

var themes = {}

func _ready():
	add_item("Default")
	add_item("Blue")
	for t in themeIds:
		var id = themeIds[t]
		themes[id] = load("res://themes/" + id + "/" + id + ".thm")

func _onItemSelected(id):
	var theme = themes[themeIds[get_item_text(id)]]
	iterControls(get_tree().get_current_scene(), theme)

func iterControls(n, theme):
	for c in n.get_children():
		iterControls(c, theme)
		if c.is_type("Control"):
			c.set_theme(theme)