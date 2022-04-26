#include "Pch.h"

#include "WindowsWindow.h"

#include "Storm/Events/KeyboardEvents.h"
#include "Storm/Events/WindowEvents.h"


namespace storm
{

static void glfwErrorCallback(int error, const char* description)
{
	ST_LOG_ERROR("GLFW window error: {0}", description);
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
		ST_LOG_ERROR("Could not initialize GLFW");
		// ASSERT
		return;
	}

	m_isGLFWInit = true;
	m_window = glfwCreateWindow(props.width, props.height, props.title.c_str(), nullptr, nullptr);

	if (!m_window)
	{
		ST_LOG_ERROR("Could create the GLFW window");
		glfwTerminate();
		// ASSERT
		return;
	}

	glfwMakeContextCurrent(m_window);
	glfwSetWindowUserPointer(m_window, &m_data);

	glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
	{
		WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));

		WindowClosedEvent e;
		data->eventCallback(e);
	});

	glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));

		if (action == GLFW_RELEASE && key == GLFW_KEY_ESCAPE)
		{
			WindowClosedEvent e;
			data->eventCallback(e);
		}
	});

	setVSync(props.vSync);

	ST_LOG_INFO("Windows window initialized");
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
