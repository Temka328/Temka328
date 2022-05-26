#include "Object.h"
#include <any>
#include <string>
#include "ObjectPropertyException.h"

std::any Object::getProperty(const std::string &key)
{
    if (store.count(key) == 0)
        throw ObjectPropertyException("Property \"" + key + "\" isnt had");
    return store[key];
}

void Object::setProperty(const std::string &key, const std::any &value)
{
    store[key] = value;
}
