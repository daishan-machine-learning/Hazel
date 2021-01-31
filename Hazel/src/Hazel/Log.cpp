#include "Log.h"
namespace Hazel {
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
	std::shared_ptr<spdlog::logger> Log::s_FileLogger;
	Log::Log() {


	}

	Log::~Log() {


	}
	void Log::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$"); // 设置打印模式
		s_CoreLogger = spdlog::stdout_color_mt("Hazel");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);

		s_FileLogger = spdlog::basic_logger_mt("basic_logger", "log.txt");
		

	}	

}
