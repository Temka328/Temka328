#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Capabilities/Moke_IState.h"
#include "../../src/headers/Commands/StartRotateCommand.h"

TEST(StartRotateCommand_test, execute_test)
{

    Moke_IState iState;

    EXPECT_CALL(iState, set_state("rotate"));

    StartRotateCommand command(iState);

    command.execute();
};
