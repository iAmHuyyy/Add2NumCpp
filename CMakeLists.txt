cmake_minimum_required(VERSION 3.10)
project(Add2NumCpp VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(my_big_number
    src/MyBigNumber.cpp
)

target_include_directories(my_big_number PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(add2num
    src/main.cpp
)

target_link_libraries(add2num PRIVATE my_big_number)

add_executable(test_my_big_number
    tests/test_my_big_number.cpp
)

target_link_libraries(test_my_big_number PRIVATE my_big_number)

enable_testing()
add_test(NAME MyBigNumberTests COMMAND test_my_big_number)
