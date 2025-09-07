cmake_minimum_required(VERSION 4.0)

add_library(DecisionTree
    src/DecisionTree.cpp
        src/Math.cpp
        src/private/Tree.h
        src/Tree.cpp
)

target_include_directories(DecisionTree
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/private
)
