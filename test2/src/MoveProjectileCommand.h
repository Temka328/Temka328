#pragma once

#include "ICommand.h"
#include "IState.h"

class MoveProjectileCommand : public IComand
{
private:
    IState &state;

public:
    MoveProjectileCommand(IState &iState) : state(iState){};

    void execute()
    {
        state.set_state("move");
    }
};
