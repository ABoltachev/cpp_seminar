cmake_minimum_required(VERSION 3.16)

project(Cpp_seminar)

add_library(Test_library SHARED TestLib.cpp)

add_executable(main main.cpp)

target_link_libraries(main Test_library)
