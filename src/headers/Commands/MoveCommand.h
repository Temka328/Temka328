#pragma once

#include "../ICommand.h"
#include "../Capabilities/IMovable.h"

template <typename T>
class MoveCommand : public IComand
{
private:
    IMovable<T> &movable;

public:
    MoveCommand(IMovable<T> &mov) : movable(mov){};

    void execute();
};

template <typename T>
void MoveCommand<T>::execute()
{
    movable.set_position(movable.get_position() + movable.get_velocity());
};
