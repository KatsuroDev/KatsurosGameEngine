#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <iostream>
#include <string>
#include <GLFW/glfw3.h>

void framebufferSizeCallback(GLFWwindow* window, int width, int height);

class Window
{
public:
  Window(int width = 800, int height = 600, const char* title = "");
  ~Window();
  bool WindowShouldClose();
  void WindowSwapBuffers();
  void WindowPollEvents();
private:
  GLFWwindow* m_window;
  int m_width;
  int m_height;
  const char* m_title;
};

#endif
