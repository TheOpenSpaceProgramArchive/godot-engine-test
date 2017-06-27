#include <vector>
#include <godot_cpp/Godot.hpp>
#include "PartModule.hpp"
#include "Resource.hpp"
#include "ResourceManager.hpp"

#pragma once

namespace OSP {
    class ResourceContainer : public PartModule {
        GODOT_CLASS(ResourceContainer, PartModule)
        std::vector<Resource> *resources;
    public:
        ResourceContainer();

    };
}
