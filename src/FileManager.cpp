#include "FileManager.h"
#include "Texture.h"

void FileManager::LoadTexture(const char* path, Tex2Ddata texData)
{
  unsigned char *data = SOIL_load_image(path, &texData.width, &texData.height, 0, SOIL_LOAD_AUTO);
  Tex2D texture = Tex2D(texData);
  texture.Generate(texData.width, texData.height, data);
}

void FileManager::LoadShader()
{
  // Load Shader Here
}
