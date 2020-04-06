#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Texture.h"
#include "Shader.h"
#include <GL/SOIL.h>
#include <iostream>



class FileManager
{
public:
  static Tex2D LoadTexture(const char* path, Tex2Ddata texData);
  //static void LoadShader(const char* path, int type);
  //static void LoadObj();
private:
  FileManager() {}

};

#endif
