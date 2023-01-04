#include "ZM83.h"

static void nop(Gameboy::ZM83& zm83);

Gameboy::ZM83::ZM83() {
	registers = {};

	memset(opcodes, NULL, sizeof(opcodes));
	memset(opcodes_cb, NULL, sizeof(opcodes_cb));

	LOG_INFO << "Initialized ZM83";
}

Gameboy::ZM83::~ZM83() {
	LOG_INFO << "Deinitialized ZM83";
}

// FIXME::need to implement MB
void Gameboy::ZM83::writeByteRegister(SelectByteRegister selectByteRegister, uint8_t value) {
	switch (selectByteRegister) {
	case A: registers.a = value; break;
	case F: registers.f = value; break;
	case B: registers.b = value; break;
	case C: registers.c = value; break;
	case D: registers.d = value; break;
	case E: registers.e = value; break;
	case H: registers.h = value; break;
	case L: registers.l = value; break;
	default:
		LOG_FATAL << "Byte register does not exist: " << selectByteRegister;
		break;
	}
}

// FIXME::need to implement MS
void Gameboy::ZM83::writeShortRegister(SelectShortRegister selectShortRegister, uint16_t value) {
	switch (selectShortRegister) {
	case AF: registers.af = value; break;
	case BC: registers.bc = value; break;
	case DE: registers.de = value; break;
	case HL: registers.hl = value; break;
	case SP: registers.sp = value; break;
	case PC: registers.pc = value; break;
	default:
		LOG_FATAL << "Short register does not exist: " << selectShortRegister;
		break;
	}
}

void Gameboy::ZM83::readByteRegister(SelectByteRegister selectByteRegister) {

}

void Gameboy::ZM83::readShortRegister(SelectShortRegister selectShortRegister) {

}

void Gameboy::ZM83::executeOpcode(uint16_t opcode, bool cb) {
	(!cb) ? (*opcodes[opcode])(*this) : (opcodes_cb[opcode])(*this);
}

static void nop(Gameboy::ZM83& zm83) {

}