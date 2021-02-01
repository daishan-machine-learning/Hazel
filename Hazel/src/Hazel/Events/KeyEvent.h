#pragma once
#include"Event.h"
#include<string>
#include<sstream>
namespace Hazel {

	class HZ_WINS_API KeyEvent :public Event {
	public:
		inline int GetKeyCode()const { return m_KeyCode; }
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
	protected:
		KeyEvent(int code) :m_KeyCode(code) {  // can't instantiate
		
		
		}
		int m_KeyCode;  // key code

	};

	class HZ_WINS_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int code, int counts) 
			:KeyEvent(code), m_KeyRepeatCounts(counts) {}

		std::string ToString()const override {
			std::stringstream ss;
			ss << "KeyPressEvent:" << m_KeyCode << "(" << m_KeyRepeatCounts << "repeats)";
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyPressed)   // 这些宏用的真好
	private:
		int m_KeyRepeatCounts;

	};

	class HZ_WINS_API KeyReleasedEvent : public KeyEvent {

	public:
		KeyReleasedEvent(int keycode) :KeyEvent(keycode) {}

		EVENT_CLASS_TYPE(KeyReleased)

		std::string ToString()const override{
			std::stringstream ss;
			ss << "KeyReleasedEvent:" << m_KeyCode;
			return ss.str();

		}
	
	};
}