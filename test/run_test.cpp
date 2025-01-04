#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include <iostream>

int run(); // 前置声明

TEST(RunTest, RunOutputsCorrectEquations) {
  std::string expected {"2 + 2 = 4\n3 * 3 = 9\n"};
  std::stringstream buffer;

  // redirect std::cout to buffer
  auto prevCoutBuf = std::cout.rdbuf(buffer.rdbuf());

  run();  // call run() to capture output
  auto output = buffer.str();

  // restore original std::cout
  std::cout.rdbuf(prevCoutBuf);

  EXPECT_EQ(expected, output);
}