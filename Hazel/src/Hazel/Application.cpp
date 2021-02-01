#include "Application.h"
#include"log.h"
#include"Events/ApplicationEvent.h"
namespace Hazel {

	Application::Application() {
	
	
	}
	Application::~Application() {
	
	}

	void Application::run() {
		WindowResizeEvent e(1200,640);
		HZ_CORE_ERROR(e);
		while (true);
	}
}