#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Moke_IShootable.h"
#include "/test/src/GenerateProjectileCommand.h"
#include "/test/src/CMakeLists.txt"
#include "/test/src/Vector.h"
#include <memory>

class GenerateProjectileCommand_test : public ::testing::Test
{

protected:
    std::vector<int> dir, start_point;
    Child_IFactory child_factory;
    std::unique_ptr<IObject> obj;
    std::map<std::string, std::any> params;

    GenerateProjectileCommand_test() : dir({1, 0}),
                                       start_point({0, 0}),
                                       params({{"speed", 50},
                                               {"direction", dir},
                                               {"position", start_point}})
    {
        obj = child_factory.create_game_object(params);
    };

    ~GenerateProjectileCommand_test() = default;

public:
    void settingIShootable(Moke_IShootable &iShoot)
    {
        EXPECT_CALL(iShoot, get_isShootable())
            .Times(1)
            .WillOnce(testing::Return(true));

        EXPECT_CALL(iShoot, get_projectile_speed())
            .Times(1)
            .WillOnce(testing::Return(50));

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

    Moke_IShootable iShoot;
    std::unique_ptr<IObject> projectile;

    settingIShootable(iShoot);

    GenerateProjectileCommand command(iShoot, projectile, child_factory);

    command.execute();

    int first = 0, second = 1;
    first = std::any_cast<int>(projectile->getProperty("speed"));
    second = std::any_cast<int>(obj->getProperty("speed"));

    EXPECT_EQ(first, second);
};
