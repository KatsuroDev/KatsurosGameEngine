#include "FileManager.h"
#include "Log.h"
#include <iostream>

Tex2D FileManager::LoadTexture(const char* path, Tex2Ddata texData)
{
  unsigned char *data = SOIL_load_image(path, &texData.width, &texData.height, 0, SOIL_LOAD_AUTO);
  Tex2D texture = Tex2D(texData);
  texture.Generate(data);
  SOIL_free_image_data(data);
  return texture;
}
/*
void FileManager::LoadShader()
void FileManager::LoadShaderFromFile(const char* path, int type, std::string &code);
{
  // Load Shader Here
  if(type == VERTEX_SHADER)
  {
    //std::string vertexCode;
    std::ifstream vShaderFile;

    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
      vShaderFile.open(path);
      std::stringstream vShaderStream;
      vShaderStream << vShaderFile.rdbuf();
      vShaderFile.close();
      Code = vShaderStream.str();
      shader.Compile(vertexCode, type);
    }
    catch(std::ifstream::failure e)
    {
      Log::Critical("Vertex shader could not be read", 6);
    }

  }
  else if (type == FRAGMENT_SHADER)
  {
    std::string fragmentCode;
    std::ifstream fShaderFile;

    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
      fShaderFile.open(path);
      std::stringstream fShaderStream;
      fShaderStream << fShaderFile.rdbuf();
      fShaderFile.close();
      fragmentCode = fShaderStream.str();
      Shader::Compile(fragmentCode, type);
    }
    catch(std::ifstream::failure e)
    {
      Log::Critical("Fragment shader could not be read", 6)
    }
  }
  else
  {
    Log::Critical("No known shader of this type", 5);
  }
}
*/
