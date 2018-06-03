#include <StreamLogger/Logger.h>

extern "C" {
void app_main();
}

using namespace m2d::ESP32;
void app_main()
{
	Logger::Group logger_group("hello");

	Logger::Stream<Logger::Error> errors;
	while (1) {
		logger_group.error << "error" << Logger::endl;
		logger_group.warning << "warning" << Logger::endl;
		logger_group.info << "info" << Logger::endl;
		logger_group.debug << "debug" << Logger::endl;
		logger_group.verbose << "verbose" << Logger::endl;
		Logger::E << "Error" << Logger::endl;
	}
	return;
}
