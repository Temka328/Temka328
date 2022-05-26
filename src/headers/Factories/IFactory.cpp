#include "./IFactory.h"
#include "../Object.h"

std::unique_ptr<IObject> IFactory::create_game_object(map<string, any> properties) const
{

    std::unique_ptr<IObject> obj(new Object());

    for (auto elem : properties)
    {
        obj->setProperty(elem.first, elem.second);
    }

    return obj;
};
