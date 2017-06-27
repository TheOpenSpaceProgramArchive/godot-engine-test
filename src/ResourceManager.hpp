#include <vector>
#include "Resource.hpp"

#pragma once

namespace OSP {
    class ResourceManager {
    private:
        struct ResourceSpec {
            char *name;
            float unitMass;
        };
        std::vector<ResourceSpec> *resources;
        ResourceManager();
        ResourceManager(const ResourceManager &copy);
        ResourceManager &(const ResourceManager &assign);
    public:
        static ResourceManager *getInstance();
        void registerResource(char *name, float unitMass);
        Resource *createResource(char *name, float amount);
    };
}
