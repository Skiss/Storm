#pragma once

#ifdef STORM_PLATFORM_WINDOWS
	#ifdef STORM_BUILD_DLL
		#define STORM_API __declspec(dllexport)
	#else
		#define STORM_API __declspec(dllimport)
	#endif
#else
	#error "The Storm engine only supports Windows"
#endif

#ifdef STORM_DEBUG
	#define ST_ENABLE_ASSERTS

	#ifdef STORM_PLATFORM_WINDOWS
		#define ST_DEBUGBREAK __debugbreak()
	#else
		#error "Only the Windows platform is supported."
	#endif
#endif
