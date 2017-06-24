#include <godot_cpp/Godot.hpp>
#include <godot_cpp/Node.hpp>
#include <godot_cpp/core/Vector3.hpp>
#include "ThrustProducer.hpp"

namespace OSP {
    class Engine : public ThrustProducer, public godot::Node {
        GODOT_CLASS(Engine, godot::Node)
    public:
        Engine(); // use default values while i figure out how to make it editable in the editor
        Engine(float maxThrustASL, float maxThrustVac, float ispASL, float ispVac);
        // automatically calculate sea level thrust based on ispVac
        Engine(float maxThrustVac, float ispASL, float ispVac);
        float maxThrustVac;
        float maxThrustASL;
        float ispVac;
        float ispASL;
        // TODO: make this with setters/getters so we don't have to normalize it every frame
        godot::Vector3 thrustDirection;
        float throttle;
        // in the real game this would be in atmospheres, gotten from some reliable source
        float getAtmoPressure();
        float currentIsp();
        float currentThrust();
        float ispWithAtmoPressure(float pressure);
        float thrustWithAtmoPressure(float pressure);
        godot::Vector3 getThrustVector();
        void setThrottle(float throttle);
        float getThrottle();
        void _fixed_process(float delta);
        static void _register_methods() {
            register_method("setThrottle", &Engine::setThrottle);
            register_method("getThrottle", &Engine::getThrottle);
            register_method("_fixed_process", &Engine::_fixed_process);
        }
    };
}
