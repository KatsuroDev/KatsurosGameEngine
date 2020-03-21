#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <iostream>
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

  inline GLFWwindow* GetWindow() { return m_window; }
  inline int GetWidth() { return m_width; }
  inline int GetHeight() { return m_height; }
  inline const char* GetTitle() { return m_title; }
  inline void SetWidth( int width ) { if(width > 0) {m_width = width;} }
  inline void SetHeight( int height ) { if(height > 0 ) {m_height = height;} }
  inline void SetTitle( const char* title ) {m_title = title;}


private:
  GLFWwindow* m_window;
  int m_width;
  int m_height;
  const char* m_title;
};

#endif
