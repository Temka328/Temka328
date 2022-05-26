#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Capabilities/Moke_IMovable.h"
#include "../../src/headers/Commands/MoveCommand.h"

void settingIMovable(Moke_IMovable<double> &iMovable, Vector<double> &velocity, Vector<double> &position)
{

    EXPECT_CALL(iMovable, get_velocity())
        .Times(1)
        .WillOnce(testing::Return(velocity));

    EXPECT_CALL(iMovable, get_position())
        .Times(1)
        .WillOnce(testing::Return(position));

    EXPECT_CALL(iMovable, set_position(velocity));
};

TEST(MoveCommand_test, execute_test)
{
    Vector<double> position({0.0, 0.0});
    Vector<double> velocity({5.0, 0.0});

    Moke_IMovable<double> iMovable;

    settingIMovable(iMovable, velocity, position);

    MoveCommand<double> command(iMovable);

    command.execute();
};
