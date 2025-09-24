cmake_minimum_required(VERSION 3.15)
project(TestDatabase)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

find_package(GTest CONFIG REQUIRED)

add_executable(test_database test_database.cpp)

target_link_libraries(test_database PRIVATE GTest::gtest GTest::gtest_main pthread)

add_test(NAME test_database COMMAND test_database)
