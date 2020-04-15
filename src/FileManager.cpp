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
  return shader;

}
