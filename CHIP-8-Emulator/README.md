# CHIP-8 Emulator

## Overview
The CHIP-8 Emulator is a simple implementation of the CHIP-8 virtual machine, allowing users to run CHIP-8 ROMs. This project includes a graphical interface for displaying the emulator's output and handling user input.

## Project Structure
```
CHIP-8-Emulator
├── src
│   ├── main.cpp                  # Entry point of the application
│   ├── Chip8ClassStructure.hpp    # Header for the Chip8 class
│   ├── Chip8ClassStructure.cpp    # Implementation of the Chip8 class
│   ├── Platform.hpp               # Header for the Platform class
│   └── Platform.cpp               # Implementation of the Platform class
├── CMakeLists.txt                # CMake configuration file
└── README.md                     # Project documentation
```

## Building the Project
To build the CHIP-8 Emulator, follow these steps:

1. Ensure you have CMake installed on your system.
2. Open a terminal and navigate to the project directory.
3. Create a build directory:
   ```
   mkdir build
   cd build
   ```
4. Run CMake to configure the project:
   ```
   cmake ..
   ```
5. Build the project:
   ```
   make
   ```

## Running the Emulator
After building the project, you can run the emulator using the following command:
```
./CHIP-8-Emulator <Scale> <Delay> <ROM>
```
- `<Scale>`: The scaling factor for the display (e.g., 10).
- `<Delay>`: The delay between cycles in milliseconds (e.g., 16).
- `<ROM>`: The path to the CHIP-8 ROM file you want to run.

## License
This project is licensed under the MIT License. See the LICENSE file for more details.