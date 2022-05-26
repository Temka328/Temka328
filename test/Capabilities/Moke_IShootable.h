#pragma once

#include "gmock/gmock.h"
#include "../../src/headers/Capabilities/IShootable.h"
#include "../../src/headers/Vectors/Vector.h"

template <typename T>
class Moke_IShootable : public IShootable<T>
{
public:
    MOCK_METHOD(bool, get_isShootable, (), (override));

    MOCK_METHOD(T, get_projectile_speed, (), (override));

    MOCK_METHOD(Vector<T>, get_projectile_start_point, (), (override));

    MOCK_METHOD(Vector<T>, get_direction, (), (override));
};
