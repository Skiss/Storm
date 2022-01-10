#pragma once

#include "Core.h"

namespace storm
{

class STORM_API Application
{
public:
	Application() {}
	virtual ~Application() {}

	void run();
};

Application* createApplication();

}

