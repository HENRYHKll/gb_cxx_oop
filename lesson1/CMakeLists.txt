cmake_minimum_required(VERSION 3.18)

project(oop CXX)

add_executable(oop main.cxx)
target_compile_features(oop PUBLIC cxx_std_17)
include(CTest)
add_test(NAME chec_oop
        COMMAND oop)