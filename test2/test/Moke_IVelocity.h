#pragma once

#include "gmock/gmock.h"
#include "/test2/src/IVelocity.h"
#include "test2/src/Vector.h"
#include <vector>


class Moke_IVelocity : public IVelocity
{
public:
    MOCK_METHOD(int, get_speed, (), (override));

    MOCK_METHOD(std::vector<int>, get_direction, (), (override));

    MOCK_METHOD(void, set_velocity, (std::vector<int> velocity), (override));
};
