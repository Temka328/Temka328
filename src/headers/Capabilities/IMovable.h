#pragma once

#include "../Vectors/Vector.h"

template <typename T>
class IMovable
{
public:
    virtual Vector<T> get_velocity() = 0;

    virtual Vector<T> get_position() = 0;

    virtual void set_position(Vector<T> pos) = 0;

    virtual ~IMovable() = default;
};
