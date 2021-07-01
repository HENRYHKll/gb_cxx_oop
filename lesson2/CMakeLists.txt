cmake_minimum_required(VERSION 3.18)

project(oop2 CXX)

add_executable(oop2 main.cxx)
target_compile_features(oop2 PUBLIC cxx_std_17)
include(CTest)
add_test(NAME chec_oop2
        COMMAND oop2)