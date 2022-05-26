#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Capabilities/Moke_IState.h"
#include "../../src/headers/Commands/EndRotateCommand.h"

TEST(EndRotateCommand_test, execute_test)
{

    Moke_IState iState;

    EXPECT_CALL(iState, set_state("stand"));

    EndRotateCommand command(iState);

    command.execute();
};
