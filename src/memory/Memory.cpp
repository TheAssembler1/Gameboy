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

void Gameboy::Memory::writeFileToMemory(uint16_t startAddress, const std::string filepath){
    //creating file and checking if it is NULL
    SDL_RWops* file = NULL;

    file = SDL_RWFromFile(filepath.c_str(), "rb");
    if (!file) { 
        LOG_ERROR << filepath << " was null";
    }
    else{
        LOG_INFO << filepath << " was opened successfully";
    }

    //going to end of file and getting file length
    long fileLength = SDL_RWseek(file, 0, RW_SEEK_END);

    LOG_INFO << "File Length: " << fileLength;

    SDL_RWseek(file, 0, RW_SEEK_SET);

    for (int i = 0; i < fileLength; i++){
        memBuffer[i + startAddress] = SDL_ReadU8(file);
    }

    //closing the file
    SDL_RWclose(file);
}