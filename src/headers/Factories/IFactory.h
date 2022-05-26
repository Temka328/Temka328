#pragma once

#include "../IObject.h"
#include <string>
#include <any>
#include <map>
#include <memory>

using namespace std;

class IFactory
{
public:
    virtual std::unique_ptr<IObject> create_game_object(map<string, any> properties) const = 0;

    ~IFactory() = default;
};
