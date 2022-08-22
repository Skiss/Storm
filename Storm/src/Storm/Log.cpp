#include <Pch.h>

#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"


namespace storm
{

std::shared_ptr<spdlog::logger> Log::s_logger;


void Log::init()
{
	auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	consoleSink->set_level(spdlog::level::trace);
	consoleSink->set_pattern("%^[%T] %n - %-8l : %v%$");

	auto fileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("Storm.log", true);
	fileSink->set_level(spdlog::level::trace);
	fileSink->set_pattern("[%T] %n - %-8l : %v");

	spdlog::sinks_init_list sinkList = { consoleSink, fileSink };

	s_logger = std::make_shared<spdlog::logger>("Storm", sinkList.begin(), sinkList.end());
	s_logger->set_level(spdlog::level::trace);
	s_logger->flush_on(spdlog::level::debug);

	spdlog::register_logger(s_logger);

	ST_LOG_INFO("Logger initialized");
}

}
