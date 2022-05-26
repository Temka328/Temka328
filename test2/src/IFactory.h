#pragma once

#include "IObject.h"
#include <string>
#include <any>
#include <map>
#include <memory>
#include "Object.h"

class IFactory
{
public:
    std::unique_ptr<IObject> create_game_object(std::map<std::string, std::any> properties)
    {
        std::unique_ptr<IObject> obj(new Object());
        for (auto elem : properties)
        {
            obj->setProperty(elem.first, elem.second);
        }
        return obj;
    }

    ~IFactory() = default;
};
