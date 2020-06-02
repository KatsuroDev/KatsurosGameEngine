#include "RenderingEngine.h"

//#include <GL/glew.h>

void RenderingEngine::Init()
{

    float screenTexCoord[] = {
       // Pos        // Tex Coord
       1.0f,  1.0f,  1.0f, 0.0f, // Top right
       1.0f, -1.0f,  1.0f, 1.0f, // Bottom right
      -1.0f, -1.0f,  0.0f, 1.0f, // Bottom left

      -1.0f, -1.0f,  0.0f, 1.0f, // Bottom left
      -1.0f,  1.0f,  0.0f, 0.0f, // Top left
       1.0f,  1.0f,  1.0f, 0.0f // Top right
    };

    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);

    glBindVertexArray(m_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(screenTexCoord), &screenTexCoord, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2* sizeof(float)));

    glBindVertexArray(0);

    m_Shader = FileManager::LoadShaderFromFile("./res/shaders/shader.vs", "./res/shaders/shader.fs");
    m_Shader.Use();
}

void RenderingEngine::DrawSprite(Tex2D tex, const Vec2 &pos, const Vec2 &scale, float radians)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(1.0f, 0.5f, 0.2f, 1.0f);
  tex.Bind();
  m_Shader.Use();

  Mat4x4 model;
  model.Identity();
  model.Rotate2D(radians);
  model.Scale2D(scale);
  model.Translate2D(pos);

  m_Shader.SetMat4("model", model);

  glBindVertexArray(m_VAO);
  glDrawArrays(GL_TRIANGLES, 0, 6);
}

void RenderingEngine::DrawCamera(const Vec2 &pos, float near, float far)
{
    Mat4x4 view;
    view.Identity();

    Mat4x4 projection;
    projection.Identity();

    projection.Ortho(0.0f, (float)m_Window->GetWidth(), 0.0f, (float)m_Window->GetHeight(), near, far);
    view.Translate2D(Vec2((float)m_Window->GetWidth()/2, (float)m_Window->GetHeight()/2));

    m_Shader.SetMat4("projection", projection);
    m_Shader.SetMat4("view", view);
}
