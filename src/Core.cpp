#include "FileManager.h"
#include "Core.h"
#include "Log.h"
#include "Texture.h"
#include "Shader.h"
#include <iostream>

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
  texData.format = GL_RGB;
  texData.minMipMapFilter = GL_NEAREST_MIPMAP_NEAREST;
  texData.minFilter = GL_NEAREST;
  texData.magFilter = GL_NEAREST;

  Shader shader = FileManager::LoadShaderFromFile("./res/shaders/shader.vs", "./res/shaders/shader.fs");
  float screenTexCoord[] = {
     1.0f,  1.0f,  0.0f,  1.0f, 0.0f, // Top right
     1.0f, -1.0f,  0.0f,  1.0f, 1.0f, // Bottom right
    -1.0f, -1.0f,  0.0f,  0.0f, 1.0f, // Bottom left

    -1.0f, -1.0f,  0.0f,  0.0f, 1.0f, // Bottom left
    -1.0f,  1.0f,  0.0f,  0.0f, 0.0f, // Top left
     1.0f,  1.0f,  0.0f,  1.0f, 0.0f // Top right
  };

  unsigned int VBO, VAO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(screenTexCoord), &screenTexCoord, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3* sizeof(float)));

  glBindVertexArray(0);
  Tex2D tex = FileManager::LoadTexture("./res/tex/ECS.png", texData);
  while(m_running)
  {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 0.5f, 0.2f, 1.0f);
    tex.Bind();
    shader.Use();

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);

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
