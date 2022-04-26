#pragma once

#include "Core.h"


#ifdef ST_ENABLE_ASSERTS
	#define ST_ASSERT(x) do { if (!(x)) { ST_LOG_ERROR("Assertion {0} failed at {1}:{2}", #x, __FILE__, __LINE__); ST_DEBUGBREAK; } } while (false)
	#define ST_ASSERT_MSG(x, ...) do { if (!(x)) { ST_LOG_ERROR("Assertion failed: {0}", __VA_ARGS__); ST_DEBUGBREAK; } } while (false)
#else
	#define ST_ASSERT(x)
	#define ST_ASSERT_MSG(x, ...)
#endif
