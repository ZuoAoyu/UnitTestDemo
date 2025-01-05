include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(unit_tests
                calc_test.cpp
                run_test.cpp)
target_link_libraries(unit_tests PRIVATE sut gtest_main gmock)
# 作用: 将 sut 库 和 gtest_main 链接到 unit_tests 可执行文件中。

include(Coverage)
AddCoverage(unit_tests)

include(Valgrind)
AddValgrind(unit_tests)

include(GoogleTest)
gtest_discover_tests(unit_tests)
# 使所有的测试用例都能被发现并执行。
