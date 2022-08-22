#pragma once

#include <Storm/Core.h>

#include<functional>


namespace storm
{

enum class EventType
{
	WindowClosed,
	WindowMoved,
	WindowFocused,
	WindowLostFocus,
	WindowResized,
	KeyPressed,
	KeyReleased,
	MouseMoved,
	MouseScrolled,
	MouseButtonPressed,
	MouseButtonReleased
};

enum class EventCategory
{
	None = 1 << 0,
	Window = 1 << 1,
	Keyboard = 1 << 2,
	Mouse = 1 << 3,
	Input = Keyboard | Mouse
};

#ifdef STORM_DEBUG
#define EVENT_CLASS_TYPE(type)\
public:\
	virtual const char* getName() const override { return #type; }\
	virtual EventType getType() const override { return getStaticType(); }\
	static EventType getStaticType() { return EventType::##type; }
#else
#define EVENT_CLASS_TYPE(type)\
public:\
	virtual EventType getType() const override { return getStaticType(); }\
	static EventType getStaticType() { return EventType::##type; }
#endif


#define EVENT_CLASS_CATEGORY(category)\
public:\
	virtual EventCategory getCategory() const { return EventCategory::##category; }\

class STORM_API Event
{
public:
#ifdef STORM_DEBUG
	virtual const char* getName() const = 0;
#endif
	virtual EventType getType() const = 0;
	virtual EventCategory getCategory() const = 0;

	bool m_isHandled = false;
};

class EventDispatcher
{
public:
	EventDispatcher(const Event& e)
		: m_event(e) 
	{}

	template <typename T, typename F>
	void dispatch(const F& function)
	{
		if (m_event.getType() == T::getStaticType())
		{
			function(static_cast<const T&>(m_event));
			const_cast<Event&>(m_event).m_isHandled = true;
		}
	}

private:
	const Event& m_event;
};

}
