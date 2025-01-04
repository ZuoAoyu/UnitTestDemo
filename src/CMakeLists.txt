add_library(sut STATIC calc.cpp run.cpp rng_mt19937.cpp)
target_include_directories(sut INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
# 作用: 任何链接到 sut 库的目标都会自动包含(include)当前源目录，当它们在源代码中包含 sut 的头文件时，可以直接使用文件名，而不需要使用完整路径。
# sut本身知道自己的头文件在哪里，但是链接到 sut 的目标不知道 sut 的头文件在哪里，所以需要通过INTERFACE关键字告诉链接到 sut 的目标 sut 的头文件在哪里。
# 通过 INTERFACE 关键字，sut 会将 sut 的头文件路径传递给链接到 sut 的目标，这样链接到 sut 的目标就可以直接使用 sut 的头文件了。
# INTERFACE 意味着消费者需要但生产者不需要的东西。PUBLIC 意味着生产者和消费者都需要的东西。PRIVATE 意味着只有生产者需要的东西。

add_executable(main main.cpp)
target_link_libraries(main PRIVATE sut)
# 作用: 将 sut 库链接到 main 可执行文件中。