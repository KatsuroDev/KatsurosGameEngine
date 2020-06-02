#ifndef RENDERINGENGINE_H
#define RENDERINGENGINE_H

#include "Math.h"
#include "Texture.h"
#include "Shader.h"
#include "FileManager.h"
#include "Window.h"

class RenderingEngine
{
public:
  RenderingEngine(Window* window) : m_Window(window) {}
  void Init();
  void DrawSprite(/*Sprite*/Tex2D tex, /*Transform*/ const Vec2 &pos, const Vec2 &scale, float radians);
  void DrawCamera(const Vec2 &pos, float near, float far);
private:
  unsigned int m_VBO, m_VAO;
  Shader m_Shader;
  Window* m_Window;

};

#endif
