#pragma once
#include<Hazel/Core.h>
#include<functional>
#include<iostream>
namespace Hazel {
	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled

	};

	// 组合事件
	enum EventCategory {
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)

	};

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags()const{return category;}

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType(){return EventType::##type;}\
								virtual EventType GetEventType()const override{return GetStaticType();}\
								virtual const char*GetName()const{return #type;}

	class HZ_WINS_API Event {
	public:
		virtual EventType GetEventType()const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags()const = 0;

		virtual std::string ToString()const { return GetName(); }
		inline bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_handle;
	};

	class HZ_WINS_API EventDispatcher {
		template<typename T>
		using EventFn = std::function<bool(T&)>; // 函数指针的前缀

	public:
		EventDispatcher(Event& event)
			:m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFn<T> func) {
			if (m_Event.GetEventType() == T::GetStaticType()) {
				m_Event.m_handle = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}
} 