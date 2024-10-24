cmake_minimum_required(VERSION 3.16)

project(leetcode)

set(CMAKE_CXX_STANDARD 17)

add_executable(palyground palyground.cpp)

add_executable(5 "5 最长回文子串/ans.cpp")

add_executable(15 "15 三数之和/ans.cpp")
add_executable(15-reference-ans "15 三数之和/reference ans.cpp")

add_executable(146-splay 146/splay.cpp)

add_executable(215 215/quick-sort-like.cpp)

add_executable(752 752/ans.cpp)

add_executable(912-quick-sort 912/quick-sort.cpp)
add_executable(912-heap-sort 912/heap-sort.cpp)
