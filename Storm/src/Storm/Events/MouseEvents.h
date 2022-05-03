#pragma once

#include "Event.h"


namespace storm
{

class STORM_API MouseEvent : public Event
{
	EVENT_CLASS_CATEGORY(Mouse)
};

class STORM_API MouseMovedEvent : public MouseEvent
{
	EVENT_CLASS_TYPE(MouseMoved)

public:
	float newPosX;
	float newPosY;
};

class STORM_API MouseScrolledEvent : public MouseEvent
{
	EVENT_CLASS_TYPE(MouseScrolled)

public:
	float offsetX;
	float offsetY;
};

class STORM_API MouseButtonEvent : public MouseEvent
{
public:
	int mouseButtonCode;
};

class STORM_API MouseButtonPressedEvent : public MouseButtonEvent
{
	EVENT_CLASS_TYPE(MouseButtonPressed)
};

class STORM_API MouseButtonReleasedEvent : public MouseButtonEvent
{
	EVENT_CLASS_TYPE(MouseButtonReleased)
};

}
