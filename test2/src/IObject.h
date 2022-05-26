#pragma once

#include <any>
#include <string>

class IObject
{
public:
    virtual std::any getProperty(const std::string &key) = 0;

    virtual void setProperty(const std::string &key, const std::any &value) = 0;

    virtual ~IObject() = default;
};
