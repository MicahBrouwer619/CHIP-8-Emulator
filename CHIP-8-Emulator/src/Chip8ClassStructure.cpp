#include "Chip8ClassStructure.hpp"
#include <fstream>
#include <stdexcept>
#include <cstring>

Chip8::Chip8()
{
    // Initialize registers, memory, video, and keypad
    std::memset(memory, 0, sizeof(memory));
    std::memset(video, 0, sizeof(video));
    std::memset(keypad, 0, sizeof(keypad));
    pc = 0x200; // Program counter starts at 0x200
    I = 0; // Index register
    sp = 0; // Stack pointer
    std::memset(stack, 0, sizeof(stack));
    std::memset(V, 0, sizeof(V)); // V registers
}

void Chip8::LoadROM(const char* filename)
{
    std::ifstream romFile(filename, std::ios::binary);
    if (!romFile)
    {
        throw std::runtime_error("Failed to open ROM file.");
    }

    romFile.read(reinterpret_cast<char*>(memory + 0x200), sizeof(memory) - 0x200);
    if (romFile.gcount() == 0)
    {
        throw std::runtime_error("Failed to read ROM file.");
    }
}

void Chip8::Cycle()
{
    // Fetch, decode, and execute the instruction at the current program counter
    uint16_t opcode = (memory[pc] << 8) | memory[pc + 1];
    pc += 2;

    // Decode and execute the opcode (implementation omitted for brevity)
    // ...
}

void Chip8::UpdateVideo()
{
    // Update the video memory (implementation omitted for brevity)
    // ...
}