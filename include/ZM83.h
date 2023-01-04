#pragma once

#include <plog/Log.h>

#define OPCODES_SIZE 0xFF
#define OPCODES_CB_SIZE 0xFF

namespace Gameboy{
	class ZM83 {
	public:
		enum SelectByteRegister {
			A, F, B, C, D, E, H, L, MB
		};

		enum SelectShortRegister {
			AF, BC, DE, HL, SP, PC, MS
		};

		ZM83();
		~ZM83();

		void executeOpcode(uint16_t opcode, bool cb);

		void writeByteRegister(SelectByteRegister selectByteRegister, uint8_t value);
		void writeShortRegister(SelectShortRegister selectShortRegister, uint16_t value);

		void readByteRegister(SelectByteRegister selectByteRegister);
		void readShortRegister(SelectShortRegister selectShortRegister);

	private:
		struct Registers {
			// accumulator & flags
			union {
				struct {
					uint8_t f;
					uint8_t a;
				};
				uint16_t af;
			};
			// bc
			union {
				struct {
					uint8_t c;
					uint8_t b;
				};
				uint16_t bc;
			};
			// de
			union {
				struct {
					uint8_t e;
					uint8_t d;
				};
				uint16_t de;
			};
			// hl
			union {
				struct {
					uint8_t l;
					uint8_t h;
				};
				uint16_t hl;
			};
			// stack pointer
			uint16_t sp;
			// program counter/pointer
			uint16_t pc;
		};

		Registers registers;

		void (*opcodes[OPCODES_SIZE])(ZM83& zm83);
		void (*opcodes_cb[OPCODES_CB_SIZE])(ZM83& zm83);
	};
}