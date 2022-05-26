#pragma once

#include <any>
#include <string>
#include <map>

#include "IObject.h"

class Object : public IObject
{
private:
    std::map<std::string, std::any> store;

public:
    Object() = default;

    virtual std::any getProperty(const std::string &key);
    virtual void setProperty(const std::string &key, const std::any &value);

    ~Object() = default;
};
