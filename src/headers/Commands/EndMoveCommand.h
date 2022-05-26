#pragma once

#include "../ICommand.h"
#include "../Capabilities/IState.h"

class EndMoveCommand : public IComand
{
private:
    IState &state;

public:
    EndMoveCommand(IState &stateObject) : state(stateObject){};

    void execute();

    ~EndMoveCommand() = default;
};

void EndMoveCommand::execute()
{
    state.set_state("stand");
};
