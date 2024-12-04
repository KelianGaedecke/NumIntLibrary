cmake_minimum_required(VERSION 3.10)

project(NumIntLibrary VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCES
    src/NumInt.cpp
    examples/main.cpp
)

add_executable(integration ${SOURCES})
