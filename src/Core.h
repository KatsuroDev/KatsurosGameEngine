#ifndef CORE_H
#define CORE_H

#include <iostream>
#include "Window.h"

class Core
{
public:
  Core(Window* window);
  ~Core();

  void Start();
  void Stop();
private:
  Window* m_window;
  bool m_running;
}

#endif
