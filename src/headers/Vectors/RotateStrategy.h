#pragma once

#include "Vector.h"

template <typename T>
class RotateStrategy
{
public:
    virtual Vector<T> rotate(const Vector<T> &vector, const T angle) = 0;

    ~RotateStrategy() = default;
};
