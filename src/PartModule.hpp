#include <godot_cpp/Godot.hpp>
#include <godot_cpp/Node.hpp>

#pragma once

namespace OSP {
    class Part;

    class PartModule : public godot::Node {
        GODOT_CLASS(PartModule, godot::Node)
    public:
        PartModule();
        Part *part;
        char *type;
    };
}
