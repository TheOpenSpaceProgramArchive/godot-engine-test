#include "Engine.hpp"
#include <godot_cpp/Godot.hpp>
#include <godot_cpp/Node.hpp>
#include <godot_cpp/RigidBody.hpp>
#include <godot_cpp/core/Vector3.hpp>
#include <stdio.h>

using namespace godot;

namespace OSP {
    Engine::Engine() {
        // isp doesn't matter yet
        // one newton of thrust
        maxThrustASL = 1;
        maxThrustVac = 1;
        ispASL = 300;
        ispVac = 300;
        // thrust goes up
        thrustDirection = Vector3(0, 1, 0);
        // jeb is too eager
        throttle = 1;
    }

    Engine::Engine(float maxThrustASL, float maxThrustVac, float ispASL, float ispVac) {
        this->maxThrustASL = maxThrustASL;
        this->maxThrustVac = maxThrustVac;
        this->ispASL = ispASL;
        this->ispVac = ispVac;
    }

    Engine::Engine(float maxThrustVac, float ispASL, float ispVac) {
        this->maxThrustASL = maxThrustVac * ispASL / ispVac;
        this->maxThrustVac = maxThrustVac;
        this->ispASL = ispASL;
        this->ispVac = ispVac;
    }

    Vector3 Engine::getThrustVector() {
        return thrustDirection.normalized() * currentThrust() * throttle;
    }

    float Engine::getAtmoPressure() {
        return 1;
    }

    float Engine::currentIsp() {
        return ispWithAtmoPressure(getAtmoPressure());
    }

    float Engine::currentThrust() {
        return thrustWithAtmoPressure(getAtmoPressure());
    }

    float Engine::ispWithAtmoPressure(float pressure) {
        return (1 - pressure) * (ispVac - ispASL) + ispASL;
    }

    float Engine::thrustWithAtmoPressure(float pressure) {
        return (1 - pressure) * (ispVac - ispASL) + ispASL;
    }

    void Engine::setThrottle(float throttle) {
        this->throttle = throttle;
    }

    float Engine::getThrottle() {
        return throttle;
    }

    // apply thrust every physics tick
    void Engine::_fixed_process(float delta) {
        printf("Engine::_fixed_process\n");
        applyThrust((RigidBody *)get_parent(), Vector3(0, 0, 0));
    }
}

GODOT_DLSCRIPT_INIT(godot_dlscript_init_options *options) {
    register_class<OSP::Engine>();
}
