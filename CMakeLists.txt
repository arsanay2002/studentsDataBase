cmake_minimum_required(VERSION 3.14)
project(TestDatabase)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.14.0.zip
)

# Для Windows (если нужно) принудительно используем общие сборки CRT
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_database test_database.cpp)

target_link_libraries(test_database PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(test_database)
