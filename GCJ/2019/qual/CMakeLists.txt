cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(foregone_solution foregone_solution.cpp)
add_executable(you_can_go_your_own_way you_can_go_your_own_way.cpp)
add_executable(cryptopangrams cryptopangrams.cpp)
add_executable(dat_bae dat_bae.cpp)
