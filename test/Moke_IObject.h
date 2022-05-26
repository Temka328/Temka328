#pragma once

#include "gmock/gmock.h"
#include "../src/headers/IObject.h"

#include <any>
#include <string>

class Moke_IObject : public IObject
{
public:
    MOCK_METHOD((std::any), getProperty, (const std::string &key), (override));

    MOCK_METHOD(void, setProperty, (const std::string &key, const std::any &value), (override));
};
