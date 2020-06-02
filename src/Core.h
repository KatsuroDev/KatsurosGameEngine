#ifndef CORE_H
#define CORE_H

#include "Window.h"
#include "RenderingEngine.h"

class Core
{
public:
  Core();
  ~Core();

  void Start();
  void Stop();
private:
  Window* m_Window;
  RenderingEngine* m_RenderingEngine;
  bool m_Running;
};

#endif
