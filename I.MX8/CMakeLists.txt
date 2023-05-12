cmake_minimum_required(VERSION 3.22.0)

project(autoattendance VERSION 1.0
                       LANGUAGES C CXX)

add_library(sqlite sqlite3/sqlite3.h)
add_library(dbform include/dbform.hpp)

add_executable(main
 src/main.cpp
 src/Serial.cpp
 src/autoattendance.cpp
 )


target_link_libraries(main sqlite dbform)

target_include_directories(main PRIVATE include sqlite3)

set_target_properties(sqlite PROPERTIES LINKER_LANGUAGE C)
set_target_properties(dbform PROPERTIES LINKER_LANGUAGE CXX)

add_compile_options(-pthread)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")


#fetch content 회사코드 참고 gtest 추가 