#pragma once

#include "../ICommand.h"
#include "../Capabilities/IState.h"

class EndRotateCommand : public IComand
{
private:
    IState &state;

public:
    EndRotateCommand(IState &stateObject) : state(stateObject){};

    void execute();

    ~EndRotateCommand() = default;
};

void EndRotateCommand::execute()
{
    state.set_state("stand");
};
