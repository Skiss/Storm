#pragma once

#include "Core.h"
#include "LayerStack.h"
#include "Window.h"

#include <memory>


namespace storm
{

class WindowClosedEvent;

class STORM_API Application
{
public:
	Application();
	virtual ~Application() = default;

	void run();

	void pushLayer(Layer* layer);
	void popLayer(Layer* layer);
	void pushOverlay(Layer* overlay);
	void popOverlay(Layer* overlay);

	void onEvent(const Event& e);

private:
	void onWindowClosedEvent(const WindowClosedEvent& e);

	bool m_isRunning = true;
	std::unique_ptr<Window> m_window;
	LayerStack m_layerStack;
};

Application* createApplication();

}

