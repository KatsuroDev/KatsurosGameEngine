#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <GL/glew.h>
#include "Texture.h"
#include "Shader.h"
#include <GL/SOIL.h>
#include <iostream>




class FileManager
{
public:
  static Tex2D LoadTexture(const char* path, Tex2Ddata texData);
  //static void LoadShader(const char* vShaderPath, const char* fShaderPath);
  //static void GetShader();
  static Shader LoadShaderFromFile(const char* vShaderPath, const char* fShaderPath);
  //static void LoadObj();
private:
  FileManager() {}

};

#endif
