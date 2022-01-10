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
