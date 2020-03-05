#include <iostream>
#include "Window.h"
#include "Core.h"

int main()
{

  Window* window = new Window(800, 600, "Test");
  Core* core = new Core(window);
  core->Start();
  std::cout << "Hello World !";
  return 0;
}
