#pragma once

#include "Core.h"

#include <spdlog/spdlog.h>


namespace storm
{

class STORM_API Log
{
public:
	Log() = default;
	~Log() = default;

	static void init();

	static std::shared_ptr<spdlog::logger>& getLogger() { return s_logger; }

private:
	static std::shared_ptr<spdlog::logger> s_logger;
};

}

#define ST_LOG_TRACE(...) storm::Log::getLogger()->trace(__VA_ARGS__)
#define ST_LOG_DEBUG(...) storm::Log::getLogger()->debug(__VA_ARGS__)
#define ST_LOG_INFO(...) storm::Log::getLogger()->info(__VA_ARGS__)
#define ST_LOG_WARNING(...) storm::Log::getLogger()->warn(__VA_ARGS__)
#define ST_LOG_ERROR(...) storm::Log::getLogger()->error(__VA_ARGS__)
#define ST_LOG_CRITICAL(...) storm::Log::getLogger()->critical(__VA_ARGS__)
