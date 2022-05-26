#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Capabilities/Moke_IVelocity.h"
#include "../../src/headers/Commands/CorrectVelocityCommand.h"
#include "../../src/headers/Vectors/Vector.h"

template <typename T>
void settingIVelocity(Moke_IVelocity<T> &iVelocity, Vector<T> &dir, Vector<T> &velocity)
{
    EXPECT_CALL(iVelocity, get_speed())
        .Times(1)
        .WillOnce(testing::Return(5.0));

    EXPECT_CALL(iVelocity, get_direction())
        .Times(1)
        .WillOnce(testing::Return(dir));

    EXPECT_CALL(iVelocity, set_velocity(velocity));
};

TEST(CorrectVelocityCommand_test, execute_test)
{
    Vector<double> direction({1.0, 0.0});
    Vector<double> velocity({5.0, 0.0});

    Moke_IVelocity<double> iVelocity;

    settingIVelocity(iVelocity, direction, velocity);

    CorrectVelocityCommand<double> command(iVelocity);

    command.execute();
};
