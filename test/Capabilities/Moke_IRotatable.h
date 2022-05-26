#pragma once

#include "gmock/gmock.h"
#include "../../src/headers/Capabilities/IRotatable.h"
#include "../../src/headers/Vectors/Vector.h"

template <typename T>
class Moke_IRotatable : public IRotatable<T>
{
public:
    MOCK_METHOD(T, get_angle_velocity, (), (override));

    MOCK_METHOD(Vector<T>, get_direction, (), (override));

    MOCK_METHOD(void, set_direction, (Vector<T> direction), (override));
};
