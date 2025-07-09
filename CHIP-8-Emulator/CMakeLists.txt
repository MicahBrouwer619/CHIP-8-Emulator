cmake_minimum_required(VERSION 3.16)
project(CHIP8-Emulator)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(chip8
    src/main.cpp
    src/Chip8.cpp
    src/PlatformLayerSDL.cpp
    src/Chip8ClassStructure.cpp
    src/Platform.cpp
    # add other source files as needed
)

target_include_directories(chip8 PRIVATE
    ${SDL2_INCLUDE_DIRS}
    src
)

target_link_libraries(chip8 ${SDL2_LIBRARIES})