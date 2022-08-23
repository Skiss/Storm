#pragma once

#include <Storm/Window.h>


struct GLFWwindow;

namespace storm
{

class WindowsWindow : public Window
{
public:
	WindowsWindow(const WindowInfo& props);
	virtual ~WindowsWindow();

	void init(const WindowInfo& props);
	void update() override;

	virtual unsigned getWidth() const override { return m_props.width; }
	virtual unsigned getHeight() const override { return m_props.height; }

	virtual void setVSync(bool enabled) override;
	virtual bool getVSync() const  override { return m_props.vSync; }

	virtual void setEventCallback(const EventCallback& cb) override { m_data.eventCallback = cb; }

private:
	struct WindowData
	{
		EventCallback eventCallback;
	};

	GLFWwindow* m_window = nullptr;
	bool m_isGLFWInit = false;
	WindowData m_data;
};

}
