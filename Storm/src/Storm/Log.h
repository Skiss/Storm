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

#define STORM_TRACE(...) storm::Log::getLogger()->trace(__VA_ARGS__)
#define STORM_INFO(...) storm::Log::getLogger()->info(__VA_ARGS__)
#define STORM_WARNING(...) storm::Log::getLogger()->warning(__VA_ARGS__)
#define STORM_ERROR(...) storm::Log::getLogger()->error(__VA_ARGS__)
#define STORM_FATAL(...) storm::Log::getLogger()->fatal(__VA_ARGS__)
