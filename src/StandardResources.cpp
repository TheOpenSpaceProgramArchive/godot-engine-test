#include "StandardResources.hpp"
#include "ResourceManager.hpp"

namespace OSP {
    void declareStandardResources() {
        ResourceManager *rmg = ResourceManager::getInstance();
        // unit masses should be in kg, but a unit is arbitrary. here it's a liter.
        rmg->registerResource("RP-1", 0.915f);
        rmg->registerResource("LiquidHydrogen", 0.07085f);
        rmg->registerResource("LiquidMethane", 0.42262f);
        rmg->registerResource("LiquidOxygen", 1.141f);
        rmg->registerResource("PBAN", 0.93f);
    }
}
