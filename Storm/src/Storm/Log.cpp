#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"


namespace storm
{

std::shared_ptr<spdlog::logger> Log::s_logger;


void Log::init()
{
	spdlog::set_level(spdlog::level::trace);

	s_logger = spdlog::stdout_color_mt("STORM");
	s_logger->set_pattern("%^ [%T] %n: %v%$");
	s_logger->set_level(spdlog::level::trace);
}

}
