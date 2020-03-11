#include <iostream>
#include "Window.h"
#include "Core.h"
#include "Log.h"
#include "MeshLoader.h"
#include "JustArenderTest.h"

int main()
{
  /*Window* window = new Window(800, 600, "Test");
  Core* core = new Core(window);
  Log::Info("Hello World!");

  // Singleton MeshLoader
  Mesh mesh = MeshLoader::Load("object.obj");
  core->Start();
  delete core;
  delete window;

  std::cout << "\nYou just killed the wrong enemy.\n";*/
  somethingStatic::staticMain();

  return 0;
}
