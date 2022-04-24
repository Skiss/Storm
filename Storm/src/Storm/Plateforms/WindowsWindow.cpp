#include "Pch.h"

#include "WindowsWindow.h"

#include "Storm/Events/KeyboardEvents.h"
#include "Storm/Events/WindowEvents.h"


namespace storm
{

static void glfwErrorCallback(int error, const char* description)
{
	STORM_ERROR("GLFW window error: {0}", description);
	// ASSERT here
}

WindowsWindow::WindowsWindow(const WindowInfo& props)
	: Window(props)
{
	init(props);
}

WindowsWindow::~WindowsWindow()
{
	if (m_window)
		glfwDestroyWindow(m_window);

	if (m_isGLFWInit)
		glfwTerminate();
}

void WindowsWindow::init(const WindowInfo& props)
{
	glfwSetErrorCallback(glfwErrorCallback);

	if (!glfwInit())
	{
		// ASSERT
		return;
	}

	m_isGLFWInit = true;
	m_window = glfwCreateWindow(props.width, props.height, props.title.c_str(), nullptr, nullptr);

	if (!m_window)
	{
		glfwTerminate();
		// ASSERT
		return;
	}

	glfwMakeContextCurrent(m_window);
	glfwSetWindowUserPointer(m_window, &m_data);

	glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
	{
		WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));
		// ASSERT
		WindowClosedEvent e;
		data->eventCallback(e);
	});

	glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));
		// ASSERT

		if (action == GLFW_RELEASE && key == GLFW_KEY_ESCAPE)
		{
			WindowClosedEvent e;
			data->eventCallback(e);
		}
	});

	setVSync(props.vSync);
}

void WindowsWindow::update()
{
	glfwSwapBuffers(m_window);
	glfwPollEvents();
}

void WindowsWindow::setVSync(bool enabled)
{
	glfwSwapInterval(enabled ? 1 : 0);
	m_props.vSync = enabled;
}

}
