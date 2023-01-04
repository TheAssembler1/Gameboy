#include "Logger.h"

using namespace Gameboy;

void Gameboy::initLogger() {
    plog::init(plog::verbose);

    // must statically allocate the appender
    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
    plog::get()->addAppender(&consoleAppender);

    LOG_INFO << "Initialized logger";

}
