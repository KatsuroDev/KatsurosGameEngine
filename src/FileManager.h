#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Texture.h"
#include <GL/SOIL.h>

class FileManager
{
public:
  static void LoadTexture(const char* path, Tex2Ddata texData);
  static void LoadShader();
  /*static void LoadObj();*/
private:

};

#endif
