#pragma once

#include "Event.h"


namespace storm
{

class STORM_API WindowEvent : public Event
{
	EVENT_CLASS_CATEGORY(Window)
};

class STORM_API WindowClosedEvent : public WindowEvent
{
	EVENT_CLASS_TYPE(WindowClosed)
};

class STORM_API WindowMovedEvent : public WindowEvent
{
	EVENT_CLASS_TYPE(WindowMoved)

public:
	unsigned newPosX;
	unsigned newPosY;
};

class STORM_API WindowFocusedEvent : public WindowEvent
{
	EVENT_CLASS_TYPE(WindowFocused)
};

class STORM_API WindowLostFocusEvent : public WindowEvent
{
	EVENT_CLASS_TYPE(WindowLostFocus)
};

class STORM_API WindowResizedEvent : public WindowEvent
{
	EVENT_CLASS_TYPE(WindowResized)

public:
	unsigned newWidth;
	unsigned newHeight;
};

}
