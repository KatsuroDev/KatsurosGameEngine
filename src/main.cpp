#include "Log.h"
#include "MeshLoader.h"

int main()
{
    Log::Info("Hello World!");

    // Singleton MeshLoader
    Mesh mesh = MeshLoader::Load("object.obj");
    return 0;
}
