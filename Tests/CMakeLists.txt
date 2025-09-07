cmake_minimum_required(VERSION 4.0)

enable_testing()

add_executable(LibreriaTests
    src/main.cpp
        src/CSVReader.cpp
        src/private/CSVReader.h
        src/private/Types.h
)

target_include_directories(LibreriaTests
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/private
)

target_link_libraries(LibreriaTests
    PRIVATE
        DecisionTree
)

add_test(NAME LibreriaTests COMMAND LibreriaTests)
