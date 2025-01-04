#include <gtest/gtest.h>
#include "calc.h"
#include "mocks/rng_mock.h"

class CalcTestSuite : public ::testing::Test {
  protected:
    RandomNumberGeneratorMock rng_mock_;
    Calc sut_{&rng_mock_};  // System Under Test
};

TEST_F(CalcTestSuite, SumAddsTwoInts) {
    EXPECT_EQ(4, sut_.Sum(2, 2));
}

TEST_F(CalcTestSuite, MultiplyMultipliesTwoInts) {
    EXPECT_EQ(6, sut_.Multiply(2, 3));
}

TEST_F(CalcTestSuite, AddRandomNumberAddsThree) {
    EXPECT_CALL(rng_mock_, Get()).Times(1).WillOnce(::testing::Return(3));
    EXPECT_EQ(4, sut_.AddRandomNumber(1));
}
