cmake_minimum_required(VERSION 3.16)
project(CHIP8-Emulator)

set(CMAKE_CXX_STANDARD 17)

# Find SDL3 (looks in /usr/local by default after install)
find_package(SDL3 REQUIRED)

add_executable(chip8
    src/main.cpp
    src/Chip8.cpp
    src/Emulated-Instructions.cpp
    src/PlatformLayerSDL.cpp
    # add other source files as needed
)

target_include_directories(chip8 PRIVATE
    ${SDL3_INCLUDE_DIRS}
    src
)

target_link_libraries(chip8 PRIVATE SDL3::SDL3)