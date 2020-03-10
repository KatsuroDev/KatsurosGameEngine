#include "Core.h"
#include "Log.h"

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
  Log::Init();
  while(m_running)
  {
    m_window->WindowSwapBuffers();
    m_window->WindowPollEvents();
    if(m_window->WindowShouldClose())
      this->Stop();
  }
}

void Core::Stop()
{
  m_running = false;
  Log::GetLogFile().close();
}
