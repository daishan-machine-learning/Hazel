#pragma once
#ifdef HZ_PLATFORM_WINS
#include"Hazel.h"
extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, void** argv) {
	printf("Sandbox!\n");
	auto app = Hazel::CreateApplication();
	app->run();
	delete app;
}

#endif
