#pragma once
#include "../Vectors/Vector.h"

template <typename T>
class IShootable
{
public:
    virtual bool get_isShootable() = 0;

    virtual T get_projectile_speed() = 0;

    virtual Vector<T> get_projectile_start_point() = 0;

    virtual Vector<T> get_direction() = 0;

    virtual ~IShootable() = default;
};
