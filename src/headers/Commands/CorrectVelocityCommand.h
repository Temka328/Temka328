#pragma once

#include "../ICommand.h"
#include "../Capabilities/IVelocity.h"

template <typename T>
class CorrectVelocityCommand : public IComand
{
private:
    IVelocity<T> &iVelocity;

public:
    CorrectVelocityCommand(IVelocity<T> &velocity) : iVelocity(velocity){};

    void execute();
};

template <typename T>
void CorrectVelocityCommand<T>::execute()
{
    iVelocity.set_velocity(iVelocity.get_direction() * iVelocity.get_speed());
};
