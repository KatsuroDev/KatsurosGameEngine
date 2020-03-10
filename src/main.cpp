#include <iostream>
#include "Window.h"
#include "Core.h"
#include "Log.h"
#include "MeshLoader.h"

int main()
{
  Window* window = new Window(800, 600, "Test");
  Core* core = new Core(window);
  Log::Info("Hello World!");
  Log::Error("J'aime les pénis");
  Log::Critical("TEST POUR  VAGIN", 80085);

  // Singleton MeshLoader
  Mesh mesh = MeshLoader::Load("object.obj");
  core->Start();
  delete core;
  delete window;

  std::cout << "\nYou just killed the wrong enemy.";
  return 0;
}
