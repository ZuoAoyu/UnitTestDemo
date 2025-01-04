#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include <iostream>
#include <regex>

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

  EXPECT_EQ(expected, output.substr(0, output.find("3 + random number =")));

  // 定义正则模式
  std::regex pattern(R"(3 \+ random number = (\d+)\n)");
  // 使用 std::regex_search 来检查 output 是否匹配模式
  std::smatch matches;
  bool match_found = std::regex_search(output, matches, pattern);
  // 断言是否匹配
  EXPECT_TRUE(match_found) << "Pattern not found in the output";
  // 如果匹配，输出捕获的数字（随机数值）
  if (match_found) {
    int random_number = std::stoi(matches[1].str()); // 提取捕获的数字
    std::cout << "Captured random number: " << random_number << std::endl;
  }
}