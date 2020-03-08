#include <iostream>
#include "Window.h"
#include "Core.h"

int main()
{
  Window* window = new Window(800, 600, "Test");
  Core* core = new Core(window);
  core->Start();
  delete core;
  delete window;
  std::cout << "\nYou just killed the wrong enemy.";
  return 0;
}
