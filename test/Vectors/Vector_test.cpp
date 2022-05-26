#include <iostream>

#include "gtest/gtest.h"
#include "../../src/headers/Vectors/Vector.h"

class Vector_test : public ::testing::Test
{
protected:
    Vector<int> i3dV1;
    Vector<int> i3dV2;
    Vector<int> i3dV3;
    Vector<int> i1dV1;
    Vector<double> d3dV1;
    Vector<double> d3dV2;

    Vector_test() : i3dV1(3),
                    i3dV2(3, {0, 0, 2}),
                    i3dV3(3, {0, 0, 1}),
                    i1dV1({1}),
                    d3dV1({1., 1., 2.}),
                    d3dV2(d3dV1)
    {
        i3dV1[0] = 1;
        i3dV1[1] = 1;
        i3dV1[2] = 3;
    };

    ~Vector_test() = default;
};

TEST_F(Vector_test, comparison_of_double_vectors)
{
    EXPECT_TRUE(d3dV1 == d3dV2);
};

TEST_F(Vector_test, taking_by_index)
{
    EXPECT_EQ(i3dV1[0], 1);
    EXPECT_THROW(i3dV1[3], std::out_of_range);
};

TEST_F(Vector_test, change_by_index)
{
    Vector<int> temp(i3dV1);
    temp[0] = -2;
    EXPECT_EQ(temp[0], -2);
    EXPECT_THROW(temp[5] = 2, std::out_of_range);
};

TEST_F(Vector_test, vector_addiction)
{
    Vector<int> temp = i3dV1 + i3dV2;
    EXPECT_EQ(temp[0], 1);
    EXPECT_EQ(temp[1], 1);
    EXPECT_EQ(temp[2], 5);
    EXPECT_THROW(temp = i3dV1 + i1dV1, VectorArithmeticException);
};

TEST_F(Vector_test, vector_difference)
{
    Vector<int> temp = i3dV1 - i3dV2;
    EXPECT_EQ(temp[0], 1);
    EXPECT_EQ(temp[1], 1);
    EXPECT_EQ(temp[2], 1);
    EXPECT_THROW(temp = i3dV1 - i1dV1, VectorArithmeticException);
};

TEST_F(Vector_test, multiplication_of_vector_by_number)
{
    Vector<int> temp = i3dV1 * 3;
    EXPECT_EQ(temp[0], 3);
    EXPECT_EQ(temp[1], 3);
    EXPECT_EQ(temp[2], 9);
};

TEST_F(Vector_test, division_of_vector_by_number)
{
    Vector<double> temp = d3dV1 / 2.0;
    EXPECT_DOUBLE_EQ(temp[0], 1. / 2.);
    EXPECT_DOUBLE_EQ(temp[1], 1. / 2.);
    EXPECT_DOUBLE_EQ(temp[2], 1.0);
};

TEST_F(Vector_test, size_int_vector)
{
    EXPECT_EQ(2, i3dV2.size());
};

TEST_F(Vector_test, normalize_int_vector)
{
    i3dV2.normalize();
    EXPECT_TRUE(i3dV3 == i3dV2);
};

TEST_F(Vector_test, get_dim_fun)
{
    EXPECT_EQ(3, d3dV1.getDim());
};

TEST_F(Vector_test, get_component_fun)
{
    EXPECT_DOUBLE_EQ(1., d3dV1.getComponent(0));
    EXPECT_THROW(d3dV1.getComponent(-5), std::out_of_range);
};

TEST_F(Vector_test, set_component_fun)
{
    d3dV1.setComponent(0, -3.);
    EXPECT_DOUBLE_EQ(-3., d3dV1.getComponent(0));
    EXPECT_THROW(d3dV1.setComponent(-1, -2.), std::out_of_range);
};
