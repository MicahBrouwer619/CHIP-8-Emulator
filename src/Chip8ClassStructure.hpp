#include <cstdint>
#include <chrono>
#include <random>

class Chip8
{

public:
	Chip8();
	void LoadROM(char const *filename);
	void Cycle();

	uint8_t keypad[16]{};
	uint32_t video[32 * 16]{};

private:
	void Table0();
	void Table8();
	void TableE();
	void TableF();

	// Do nothing
	void OP_NULL();

	// Do nothing
	void OP_NULL();

	// CLS
	void OP_00E0();

	// RET
	void OP_00EE();

	// JP address
	void OP_1nnn();

	// CALL address
	void OP_2nnn();

	// SE Vx, byte
	void OP_3xkk();

	// SNE Vx, byte
	void OP_4xkk();

	// SE Vx, Vy
	void OP_5xy0();

	// LD Vx, byte
	void OP_6xkk();

	// ADD Vx, byte
	void OP_7xkk();

	// LD Vx, Vy
	void OP_8xy0();

	// OR Vx, Vy
	void OP_8xy1();

	// AND Vx, Vy
	void OP_8xy2();

	// XOR Vx, Vy
	void OP_8xy3();

	// ADD Vx, Vy
	void OP_8xy4();

	// SUB Vx, Vy
	void OP_8xy5();

	// SHR Vx
	void OP_8xy6();

	// SUBN Vx, Vy
	void OP_8xy7();

	// SHL Vx
	void OP_8xyE();

	// SNE Vx, Vy
	void OP_9xy0();

	// LD I, address
	void OP_Annn();

	// JP V0, address
	void OP_Bnnn();

	// RND Vx, byte
	void OP_Cxkk();

	// DRW Vx, Vy, height
	void OP_Dxyn();

	// SKP Vx
	void OP_Ex9E();

	// SKNP Vx
	void OP_ExA1();

	// LD Vx, DT
	void OP_Fx07();

	// LD Vx, K
	void OP_Fx0A();

	// LD DT, Vx
	void OP_Fx15();

	// LD ST, Vx
	void OP_Fx18();

	// ADD I, Vx
	void OP_Fx1E();

	// LD F, Vx
	void OP_Fx29();

	// LD B, Vx
	void OP_Fx33();

	// LD [I], Vx
	void OP_Fx55();

	// LD Vx, [I]
	void OP_Fx65();

	//16 registers
	uint8_t registers[16]{};
	//4k of memory
	uint8_t memory[4096]{};
	//index register
	uint16_t index{};
	//program counter
	uint16_t pc{};
	//16-level stack
	uint16_t stack[16]{};
	//8-bit stack pointer
	uint8_t sp{};
	//8-bit delay timer
	uint8_t delayTimer{};
	//8-bit sound timer
	uint8_t soundTimer{};
	//32 opcodes
	uint16_t opcode;

	std::default_random_engine randGen;
	std::uniform_int_distribution<uint8_t> randByte;

	typedef void (Chip8::*Chip8Func)();
	Chip8Func table[0xF + 1]{&Chip8::OP_NULL};
	Chip8Func table0[0xE + 1]{&Chip8::OP_NULL};
	Chip8Func table8[0xE + 1]{&Chip8::OP_NULL};
	Chip8Func tableE[0xE + 1]{&Chip8::OP_NULL};
	Chip8Func tableF[0x65 + 1]{&Chip8::OP_NULL};
};
