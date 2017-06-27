#include <vector>
#include <string.h>
#include "ResourceManager.hpp"
#include "Resource.hpp"

namespace OSP {
    ResourceManager *ResourceManager::getInstance() {
        static ResourceManager *instance;
        return instance;
    }

    void ResourceManager::registerResource(char *name, float unitMass) {
        ResourceSpec spec;
        spec.name = name;
        spec.unitMass = unitMass;
        resources->push_back(spec);
    }

    Resource *ResourceManager::createResource(char *name, float amount) {
        ResourceSpec spec;
        for (auto it = resources->begin(); it != resources->end(); ++it) {
            if (strcmp(*it.name, name) == 0) {
                spec = *it;
                break;
            }
        }
        Resource *resource;
        resource->name = name;
        resource->amount = amount;
        resource->mass = amount * spec.unitMass;
        return resource;
    }
}
