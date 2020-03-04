#include <iostream>
#include "Window.h"

int main()
{
  Window* window = new Window(800, 600, "Test");
  std::cout << "Hello World !";
  return 0;
}
