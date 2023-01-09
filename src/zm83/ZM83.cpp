#include "ZM83.h"

namespace Gameboy {
	//NOP | 1 | 4 | - - - - -
	static void nop(ZM83& zm83) {
		zm83.addToPCRegister(1);
		zm83.addToCycles(4);
	}

	//STOP | 1 | 4 | - - - - -
	static void stop(ZM83& zm83) {
		zm83.addToPCRegister(1);
		zm83.addToCycles(4);

		zm83.stopped = true;
	}

	//HALT | 1 | 4 | - - - - -
	static void halt(ZM83& zm83) {
		zm83.addToPCRegister(1);
		zm83.addToCycles(4);

		zm83.halted = true;
	}
}

Gameboy::ZM83::ZM83(Memory& memory) : memory(memory) {
	registers = {};

	interruptsEnabled = { true };
	stopped = { false };
	halted = { false };

	memset(opcodes, NULL, sizeof(opcodes));
	memset(opcodes_cb, NULL, sizeof(opcodes_cb));

	//NOP | 1 | 4 | - - - - -
	opcodes[0x00] = nop;
	//STOP | 1 | 4 | - - - - -
	opcodes[0x10] = stop;

	LOG_INFO << "Initialized ZM83";
}

Gameboy::ZM83::~ZM83() {
	LOG_INFO << "Deinitialized ZM83";
}

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
	case MB: memory.writeByteMemory(readShortRegister(HL), value); break;
	default:
		LOG_FATAL << "Write byte register does not exist: " << selectByteRegister;
		break;
	}
}

void Gameboy::ZM83::writeShortRegister(SelectShortRegister selectShortRegister, uint16_t value) {
	switch (selectShortRegister) {
	case AF: registers.af = value; break;
	case BC: registers.bc = value; break;
	case DE: registers.de = value; break;
	case HL: registers.hl = value; break;
	case SP: registers.sp = value; break;
	case PC: registers.pc = value; break;
	case MS: memory.writeShortMemory(readShortRegister(HL), value); break;
	default:
		LOG_FATAL << "Write short register does not exist: " << selectShortRegister;
		break;
	}
}

uint8_t Gameboy::ZM83::readByteRegister(SelectByteRegister selectByteRegister) {
	switch (selectByteRegister) {
	case A: return registers.a; break;
	case F: return registers.f; break;
	case B: return registers.b; break;
	case C: return registers.c; break;
	case D: return registers.d; break;
	case E: return registers.e; break;
	case H: return registers.h; break;
	case L: return registers.l; break;
	case MB: return memory.readByteMemory(readShortRegister(HL)); break;
	default:
		LOG_FATAL << "Read byte register does not exist: " << selectByteRegister;
		return 0;
		break;
	}
}

uint16_t Gameboy::ZM83::readShortRegister(SelectShortRegister selectShortRegister) {
	switch (selectShortRegister) {
	case AF: return registers.af; break;
	case BC: return registers.bc; break;
	case DE: return registers.de; break;
	case HL: return registers.hl; break;
	case SP: return registers.sp; break;
	case PC: return registers.pc; break;
	case MS: return memory.readShortMemory(readShortRegister(HL)); break;
	default:
		LOG_FATAL << "Read short register does not exist: " << selectShortRegister;
		return 0;
		break;
	}
}

void Gameboy::ZM83::executeOpcode(uint16_t opcode, bool cb) {
	if (stopped || halted) return;

	if(!cb){
		if(opcodes[opcode] == NULL){
			LOG_FATAL << "Opcode does not exist: " << opcode;
		}

		(*opcodes[opcode])(*this);
	}else{
		if(opcodes_cb[opcode] == NULL){
			LOG_FATAL << "Opcode does not exist: " << opcode;
		}

		(opcodes_cb[opcode])(*this);
	}
}

void Gameboy::ZM83::executeInterrupt(uint16_t opcode) {
	if (interruptsEnabled) {
		halted = false;
		executeOpcode(false, opcode);
	}
}

// special functions for pc since it changes so often
void Gameboy::ZM83::writePCRegister(uint16_t value){
	registers.pc = value;
}

void Gameboy::ZM83::addToPCRegister(uint16_t value){
	registers.pc += value;
}

void Gameboy::ZM83::addToCycles(unsigned long value){
	cycles += value;
}