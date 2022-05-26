#pragma once

#include "gmock/gmock.h"
#include "../../src/headers/Capabilities/IMovable.h"
#include "../../src/headers/Vectors/Vector.h"

template <typename T>
class Moke_IMovable : public IMovable<T>
{
public:
    MOCK_METHOD(Vector<T>, get_velocity, (), (override));

    MOCK_METHOD(Vector<T>, get_position, (), (override));

    MOCK_METHOD(void, set_position, (Vector<T> pos), (override));
};
