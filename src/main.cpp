#include <iostream>
#include "Window.h"
#include "Core.h"
#include "Log.h"
#include "MeshLoader.h"
#include "Math.h"

int main()
{
  Vec3 test3(1.0f, 4.0f, 40.0f);
  Vec3 anotherTest = test3;
  std::cout << anotherTest.m_X << " " << anotherTest.m_Y << " " << anotherTest.m_Z << "\n";

  std::cout << test3.Length() << " " << test3.Dot(anotherTest) << "\n";
  anotherTest.Normalize();
  std::cout << anotherTest.m_X << " " << anotherTest.m_Y << " " << anotherTest.m_Z << " " << anotherTest.Length() << "\n";

  Vec3 testAgain(test3);
  std::cout << testAgain.m_X << " " << testAgain.m_Y << " " << testAgain.m_Z << "\n";
  if(testAgain == anotherTest)
  {
    std::cout << "salut";
  }
//  Window* window = new Window(800, 600, "Test");
  //Core* core = new Core(window);
  //Log::Info("Hello World!");

  // Singleton MeshLoader
  //Mesh mesh = MeshLoader::Load("object.obj");
  //core->Start();
//  delete core;
  //delete window;

  //std::cout << "\nYou just killed the wrong enemy.\n";
  return 0;
}
