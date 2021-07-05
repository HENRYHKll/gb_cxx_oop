cmake_minimum_required(VERSION 3.18)

project(oop3 CXX)

add_executable(oop3 main.cxx)
target_compile_features(oop3 PUBLIC cxx_std_17)
include(CTest)
add_test(NAME chec_oop3
        COMMAND oop3)