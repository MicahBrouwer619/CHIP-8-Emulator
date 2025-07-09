cmake_minimum_required(VERSION 3.14)
project(chip8)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/glad/include)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(
    chip8
    src/Chip8.cpp
    src/main.cpp
    src/PlatformLayerSDL.cpp
    ${CMAKE_SOURCE_DIR}/glad/src/glad.c
)

target_compile_options(chip8 PRIVATE -Wall)
target_link_libraries(chip8 PRIVATE ${SDL2_LIBRARIES})
