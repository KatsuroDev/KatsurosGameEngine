#include "Core.h"

Core::Core(Window* window):
    m_window(window)
{
}

Core::~Core()
{
}

void Core::Start()
{
  m_running = true;
  while(m_running)
  {
    m_window->WindowSwapBuffers();
    m_window->WindowPollEvents();
    if(m_window->WindowShouldClose())
      m_running = false;
  }
}
