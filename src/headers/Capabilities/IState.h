#pragma once
#include <string>

class IState
{
public:
    virtual void set_state(std::string state) = 0;

    virtual ~IState() = default;
};
