#include "FileManager.h"
#include "Log.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

Tex2D FileManager::LoadTexture(const char* path, Tex2Ddata texData)
{
  unsigned char *data = SOIL_load_image(path, &texData.width, &texData.height, 0, SOIL_LOAD_AUTO);
  Tex2D texture = Tex2D(texData);
  texture.Generate(data);
  SOIL_free_image_data(data);
  return texture;
}

Shader FileManager::LoadShaderFromFile(const char* vShaderPath, const char* fShaderPath)
{
  std::string vertexCode;
  std::string fragmentCode;
  std::ifstream vShaderFile;
  std::ifstream fShaderFile;
  // Ensure ifstream objects can throw exceptions:
  vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
  fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
  try
  {
    // Open files
    vShaderFile.open(vShaderPath);
    fShaderFile.open(fShaderPath);
    std::stringstream vShaderStream, fShaderStream;
    // Read file's buffer contents into streams
    vShaderStream << vShaderFile.rdbuf();
    fShaderStream << fShaderFile.rdbuf();
    // Close file handlers
    vShaderFile.close();
    fShaderFile.close();
    // Convert stream into string
    vertexCode = vShaderStream.str();
    fragmentCode = fShaderStream.str();
  }
  catch(std::ifstream::failure e)
  {
    std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ\n";
  }
  const char* vShaderCode = vertexCode.c_str();
  const char* fShaderCode = fragmentCode.c_str();

  Shader shader;
  shader.Compile(vShaderCode, fShaderCode);
  // 2.Compile Shaders
  return shader;

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
