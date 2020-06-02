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
    Core core = Core();
    Log::Info("Hello World!");

    // Singleton MeshLoader
    //Mesh mesh = MeshLoader::Load("object.obj");
    core.Start();

    std::cout << "\nYou died.\n";
    return 0;
}
