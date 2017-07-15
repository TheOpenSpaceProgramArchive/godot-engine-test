#include <map>
#include <string>
#include <vector>
#include "ResourceContainer.hpp"
#include "ResourceManager.hpp"
#include "Resource.hpp"
#include "ResourceRatioSpec.hpp"

using std::string;

namespace OSP {
    ResourceContainer::ResourceContainer() {

    }

    void ResourceContainer::addResourceByAmount(string name, float amount) {
        if (resources.count(name) && resources[name]->amount > amount) return;
        ResourceManager *rmg = ResourceManager::getInstance();
        resources[name] = rmg->createResourceByAmount(name, amount);
    }

    void ResourceContainer::addResourceByMass(string name, float mass) {
        if (resources.count(name) && resources[name]->mass > mass) return;
        ResourceManager *rmg = ResourceManager::getInstance();
        resources[name] = rmg->createResourceByMass(name, mass);
    }

    float ResourceContainer::consumeResource(string resource, float mass) {
        float amountToConsume = mass / ResourceManager::getInstance()->getUnitMass(resource);
        if (amountToConsume > resources[resource]->amount) {
            mass = resources[resource]->mass;
            resources[resource]->amount = 0;
            resources[resource]->mass = 0;
            return mass;
        }
        resources[resource]->amount -= amountToConsume;
        resources[resource]->mass -= mass;
        return mass;
    }

    float ResourceContainer::consumeMixture(std::vector<ResourceRatioSpec *> mix, float mass) {
        
    }
}
