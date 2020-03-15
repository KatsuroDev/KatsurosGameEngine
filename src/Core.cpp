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
  //std::ofstream logFile;
  m_running = true;
  //Log::Init(logFile);
  while(m_running)
  {
    m_window->WindowPollEvents();
    m_window->WindowSwapBuffers();
    if(m_window->WindowShouldClose())
      this->Stop();
  }
}

void Core::Stop()
{
  m_running = false;
  //logFile.close();
  //delete Log::GetLogFile();
}
