#include <map>
#include <string>
#include "ResourceManager.hpp"
#include "Resource.hpp"

using std::string;

namespace OSP {
    ResourceManager *ResourceManager::getInstance() {
        static ResourceManager *instance;
        return instance;
    }

    void ResourceManager::registerResource(string name, float unitMass) {
        resources.insert(std::pair<string, float>(name, unitMass));
    }

    Resource *ResourceManager::createResourceByAmount(string name, float amount) {
        Resource *resource;
        resource->name = name;
        resource->amount = amount;
        resource->mass = amount * resources[name];
        return resource;
    }

    Resource *ResourceManager::createResourceByMass(string name, float mass) {
        Resource *resource;
        resource->name = name;
        resource->amount = mass / resources[name];
        resource->mass = mass;
        return resource;
    }

    float ResourceManager::getUnitMass(string name) {
        return resources[name];
    }
}
