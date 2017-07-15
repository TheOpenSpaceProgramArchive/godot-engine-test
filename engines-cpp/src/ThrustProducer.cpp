#include "ThrustProducer.hpp"
#include <godot_cpp/Godot.hpp>
#include <godot_cpp/RigidBody.hpp>
#include <godot_cpp/core/Vector3.hpp>

using namespace godot;

namespace OSP {
    ThrustProducer::ThrustProducer() {
        
    }

    void ThrustProducer::applyThrust(RigidBody *target, Vector3 thrustPos) {
        target->apply_impulse(thrustPos, getThrustVector());
    }
}
