#pragma once

#include "../ICommand.h"
#include "../Capabilities/IState.h"

class StartRotateCommand : public IComand
{
private:
    IState &state;

public:
    StartRotateCommand(IState &stateObject) : state(stateObject){};

    void execute();

    ~StartRotateCommand() = default;
};

void StartRotateCommand::execute()
{
    state.set_state("rotate");
};
