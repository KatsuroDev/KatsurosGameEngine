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
     // Pos        // Tex Coord
     1.0f,  1.0f,  1.0f, 0.0f, // Top right
     1.0f, -1.0f,  1.0f, 1.0f, // Bottom right
    -1.0f, -1.0f,  0.0f, 1.0f, // Bottom left

    -1.0f, -1.0f,  0.0f, 1.0f, // Bottom left
    -1.0f,  1.0f,  0.0f, 0.0f, // Top left
     1.0f,  1.0f,  1.0f, 0.0f // Top right
  };



  Mat3x3 model;
  model.Identity();

  model.Rotate(tk::radians(45.0f));
  model.Translate(Vec2(0.0f, 0.0f));
  model.Scale(0.5f, 0.5f);


  Mat3x3 view;
  view.Identity();
  view.Translate(Vec2(0.5f, 0.0f));

//  Mat3x3 projection; // Orthographic cause no perspective in 2D on Z axis.
  //projection.Identity();
  //projection.Ortho(0.0, m_window->GetWidth(), 0.0, m_window->GetHeight(), 0.1f, 1.0f);
  //projection.Print();
  //projection.Identity();
  //projection.m_Mat[2][2] = 0;

  glm::mat4 proj = glm::mat4(1.0f);
  proj = glm::ortho(0.0f, (float)m_window->GetWidth(), 0.0f, (float)m_window->GetHeight(), 0.1f, 1.0f);
  std::cout << proj[0][0] << " " << proj[0][1] << " "<< proj[0][2] << " " << proj[0][3] << "\n";
  std::cout << proj[1][0] << " " << proj[1][1] << " "<< proj[1][2] << " " << proj[1][3] << "\n";
  std::cout << proj[2][0] << " " << proj[2][1] << " "<< proj[2][2] << " " << proj[2][3] << "\n";
  std::cout << proj[3][0] << " " << proj[3][1] << " "<< proj[3][2] << " " << proj[3][3] << "\n";

  unsigned int projLoc = glGetUniformLocation(shader.m_ID, "projection");
  glUniformMatrix3fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

  unsigned int VBO, VAO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(screenTexCoord), &screenTexCoord, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2* sizeof(float)));

  glBindVertexArray(0);
  Tex2D tex = FileManager::LoadTexture("./res/tex/Image.png", texData);
  while(m_running)
  {

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 0.5f, 0.2f, 1.0f);
    tex.Bind();
    shader.Use();
    //shader.setMat3("projection", projection);
    shader.setMat3("view", view);
    shader.setMat3("model", model);


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
