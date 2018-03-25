//
// Created by i32ropie on 25/03/18.
//

#include <gtest/gtest.h>

TEST(Example, example_eq){
    EXPECT_EQ(0, 0);
    EXPECT_EQ(1, 1);
    EXPECT_EQ(2, 2);
    EXPECT_EQ(3, 3);
    EXPECT_EQ(4, 4);
    EXPECT_EQ(5, 5);
    EXPECT_EQ(6, 6);
    EXPECT_EQ(7, 7);
    EXPECT_EQ(8, 8);
    EXPECT_EQ(9, 9);
}

TEST(Example, example_ne){
    EXPECT_NE(0, 0 + 1);
    EXPECT_NE(1, 1 + 1);
    EXPECT_NE(2, 2 + 1);
    EXPECT_NE(3, 3 + 1);
    EXPECT_NE(4, 4 + 1);
    EXPECT_NE(5, 5 + 1);
    EXPECT_NE(6, 6 + 1);
    EXPECT_NE(7, 7 + 1);
    EXPECT_NE(8, 8 + 1);
    EXPECT_NE(9, 9 + 1);
}