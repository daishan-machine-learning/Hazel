#pragma once
// write macros

#ifdef HZ_PLATFORM_WINS

	#ifdef HZ_BUILD_DLL
		#define HZ_WINS_API __declspec(dllexport)
	#else
		#define HZ_WINS_API __declspec(dllimport)
	#endif
#else
	#error It has to run in windows platform!
#endif