#include "FileManager.h"
#include "Texture.h"

void FileManager::LoadTexture(int mipmapLevel, int internalFormat, int format, int wrapS, int wrapT, int minMipMapFilter, int minFilter, int magFilter)
{
  int width, height;
  unsigned char *data = SOIL_load_image("path", &width, &height, 0, SOIL_LOAD_AUTO);
  Tex2D texture();
}

void FileManager::LoadShader()
{

}
