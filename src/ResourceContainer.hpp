#include <map>
#include <string>
#include <vector>
#include <godot_cpp/Godot.hpp>
#include "PartModule.hpp"
#include "Resource.hpp"
#include "ResourceRatioSpec.hpp"

#pragma once

namespace OSP {
    class ResourceContainer : public PartModule {
        GODOT_CLASS(ResourceContainer, PartModule)
        std::map<std::string, Resource *> resources;
    public:
        ResourceContainer();
        void addResourceByAmount(std::string name, float amount);
        void addResourceByMass(std::string name, float mass);
        float consumeResource(std::string resource, float massFlowRate, float time);
        float consumeMixture(std::vector<ResourceRatioSpec *> mix, float massFlowRate, float time);
    };
}
