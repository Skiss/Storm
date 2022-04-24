#pragma once

#include <functional>
#include <memory>
#include <string>


namespace storm
{

struct WindowInfo
{
	std::string title = "Untitled";
	unsigned width = 100;
	unsigned height = 100;
	bool vSync = true;
};

class Event;

class STORM_API Window
{
public:
	using EventCallback = std::function<void(const Event&)>;

	virtual void update() = 0;

	virtual unsigned getWidth() const = 0;
	virtual unsigned getHeight() const = 0;

	virtual void setVSync(bool enabled) = 0;
	virtual bool getVSync() const = 0;

	virtual void setEventCallback(const EventCallback& cb) = 0;

	static std::unique_ptr<Window> createWindow(const WindowInfo& props);

protected:
	Window(const WindowInfo& props)
		: m_props(props)
	{}

	WindowInfo m_props;
};

}
