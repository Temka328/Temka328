#pragma once

#include "../Vectors/Vector.h"

template <typename T>
class IRotatable
{
public:
    virtual T get_angle_velocity() = 0;

    virtual Vector<T> get_direction() = 0;

    virtual void set_direction(Vector<T> direction) = 0;

    virtual ~IRotatable() = default;
};
