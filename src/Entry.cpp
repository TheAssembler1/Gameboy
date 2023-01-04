#include "Logger.h"
#include "ZM83.h"

int main(int argc, char** arv){
	Gameboy::initLogger();
	Gameboy::ZM83& cpu = *new Gameboy::ZM83();

	delete &cpu;
	return 0;
}