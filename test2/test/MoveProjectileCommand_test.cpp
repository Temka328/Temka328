#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "test2/src/Moke_IState.h"
#include "test2/src/MoveProjectileCommand.h"

TEST(MoveProjectileCommand_test, execute_test)
{

    Moke_IState iState;

    EXPECT_CALL(iState, set_state("move"));

    MoveProjectileCommand command(iState);

    command.execute();
};
