#pragma once
#include"Core.h"
namespace Hazel {
	class  HZ_WINS_API Application
	{
	public:
		Application();
		virtual ~Application();
		void run();

		
	};
	// define in use client
	Application* CreateApplication();
}