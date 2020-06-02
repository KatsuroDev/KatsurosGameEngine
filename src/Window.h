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
  void Update();

  inline GLFWwindow* GetWindow() { return m_Window; }
  inline int GetWidth() { return m_Width; }
  inline int GetHeight() { return m_Height; }
  inline const char* GetTitle() { return m_Title; }
  inline void SetWidth( int width ) { if(width > 0) {m_Width = width;} }
  inline void SetHeight( int height ) { if(height > 0 ) {m_Height = height;} }
  inline void SetTitle( const char* title ) {m_Title = title;}



private:
  GLFWwindow* m_Window;
  int m_Width;
  int m_Height;
  const char* m_Title;
};

#endif
