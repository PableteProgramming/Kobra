cmake_minimum_required(VERSION 3.12)

project(Kobra)

set(SRC_FILES
    kobra/src/kobra.cpp
    lexer/src/lexer.cpp
    func/src/func.cpp
)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(
    ${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/kobra/include
)