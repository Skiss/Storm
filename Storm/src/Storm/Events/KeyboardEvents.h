#pragma once

#include "Event.h"


namespace storm
{

class STORM_API KeyboardEvent : public Event
{
	EVENT_CLASS_CATEGORY(Keyboard)

public:
	KeyboardEvent(int key) : keyCode(key) {}

	int keyCode;
};

class STORM_API KeyPressedEvent : public KeyboardEvent
{
	EVENT_CLASS_TYPE(KeyPressed)

public:
	KeyPressedEvent(int key, int repeatCount) : KeyboardEvent(key), repeatCount(repeatCount) {}

	int repeatCount = 0;
};

class STORM_API KeyReleasedEvent : public KeyboardEvent
{
	EVENT_CLASS_TYPE(KeyReleased)

public:
	KeyReleasedEvent(int key) : KeyboardEvent(key) {}
};

}
