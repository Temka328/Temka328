#include "./Child_Factory.h"

#include "../../../src/headers/IObject.h"
#include "../../../src/headers/Factories/IFactory.h"

#include <memory>
#include <map>
#include <string>
#include <any>

std::unique_ptr<IObject> Child_IFactory::create_game_object(std::map<std::string, std::any> properties) const
{
    return this->IFactory::create_game_object(properties);
};
