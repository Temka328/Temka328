#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Capabilities/Moke_IState.h"
#include "../../src/headers/Commands/EndMoveCommand.h"

TEST(EndMoveCommand_test, execute_test)
{

    Moke_IState iState;

    EXPECT_CALL(iState, set_state("stand"));

    EndMoveCommand command(iState);

    command.execute();
};
