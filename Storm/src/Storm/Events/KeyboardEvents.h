#pragma once

#include "Event.h"


namespace storm
{

class STORM_API KeyboardEvent : public Event
{
	EVENT_CLASS_CATEGORY(Keyboard)
};

class STORM_API KeyPressedEvent : public KeyboardEvent
{
	EVENT_CLASS_TYPE(KeyPressed)

public:
	int keyCode;
};

class STORM_API KeyReleasedEvent : public KeyboardEvent
{
	EVENT_CLASS_TYPE(KeyReleased)

public:
	int keyCode;
};

}
