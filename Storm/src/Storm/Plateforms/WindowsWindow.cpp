#include "Pch.h"

#include "WindowsWindow.h"

#include "Storm/Events/KeyboardEvents.h"
#include "Storm/Events/MouseEvents.h"
#include "Storm/Events/WindowEvents.h"


namespace storm
{

static void glfwErrorCallback(int error, const char* description)
{
	ST_LOG_ERROR("GLFW window error: {0}", description);
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
		return;
	}

	m_isGLFWInit = true;
	m_window = glfwCreateWindow(props.width, props.height, props.title.c_str(), nullptr, nullptr);

	if (!m_window)
	{
		ST_LOG_ERROR("Could create the GLFW window");
		glfwTerminate();

		return;
	}

	glfwMakeContextCurrent(m_window);
	glfwSetWindowUserPointer(m_window, &m_data);

	// Setting events callbacks

	glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
	{
		WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));
		ST_ASSERT(data);

		WindowClosedEvent e;
		data->eventCallback(e);
	});

	glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));
		ST_ASSERT(data);

		if (action == GLFW_PRESS)
		{
			KeyPressedEvent e(key, 0);
			data->eventCallback(e);
		}
		else if (action == GLFW_REPEAT)
		{
			// #TODO handle the repeat stuff. Putting just 1 in the meantime.
			KeyPressedEvent e(key, 1);
			data->eventCallback(e);
		}
		else if (action == GLFW_RELEASE)
		{
			if (key == GLFW_KEY_ESCAPE)
			{
				WindowClosedEvent e;
				data->eventCallback(e);
			}
			else
			{
				KeyReleasedEvent e(key);
				data->eventCallback(e);
			}
		}
		else
			ST_LOG_ERROR("Unhandled action for glfwSetKeyCallback");
	});

	glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
	{
		WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));
		ST_ASSERT(data);

		WindowResizedEvent e;
		e.newWidth = width;
		e.newHeight = height;

		data->eventCallback(e);
	});

	glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
	{
		WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));
		ST_ASSERT(data);

		if (action == GLFW_PRESS)
		{
			MouseButtonPressedEvent e;
			e.mouseButtonCode = button;

			data->eventCallback(e);
		}
		else if (action == GLFW_RELEASE)
		{
			MouseButtonReleasedEvent e;
			e.mouseButtonCode = button;

			data->eventCallback(e);
		}
		else
			ST_LOG_ERROR("Unhandled action for glfwSetMouseButtonCallback");
	});

	glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xoffset, double yoffset)
	{
		WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));
		ST_ASSERT(data);

		MouseScrolledEvent e;
		e.offsetX = (float)xoffset;
		e.offsetY = (float)yoffset;

		data->eventCallback(e);
	});

	glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos)
	{
		WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));
		ST_ASSERT(data);

		MouseMovedEvent e;
		e.newPosX = (float)xpos;
		e.newPosY = (float)ypos;

		data->eventCallback(e);
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
