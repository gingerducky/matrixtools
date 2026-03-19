cmake_minimum_required(VERSION 3.15)
project(MatrixReduction VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(matrix-tools
    src/main.cpp
)

target_include_directories(matrix-tools PUBLIC ${PROJECT_SOURCE_DIR}/include)
