#pragma once

#include "Vector.h"


class IVelocity
{
public:
    virtual int get_speed() = 0;

    virtual std::vector<int> get_direction() = 0;

    virtual void set_velocity(std::vector<int> velocity) = 0;

    virtual ~IVelocity() = default;
};
