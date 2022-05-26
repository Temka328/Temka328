#pragma once

#include "../Vectors/Vector.h"

template <typename T>
class IVelocity
{
public:
    virtual T get_speed() = 0;

    virtual Vector<T> get_direction() = 0;

    virtual void set_velocity(Vector<T> velocity) = 0;

    virtual ~IVelocity() = default;
};
