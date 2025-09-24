cmake_minimum_required(VERSION 3.14)
project(TestDatabase)

cmake_policy(SET CMP0135 NEW)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_database test_database.cpp)

target_link_libraries(test_database PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(test_database)
