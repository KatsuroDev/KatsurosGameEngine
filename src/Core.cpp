#include "Core.h"
#include "Log.h"
#include "FileManager.h"
#include "Texture.h"

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
  Tex2Ddata texData;
  texData.internalFormat = GL_RGBA;
  texData.format = GL_RGBA;
  texData.minMipMapFilter = GL_NEAREST_MIPMAP_NEAREST;
  texData.minFilter = GL_NEAREST;
  texData.magFilter = GL_NEAREST;

  FileManager::LoadTexture("./res/tex/image.png", texData);
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
  //logFile.close();
  //delete Log::GetLogFile();
}
