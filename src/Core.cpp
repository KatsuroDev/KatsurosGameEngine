#include "Core.h"

Core::Core(Window* window)
{
  m_window(window);
}

Core::~Core()
{
}

void Core::Start()
{
  m_running = true;
  while(m_running)
  {
    if(glfwWindowShouldClose(m_window))
      m_running = false;
  }
}
