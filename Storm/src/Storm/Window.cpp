#include <Pch.h>

#include <Storm/Plateforms/WindowsWindow.h>


namespace storm
{

std::unique_ptr<Window> Window::createWindow(const WindowInfo& props)
{
#ifdef STORM_PLATFORM_WINDOWS
	return std::make_unique<WindowsWindow>(props);
#else
	#error "Window creation not supported for this plateform"
#endif

	return nullptr;
}

}
