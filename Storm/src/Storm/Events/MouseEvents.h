#pragma once

#include "Event.h"


namespace storm
{

class STORM_API MouseEvent : public Event
{
	EVENT_CLASS_CATEGORY(Mouse)

public:
	unsigned newPosX;
	unsigned newPosY;
};

}
