#pragma once
#include "Vector.h"


class IShootable
{
public:
    virtual bool get_isShootable() = 0;

    virtual int get_projectile_speed() = 0;

    virtual std::vector<int> get_projectile_start_point() = 0;

    virtual std::vector<int> get_direction() = 0;

    virtual ~IShootable() = default;
};
