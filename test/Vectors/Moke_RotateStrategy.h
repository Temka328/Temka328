#pragma once

#include "gmock/gmock.h"
#include "../../src/headers/Vectors/RotateStrategy.h"
#include "../../src/headers/Vectors/Vector.h"

template <typename T>
class Moke_RotateStrategy : public RotateStrategy<T>
{
public:
    MOCK_METHOD(Vector<T>, rotate, (const Vector<T> &vector, const T angle), (override));
};
