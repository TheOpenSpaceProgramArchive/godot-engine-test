#include "Part.hpp"
#include "PartModule.hpp"
#include <vector>

using namespace std;

namespace OSP {
    void Part::addModule(PartModule *module) {
        modules.push_back(module);
    }

    void Part::removeModule(PartModule *module) {
        // stackoverflow says this works
        // wait no it doesn't nvm
        // modules->erase(remove(modules->begin(), modules->end(), module), modules->end());
    }

    vector<PartModule *>::iterator Part::getModulesIterator() {
        return modules.begin();
    }

    vector<PartModule *> getModulesOfType(char *type) {
        // todo
    }
}
