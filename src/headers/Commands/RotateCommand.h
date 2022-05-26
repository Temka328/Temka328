#pragma once

#include "../ICommand.h"
#include "../Capabilities/IRotatable.h"
#include "../Vectors/RotateStrategy.h"

template <typename T>
class RotateCommand : public IComand
{
private:
    IRotatable<T> &rotatable;
    RotateStrategy<T> &strategy;

public:
    RotateCommand(IRotatable<T> &rotate, RotateStrategy<T> &strat) : rotatable(rotate), strategy(strat){};

    void execute();
};

template <typename T>
void RotateCommand<T>::execute()
{
    Vector<T> newDir = strategy.rotate(rotatable.get_direction(), rotatable.get_angle_velocity());
    newDir.normalize();
    rotatable.set_direction(newDir);
};
