#pragma once

#include "gmock/gmock.h"
#include "../../src/headers/Capabilities/IVelocity.h"
#include "../../src/headers/Vectors/Vector.h"
#include <vector>
#include "../src/headers/operators.cpp"

class Moke_IVelocity : public IVelocity
{
public:
    MOCK_METHOD(int, get_speed, (), (override));

    MOCK_METHOD(std::vector<int>, get_direction, (), (override));

    MOCK_METHOD(void, set_velocity, (std::vector<int> velocity), (override));
};
