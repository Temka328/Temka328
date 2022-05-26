#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Capabilities/Moke_IShootable.h"
#include "../../src/headers/Commands/GenerateProjectileCommand.h"
#include "../../src/headers/IObject.h"
#include "../../src/headers/Vectors/Vector.h"
#include "../Factories/Child_Factory/Child_Factory.h"

#include <memory>

class GenerateProjectileCommand_test : public ::testing::Test
{

protected:
    Vector<double> dir;
    Vector<double> start_point;
    Child_IFactory child_factory;
    std::unique_ptr<IObject> obj;
    std::map<std::string, std::any> params;

    GenerateProjectileCommand_test() : dir({1, 0}),
                                       start_point({0, 0}),
                                       params({{"speed", 50.0},
                                               {"direction", dir},
                                               {"position", start_point}})
    {

        obj = child_factory.create_game_object(params);
    };

    ~GenerateProjectileCommand_test() = default;

public:
    void settingIShootable(Moke_IShootable<double> &iShoot)
    {
        EXPECT_CALL(iShoot, get_isShootable())
            .Times(1)
            .WillOnce(testing::Return(true));

        EXPECT_CALL(iShoot, get_projectile_speed())
            .Times(1)
            .WillOnce(testing::Return(double(50)));

        EXPECT_CALL(iShoot, get_direction())
            .Times(1)
            .WillOnce(testing::Return(dir));

        EXPECT_CALL(iShoot, get_projectile_start_point())
            .Times(1)
            .WillOnce(testing::Return(start_point));
    }
};

TEST_F(GenerateProjectileCommand_test, execute_test)
{

    Moke_IShootable<double> iShoot;
    std::unique_ptr<IObject> projectile;

    settingIShootable(iShoot);

    GenerateProjectileCommand<double> command(iShoot, projectile, child_factory);

    command.execute();
    double first = 0, second = 1;
    first = std::any_cast<double>(projectile->getProperty("speed"));
    second = std::any_cast<double>(obj->getProperty("speed"));

    EXPECT_DOUBLE_EQ(first, second);
};
