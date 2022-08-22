#include <Pch.h>

#include "Application.h"

#include "Storm/Events/Event.h"
#include "Storm/Events/WindowEvents.h"
#include "Window.h"


namespace storm
{

Application::Application()
{
	m_window = Window::createWindow(WindowInfo{"Application", 1080, 780, true});
	ST_ASSERT(m_window);

	m_window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
}

void Application::run()
{
	ST_LOG_INFO("Main App running");
	
	while (m_isRunning)
	{
		for (Layer* layer : m_layerStack)
			layer->update();

		m_window->update();
	}

	ST_LOG_INFO("Main App stopping");
}

void Application::pushLayer(Layer* layer)
{
	ST_LOG_DEBUG("Pushing Layer: {0}", layer->getDebugName());
	m_layerStack.pushLayer(layer);
}

void Application::popLayer(Layer* layer)
{
	ST_LOG_DEBUG("Poping Layer: {0}", layer->getDebugName());
	m_layerStack.popLayer(layer);
}

void Application::pushOverlay(Layer* overlay)
{
	ST_LOG_DEBUG("Pushing Overlay: {0}", overlay->getDebugName());
	m_layerStack.pushOverlay(overlay);
}

void Application::popOverlay(Layer* overlay)
{
	ST_LOG_DEBUG("Poping Overlay: {0}", overlay->getDebugName());
	m_layerStack.popOverlay(overlay);
}

void Application::onEvent(const Event& e)
{
	for (auto it = m_layerStack.end(); it != m_layerStack.begin();)
	{
		(*--it)->onEvent(e);

		if (e.m_isHandled)
			break;
	}

	EventDispatcher ed(e);
	ed.dispatch<WindowClosedEvent>(std::bind(&Application::onWindowClosedEvent, this, std::placeholders::_1));
}

void Application::onWindowClosedEvent(const WindowClosedEvent& e)
{
	m_isRunning = false;
}

}
