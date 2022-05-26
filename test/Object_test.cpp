#include <iostream>

#include "gtest/gtest.h"
#include "../src/headers/Object.h"
#include <any>

class Object_test : public ::testing::Test
{
protected:
    Object obj1;
    Object emptyObj;

    Object_test()
    {
        obj1.setProperty("State", "stand");
        obj1.setProperty("Number", 1.0);
    };

    ~Object_test() = default;
};

TEST_F(Object_test, get_any_property)
{
    EXPECT_EQ(typeid(obj1.getProperty("Number")), typeid(std::any));
}

TEST_F(Object_test, get_double_property)
{

    EXPECT_DOUBLE_EQ(std::any_cast<double>(obj1.getProperty("Number")), 1.0);
};

TEST_F(Object_test, get_string_property)
{
    EXPECT_EQ(std::any_cast<const char *>(obj1.getProperty("State")), "stand");
}

TEST_F(Object_test, try_get_null_property)
{
    EXPECT_ANY_THROW(emptyObj.getProperty("any"));
};
