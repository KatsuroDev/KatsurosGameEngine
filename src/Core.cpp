#include "FileManager.h"
#include "Core.h"
#include "Log.h"
#include "Texture.h"
#include "Shader.h"
#include "Math.h"
#include <GL/glm/glm.hpp>
#include <GL/glm/gtc/matrix_transform.hpp>
#include <GL/glm/gtc/type_ptr.hpp>
#include <iostream>

Core::Core()
{
  m_Window = new Window(800, 600, "Test");
  m_RenderingEngine = new RenderingEngine(m_Window);
}

Core::~Core()
{
  delete m_Window;
  delete m_RenderingEngine;
}

void Core::Start()
{
  float deltaTime = 0.0f;
  float lastFrame = 0.0f;

  m_Running = true;
  m_RenderingEngine->Init();

  while(m_Running)
  {
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    m_Window->Update();


    m_Window->WindowSwapBuffers();
    m_Window->WindowPollEvents();
    if(m_Window->WindowShouldClose())
      this->Stop();

  }
}

void Core::Stop()
{
  m_Running = false;
}
