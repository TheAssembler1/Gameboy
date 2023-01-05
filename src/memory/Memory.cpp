#include "Memory.h"

uint8_t Gameboy::Memory::readByteMemory(uint16_t address) {
	return memBuffer[address];
}

uint16_t Gameboy::Memory::readShortMemory(uint16_t address) {
	return memBuffer[address + 1] << 8 | memBuffer[address];
}

void Gameboy::Memory::writeByteMemory(uint16_t address, uint8_t value) {
	memBuffer[address] = value;
}

void Gameboy::Memory::writeShortMemory(uint16_t address, uint16_t value) {
	memBuffer[address + 1] = (value & 0xFF00) >> 8;
	memBuffer[address] = value & 0x00FF;
}

uint8_t* Gameboy::Memory::getMemoryBuffer(){
	return memBuffer;
}

void Gameboy::Memory::writeFileToMemory(const std::string filepath){
	
}