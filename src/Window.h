#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <string>
#include <GLFW/glfw3.h>

class Window
{
public:
  Window(int width = 800, int height = 600, std::string title = "");
  ~Window();
private:

  GLFWwindow* m_window;
  int m_width;
  int m_height;
  std::string m_title;
};

#endif
