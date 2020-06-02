#include <iostream>
#include "Window.h"
#include "Core.h"
#include "Log.h"
#include "MeshLoader.h"
#include "FileManager.h"
#include "Math.h"
#include <cmath>


int main()
{

<<<<<<< HEAD
=======


>>>>>>> 8804b4aed6ffb707e60826ed3d55d9718291b922
  Window* window = new Window(800, 600, "Test");
  Core* core = new Core(window);
  Log::Info("Hello World!");

  // Singleton MeshLoader
  //Mesh mesh = MeshLoader::Load("object.obj");
  core->Start();
  delete core;
  delete window;

  std::cout << "\nYou just killed the wrong enemy.\n";
  return 0;
}
