#include <iostream>
#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>
#include <plog/Initializers/ConsoleInitializer.h>


int main() {
    // Step3: write log messages using a special macro
    // There are several log macros, use the macro you liked the most
    plog::init(plog::verbose, "Log.txt", 5000, 3);

    plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
    plog::get()->addAppender(&consoleAppender);

    // Also you can use LOG_XXX macro but it may clash with other logging libraries
    LOG_INFO << "Hello log!"; // long macro

	return 0;
}