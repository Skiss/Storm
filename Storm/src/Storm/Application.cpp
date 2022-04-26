#include <Pch.h>

#include "Application.h"

#include "Storm/Events/Event.h"
#include "Window.h"


namespace storm
{

Application::Application()
{
	m_window = Window::createWindow(WindowInfo{"Application", 1080, 780, true});
	m_window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
}

void Application::run()
{
	ST_LOG_INFO("Main App running");
	
	while (m_isRunning)
	{
		m_window->update();
	}
}

void Application::onEvent(const Event& e)
{
	if (e.getType() == EventType::WindowClosed)
		m_isRunning = false;
}

}
