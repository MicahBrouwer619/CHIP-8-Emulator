#include <cstdint>

class Chip8
{
Chip8::Chip8()
	: randGen(std::chrono::system_clock::now().time_since_epoch().count())

{	// Initialize PC
	pc = START_ADDRESS;
	// Load fonts into memory
	for (unsigned int i = 0; i < FONTSET_SIZE; ++i)
	{
		memory[FONTSET_START_ADDRESS + i] = fontset[i];
	}
	// Initialize RNG
		randByte = std::uniform_int_distribution<uint8_t>(0, 255U);
}

public:
	uint8_t registers[16]{};
	uint8_t memory[4096]{};
	uint16_t index{};
	uint16_t pc{};
	uint16_t stack[16]{};
	uint8_t sp{};
	uint8_t delayTimer{};
	uint8_t soundTimer{};
	uint8_t keypad[16]{};
	uint32_t video[64 * 32]{};
	uint16_t opcode;
};

std::default_random_engine randGen;
std::uniform_int_distribution<uint8_t> randByte;
