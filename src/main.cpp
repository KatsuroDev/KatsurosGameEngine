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
    std::cout << "salut\n";
  }

  if(test3 > anotherTest)
  {
    std::cout << "yes\n";
  }

  test3 += anotherTest;
  std::cout << test3.m_X << " " << test3.m_Y << " " << test3.m_Z << "\n";

  test3 *= 15;
  std::cout << test3.m_X << " " << test3.m_Y << " " << test3.m_Z << "\n";
  test3 += 15;
  std::cout << test3.m_X << " " << test3.m_Y << " " << test3.m_Z << "\n";
//Come see in matrix
  Mat3x3 mat;
  mat.Identity();
  std::cout << mat.m_Mat[0][0] << " " << mat.m_Mat[0][1] << " "<< mat.m_Mat[0][2] << "\n" << mat.m_Mat[1][0] << " "<< mat.m_Mat[1][1] << " "<< mat.m_Mat[1][2] << "\n"<< mat.m_Mat[2][0] << " " << mat.m_Mat[2][1] << " "<< mat.m_Mat[2][2] << "\n";
  mat.Rotate(tk::radians(90.0f));
  std::cout << mat.m_Mat[0][0] << " " << mat.m_Mat[0][1] << " "<< mat.m_Mat[0][2] << "\n" << mat.m_Mat[1][0] << " "<< mat.m_Mat[1][1] << " "<< mat.m_Mat[1][2] << "\n"<< mat.m_Mat[2][0] << " " << mat.m_Mat[2][1] << " "<< mat.m_Mat[2][2] << "\n";
  mat.Translate(Vec2(9.0f, 3.0f));
  std::cout << mat.m_Mat[0][0] << " " << mat.m_Mat[0][1] << " "<< mat.m_Mat[0][2] << "\n" << mat.m_Mat[1][0] << " "<< mat.m_Mat[1][1] << " "<< mat.m_Mat[1][2] << "\n"<< mat.m_Mat[2][0] << " " << mat.m_Mat[2][1] << " "<< mat.m_Mat[2][2] << "\n";
  mat.Scale(2.0f, 2.0f);
  std::cout << mat.m_Mat[0][0] << " " << mat.m_Mat[0][1] << " "<< mat.m_Mat[0][2] << "\n" << mat.m_Mat[1][0] << " "<< mat.m_Mat[1][1] << " "<< mat.m_Mat[1][2] << "\n"<< mat.m_Mat[2][0] << " " << mat.m_Mat[2][1] << " "<< mat.m_Mat[2][2] << "\n";
  Mat3x3 mat2;
  mat2.Identity();
  mat2.Translate(15.0f, -20.0f);
  std::cout << mat2.m_Mat[0][0] << " " << mat2.m_Mat[0][1] << " "<< mat2.m_Mat[0][2] << "\n" << mat2.m_Mat[1][0] << " "<< mat2.m_Mat[1][1] << " "<< mat2.m_Mat[1][2] << "\n"<< mat2.m_Mat[2][0] << " " << mat2.m_Mat[2][1] << " "<< mat2.m_Mat[2][2] << "\n";
  mat += mat2;
  std::cout << mat.m_Mat[0][0] << " " << mat.m_Mat[0][1] << " "<< mat.m_Mat[0][2] << "\n" << mat.m_Mat[1][0] << " "<< mat.m_Mat[1][1] << " "<< mat.m_Mat[1][2] << "\n"<< mat.m_Mat[2][0] << " " << mat.m_Mat[2][1] << " "<< mat.m_Mat[2][2] << "\n";

  std::cout << tk::radians(90) << "\n";
  std::cout << 2.0*cos(M_PI/2.0) << "\n";

  /*
  should print:
    1 0 0
    0 1 0
    0 0 1
  */


//  Window* window = new Window(800, 600, "Test");
  //Core* core = new Core(window);
  //Log::Info("Hello World!");

  // Singleton MeshLoader
  //Mesh mesh = MeshLoader::Load("object.obj");
  core->Start();
  delete core;
  delete window;

  std::cout << "\nYou just killed the wrong enemy.\n";
  return 0;
}
