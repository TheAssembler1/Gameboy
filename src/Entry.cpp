#include "Logger.h"
#include "ZM83.h"

int main(int argc, char** arv){
	Gameboy::initLogger();

	Gameboy::Memory& mem = *new Gameboy::Memory();
	Gameboy::ZM83& cpu = *new Gameboy::ZM83(mem);

	delete &cpu;
	delete& mem;

	return 0;
}