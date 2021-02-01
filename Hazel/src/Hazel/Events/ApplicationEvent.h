#pragma once
#include"Event.h"
#include<sstream>

namespace Hazel {
	
	
	class HZ_WINS_API WindowResizeEvent :public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) :m_width(width),m_height(height){}

		inline unsigned int GetWidth()const { return m_width; }
		inline unsigned int GetHeight()const { return m_height; }
		std::string ToString()const override {
			std::stringstream ss;
			ss << "WIndowResizeEvent:(" << m_width << "," << m_height << ")";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowResize)
	private:
		unsigned int m_width, m_height;
	};


	class HZ_WINS_API WindowCloseEvent :public Event {
	public:
		WindowCloseEvent(){}
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowClose)

	};
	class HZ_WINS_API AppTickEvent :public Event {
	public:
		AppTickEvent(){}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppTick)
	};

	class HZ_WINS_API AppUpdateEvent :public Event {
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
			EVENT_CLASS_TYPE(AppUpdate)
	};

	class HZ_WINS_API AppRenderEvent :public Event {
	public:
		AppRenderEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
			EVENT_CLASS_TYPE(AppRender)
	};



}