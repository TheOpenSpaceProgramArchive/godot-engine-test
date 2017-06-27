#include <godot_cpp/Godot.hpp>
#include <godot_cpp/RigidBody.hpp>
#include <vector>

#pragma once

namespace OSP {
    class PartModule;

    class Part : public godot::RigidBody {
        GODOT_CLASS(Part, godot::RigidBody)
        std::vector<PartModule *> *modules;
    public:
        float mass;
        void addModule(PartModule *module);
        void removeModule(PartModule *module);
        std::vector<PartModule *>::iterator getModulesIterator();
        std::vector<PartModule *> *getModulesOfType(char *type);
    };
}
