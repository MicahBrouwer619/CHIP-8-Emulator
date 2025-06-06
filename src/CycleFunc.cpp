#include"Chip8ClassStructure.hpp"


void Chip8::Cycle()
{
	// Fetch
	opcode = (memory[pc] << 8u) | memory[pc + 1];

	// Increment the PC before we execute anything
	pc += 2;

	// Decode and Execute
	((*this).*(table[(opcode & 0xF000u) >> 12u]))();

	// Decrement the delay timer 
	if (delayTimer > 0)
	{
		--delayTimer;
	}

	// Decrement the sound timer 
	if (soundTimer > 0)
	{
		--soundTimer;
	}
}