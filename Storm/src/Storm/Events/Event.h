#pragma once

#include <Storm/Core.h>


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

#define EVENT_CLASS_TYPE(type)\
public:\
	virtual const char* getName() const { return #type; }\
	virtual EventType getType() const { return EventType::##type; }

#define EVENT_CLASS_CATEGORY(category)\
public:\
	virtual EventCategory getCategory() const { return EventCategory::##category; }\

class STORM_API Event
{
public:
	virtual const char* getName() const = 0;
	virtual EventType getType() const = 0;
	virtual EventCategory getCategory() const = 0;
};

}
