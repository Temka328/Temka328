#pragma once

#include "gmock/gmock.h"
#include "../../src/headers/Capabilities/IVelocity.h"
#include "../../src/headers/Vectors/Vector.h"

template <typename T>
class Moke_IVelocity : public IVelocity<T>
{
public:
    MOCK_METHOD(T, get_speed, (), (override));

    MOCK_METHOD(Vector<T>, get_direction, (), (override));

    MOCK_METHOD(void, set_velocity, (Vector<T> velocity), (override));
};
