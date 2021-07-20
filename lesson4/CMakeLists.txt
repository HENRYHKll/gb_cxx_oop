cmake_minimum_required(VERSION 3.18)

project(oop4 CXX)

add_executable(oop4 main.cxx)
target_compile_features(oop4 PUBLIC cxx_std_17)
include(CTest)
add_test(NAME chec_oop4
        COMMAND oop4)