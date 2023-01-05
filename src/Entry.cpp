#include "Logger.h"
#include "ZM83.h"

#define SDL_MAIN_HANDLED
#include <SDL.h>

int main(int argc, char** arv){
	Gameboy::initLogger();

	Gameboy::Memory& mem = *new Gameboy::Memory();
	Gameboy::ZM83& cpu = *new Gameboy::ZM83(mem);

	delete &cpu;
	delete &mem;

	return 0;
}