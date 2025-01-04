#include <gtest/gtest.h>
#include "calc.h"

class CalcTestSuite : public ::testing::Test {
  protected:
    Calc sut_;  // System Under Test
};

TEST_F(CalcTestSuite, SumAddsTwoInts) {
    EXPECT_EQ(4, sut_.Sum(2, 2));
}

TEST_F(CalcTestSuite, MultiplyMultipliesTwoInts) {
    EXPECT_EQ(6, sut_.Multiply(2, 3));
}
