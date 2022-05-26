#pragma once

#include "../ICommand.h"
#include "../Capabilities/IState.h"

class MoveProjectileCommand : public IComand
{
private:
    IState &state;

public:
    MoveProjectileCommand(IState &iState) : state(iState){};

    void execute();
};

void MoveProjectileCommand::execute()
{
    state.set_state("move");
};
