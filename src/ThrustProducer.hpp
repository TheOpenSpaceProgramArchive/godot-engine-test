#include <godot_cpp/Godot.hpp>
#include <godot_cpp/RigidBody.hpp>
#include <godot_cpp/core/Vector3.hpp>

namespace OSP {
    class ThrustProducer {
    public:
        virtual godot::Vector3 getThrustVector();
        void applyThrust(godot::RigidBody *target, godot::Vector3 thrustPos);
    };
}
