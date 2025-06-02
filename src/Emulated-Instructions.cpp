//clear the routine
void Chip8::OP_00E0()
{
	memset(video, 0, sizeof(video));
}
//return from a subroutine
void Chip8::OP_00EE()
{
	--sp;
	pc = stack[sp];
}
//jump to location
void Chip8::OP_1nnn()
{
	uint16_t address = opcode & 0x0FFFu;

	pc = address;
}
//call subroutine
void Chip8::OP_2nnn()
{
	uint16_t address = opcode & 0x0FFFu;

	stack[sp] = pc;
	++sp;
	pc = address;
}
