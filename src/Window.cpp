#include "Window.h"

Window::Window(int width, int height, const char* title):
    m_width(width),
    m_height(height),
    m_title(title)
{

  // Init GLFW and telling we are gonna use the opengl 3.3 version in the core-profile
	glfwInit();


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Only to use on MACOS
#endif


  m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
  /*if (window == NULL)
  {
    std::cerr << "[ERROR] : Failed to create GLFW window\n"; // Testing if we got the window right
    glfwTerminate();
    return -1;
  }*/
  glfwMakeContextCurrent(m_window); // Telling GLFW what current context we'll use.
  glfwSetFramebufferSizeCallback(m_window, framebufferSizeCallback);

  if (glewInit() != GLEW_OK) // Init GLEW
    exit(404);
}

bool Window::WindowShouldClose()
{
  return glfwWindowShouldClose(m_window);
}

void Window::WindowSwapBuffers()
{
  glfwSwapBuffers(m_window);
}

void Window::WindowPollEvents()
{
  glfwPollEvents();
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}
