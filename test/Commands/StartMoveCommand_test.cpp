#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Capabilities/Moke_IState.h"
#include "../../src/headers/Commands/StartMoveCommand.h"

TEST(StartMoveCommand_test, execute_test)
{

    Moke_IState iState;

    EXPECT_CALL(iState, set_state("move"));

    StartMoveCommand command(iState);

    command.execute();
};
