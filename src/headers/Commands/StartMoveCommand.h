#pragma once

#include "../ICommand.h"
#include "../Vectors/Vector.h"
#include "../Capabilities/IState.h"

class StartMoveCommand : public IComand
{
private:
    IState &state;

public:
    StartMoveCommand(IState &stateObject) : state(stateObject){};

    void execute();
};

void StartMoveCommand::execute()
{
    state.set_state("move");
};
