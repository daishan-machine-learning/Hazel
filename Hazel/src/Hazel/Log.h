#pragma once
#include"Core.h"
#include<spdlog/spdlog.h>
#include<spdlog/sinks/stdout_color_sinks.h>
#include<spdlog/sinks/basic_file_sink.h>
#include<memory>


namespace  Hazel {
	class HZ_WINS_API Log
	{
	public:
		Log();
		~Log();
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetFileLogger() { return s_FileLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;  //控制台窗口engine信息
		static std::shared_ptr<spdlog::logger> s_ClientLogger; // 控制台窗口game信息
		static std::shared_ptr<spdlog::logger> s_FileLogger;  // 文件中的日志信息
	};


}
// Core log macros
#define HZ_CORE_ERROR(...)	 Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_WARN(...)	 Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_INFO(...)	 Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_TRACE(...)   Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)


// Client log macros
#define HZ_ERROR(...)	 Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_WARN(...)	 Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_INFO(...)	 Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_TRACE(...)    Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)

// File log macros
#define HZ_FILE_ERROR(...) Hazel::Log::GetFileLogger()->error(__VA_ARGS__)
#define HZ_FILE_WARN(...)  Hazel::Log::GetFileLogger()->warn(__VA_ARGS__)
#define HZ_FILE_INFO(...)  Hazel::Log::GetFileLogger()->info(__VA_ARGS__)
#define HZ_FILE_TRACE(...) Hazel::Log::GetFileLogger()->trace(__VA_ARGS__)
