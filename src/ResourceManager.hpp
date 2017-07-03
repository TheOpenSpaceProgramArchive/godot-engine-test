#include <map>
#include <string>
#include "Resource.hpp"

#pragma once

namespace OSP {
    class ResourceManager {
    private:
        std::map<std::string, float> resources;
        ResourceManager();
    public:
        static ResourceManager *getInstance();
        void registerResource(std::string name, float unitMass);
        Resource *createResourceByAmount(std::string name, float amount);
        Resource *createResourceByMass(std::string name, float mass);
        float getUnitMass(std::string name);
    };
}
