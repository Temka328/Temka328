#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Capabilities/Moke_IState.h"
#include "../../src/headers/Commands/MoveProjectileCommand.h"

TEST(MoveProjectileCommand_test, execute_test)
{

    Moke_IState iState;

    EXPECT_CALL(iState, set_state("move"));

    MoveProjectileCommand command(iState);

    command.execute();
};
