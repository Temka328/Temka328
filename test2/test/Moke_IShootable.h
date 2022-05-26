#pragma once

#include "gmock/gmock.h"
#include "../../src/Capabilities/IShootable.h"
#include "../../src/Vector.h"

class Moke_IShootable : public IShootable
{
public:
    MOCK_METHOD(bool, get_isShootable, (), (override));

    MOCK_METHOD(int, get_projectile_speed, (), (override));

    MOCK_METHOD(std::vector<int>, get_projectile_start_point, (), (override));

    MOCK_METHOD(std::vector<int>, get_direction, (), (override));
};
