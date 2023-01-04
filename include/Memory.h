#pragma once

#include <plog/Log.h>
#include <stdint.h>

namespace Gameboy {
	class Memory {
	public:
		uint8_t readByteMemory(uint16_t address);
		uint16_t readShortMemory(uint16_t address);

		void writeByteMemory(uint16_t address, uint8_t value);
		void writeShortMemory(uint16_t address, uint16_t value);
	};
}