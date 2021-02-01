#pragma once
#include"Event.h"
#include<sstream>
#include<utility>
namespace Hazel {

	class HZ_WINS_API MouseMovedEvent :public Event {
	public:
		MouseMovedEvent(float x, float y):m_x(x),m_y(y){}

		inline std::pair<float, float> GetPosition()const {
			return std::make_pair(m_x, m_y);
		}
		inline int GetX()const { return m_x; }
		inline int GetY()const { return m_y; }

		std::string ToString()const override {
			std::stringstream ss;
			ss << "MouseMovedEvent:" << "(" << m_x << "," << m_y << ")";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
		EVENT_CLASS_TYPE(MouseMoved)
		
	private:
		float m_x, m_y;
	};

	class HZ_WINS_API MouseScrolledEvent :public Event {
	public:
		MouseScrolledEvent(float offsetX, float offsetY) 
			:m_offsetX(offsetX),m_offsetY(offsetY){}
		inline float GetOffsetX()const { return m_offsetX; }
		inline float GetOffsetY()const { return m_offsetY; }
		std::string ToString()const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent:" <<"("<< GetOffsetX() << "," << GetOffsetY()<<")";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
		EVENT_CLASS_TYPE(MouseScrolled)
	private:
		float m_offsetX, m_offsetY;

	};
	class HZ_WINS_API MouseButtonEvent :public Event {
	public:

		inline int GetMouseButton()const { return m_button; }
		
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

	protected:
		MouseButtonEvent(int button) :m_button(button) {}
		int m_button;

	};

	class HZ_WINS_API MouseButtonPressedEvent :public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button) :
			MouseButtonEvent(button) {}
		std::string ToString()const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent:" << m_button;
			return ss.str();

		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class HZ_WINS_API MouseButtonReleasedEvent : public MouseButtonEvent{
	public:
		MouseButtonReleasedEvent(int button) :
			MouseButtonEvent(button) {}
		std::string ToString()const override {
			std::stringstream ss;
			ss << " MouseButtonReleasedEvent:" << m_button;
			return ss.str();

		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

	
}