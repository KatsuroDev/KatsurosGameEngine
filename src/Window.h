#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
public:
  Window(int width = 800, int height = 600, const char* title = "");
  ~Window();
private:
  void framebufferSizeCallback(GLFWwindow* window, int width, int height);

  GLFWwindow* m_window;
  int m_width;
  int m_height;
  const char* m_title;
};

#endif
