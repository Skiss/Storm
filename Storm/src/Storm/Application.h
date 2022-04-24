#pragma once

#include "Core.h"
#include "Window.h"

#include <memory>


namespace storm
{

class STORM_API Application
{
public:
	Application();
	virtual ~Application() = default;

	void run();

	void onEvent(const Event& e);

private:
	bool m_isRunning = true;
	std::unique_ptr<Window> m_window;
};

Application* createApplication();

}

