#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "./Child_Factory/Child_Factory.h"
#include "../../src/headers/IObject.h"
#include "../../src/headers/Vectors/Vector.h"

#include <memory>
#include <map>
#include <vector>
#include <any>

class IFactory_test : public ::testing::Test
{

protected:
    Child_IFactory factory;
    const Child_IFactory constFactory;

    double firstValue = 100.0;
    Vector<double> secondValue;

    IFactory_test() : secondValue({10.0, -5, 0}){

                      };

    ~IFactory_test() = default;
};

TEST_F(IFactory_test, empty_args_init_list_test)
{
    std::unique_ptr<IObject> object = factory.create_game_object({});
    EXPECT_ANY_THROW(object->getProperty("any"));
};

TEST_F(IFactory_test, two_args_test)
{
    std::unique_ptr<IObject> object = factory.create_game_object({{"first", firstValue},
                                                                  {"second", secondValue}});
    EXPECT_DOUBLE_EQ(std::any_cast<double>(object->getProperty("first")), firstValue);
    EXPECT_EQ(std::any_cast<Vector<double>>(object->getProperty("second")), secondValue);
};

TEST_F(IFactory_test, const_obj_test)
{
    std::unique_ptr<IObject> object = constFactory.create_game_object({{"first", firstValue}});
    EXPECT_DOUBLE_EQ(std::any_cast<double>(object->getProperty("first")), firstValue);
};