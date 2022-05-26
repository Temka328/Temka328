#pragma once

#include "../../../src/headers/IObject.h"
#include "../../../src/headers/Factories/IFactory.h"

#include <memory>
#include <map>
#include <string>
#include <any>

class Child_IFactory : public IFactory
{
public:
    virtual std::unique_ptr<IObject> create_game_object(std::map<std::string, std::any> properties) const;
};
