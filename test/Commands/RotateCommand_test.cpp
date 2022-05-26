#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Vectors/Moke_RotateStrategy.h"
#include "../../src/headers/Commands/RotateCommand.h"
#include "../Capabilities/Moke_IRotatable.h"

template <typename T>
void settingIRotate(Moke_IRotatable<T> &iRotate, T angle, Vector<T> &oldDir, Vector<T> &newDir)
{
    EXPECT_CALL(iRotate, get_angle_velocity())
        .Times(1)
        .WillOnce(testing::Return(angle));

    EXPECT_CALL(iRotate, get_direction())
        .Times(1)
        .WillOnce(testing::Return(oldDir));

    newDir.normalize();
    EXPECT_CALL(iRotate, set_direction(newDir))
        .Times(1);
};

template <typename T>
void settingRotateStrategy(Moke_RotateStrategy<T> &iRotate, T angle, Vector<T> &oldDir, Vector<T> &newDir)
{
    EXPECT_CALL(iRotate, rotate(oldDir, angle))
        .Times(1)
        .WillOnce(testing::Return(newDir));
};

TEST(RotateCommand_test, execute_test)
{
    Vector<double> oldDir({1, 0});
    Vector<double> newDir({0, 2});
    Moke_IRotatable<double> iRotate;
    Moke_RotateStrategy<double> strategy;
    double angle = 90.;

    settingRotateStrategy(strategy, angle, oldDir, newDir);
    settingIRotate(iRotate, angle, oldDir, newDir);

    RotateCommand command(iRotate, strategy);

    command.execute();
};
