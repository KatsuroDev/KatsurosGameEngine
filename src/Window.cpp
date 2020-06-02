#include "Window.h"
#include "Log.h"

Window::Window(int width, int height, const char* title):
    m_Width(width),
    m_Height(height),
    m_Title(title)
{

  // Init GLFW and telling we are gonna use the opengl 3.3 version in the core-profile
	glfwInit();


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Only to use on MACOS
#endif


  m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
  if (m_Window == NULL)
  {
    glfwTerminate();
    Log::Critical("GLFW was not able to create the window", 1); // Testing if we got the window right
  }
  glfwMakeContextCurrent(m_Window); // Telling GLFW what current context we'll use.
  glfwSetFramebufferSizeCallback(m_Window, framebufferSizeCallback);

  if (glewInit() != GLEW_OK) // Init GLEW
    Log::Critical("GLEW could not init", 2);
}

Window::~Window()
{
  glfwTerminate();
}

bool Window::WindowShouldClose()
{
  return glfwWindowShouldClose(m_Window);
}

// Use a getter instead ?

void Window::WindowSwapBuffers()
{
  glfwSwapBuffers(m_Window);
}

void Window::WindowPollEvents()
{
  glfwPollEvents();
}

void Window::Update()
{
  glfwGetWindowSize(m_Window, &m_Width, &m_Height);
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}
