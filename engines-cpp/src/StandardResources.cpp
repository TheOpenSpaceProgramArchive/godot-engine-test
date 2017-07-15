#include "StandardResources.hpp"
#include "ResourceManager.hpp"

namespace OSP {
    void declareStandardResources() {
        ResourceManager *rmg = ResourceManager::getInstance();
        // rmg->registerResource("RP-1", 0.915f);
        // rmg->registerResource("LiquidHydrogen", 0.07085f);
        // rmg->registerResource("LiquidMethane", 0.42262f);
        // rmg->registerResource("LiquidOxygen", 1.141f);
        // rmg->registerResource("PBAN", 0.93f);
        // for all these fuels the unit is just a kg
        rmg->registerResource("RP-1", 1);
        rmg->registerResource("LiquidHydrogen", 1);
        rmg->registerResource("LiquidMethane", 1);
        rmg->registerResource("LiquidOxygen", 1);
        rmg->registerResource("PBAN", 1);
        rmg->registerResource("Hydrazine", 1);
        rmg->registerResource("GaseousNitrogen", 1);
        rmg->registerResource("XenonGas", 1);
    }
}
