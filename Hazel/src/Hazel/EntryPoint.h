#pragma once
#ifdef HZ_PLATFORM_WINS
#include"Hazel.h"
extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, void** argv) {
	Hazel::Log::Init();
	HZ_CORE_WARN("Initialize Information");
	HZ_INFO("main fucntion starts up!!");
	
	HZ_FILE_ERROR("Game Engine start!");

	auto app = Hazel::CreateApplication();
	app->run();
	delete app;
}

#endif
