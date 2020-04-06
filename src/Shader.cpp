#include "Shader.h"
#include "Log.h"
#include "FileManager.h"

Shader::Shader()
{
  // 1.Retrieve the vertex/fragment source code from file path
  /*std::string vertexCode;
  std::string fragmentCode;
  std::ifstream vShaderFile;
  std::ifstream fShaderFile;
  // Ensure ifstream objects can throw exceptions:
  vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
  fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
  try
  {
    // Open files
    vShaderFile.open(vertexPath);
    fShaderFile.open(fragmentPath);
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

  // 2.Compile Shaders
  unsigned int vertex, fragment;

  // Vertex Shader
  vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &vShaderCode, NULL);
  glCompileShader(vertex);
  // Print compile errors if any
  CheckCompileErrors(vertex, "VERTEX");

  // Fragment Shader
  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &fShaderCode, NULL);
  glCompileShader(fragment);
  // Print compile errors if any
  CheckCompileErrors(fragment, "FRAGMENT");

  // Shader Program
  ID = glCreateProgram();
  glAttachShader(ID, vertex);
  glAttachShader(ID, fragment);
  glLinkProgram(ID);
  // Print linking errors if any
  CheckCompileErrors(ID, "PROGRAM");

  // Delete the shaders as they're linked into our program now and no longer necessary
  glDeleteShader(vertex);
  glDeleteShader(fragment);
*/
}

void Shader::Compile(const char* vcode, const char* fcode)
{
  unsigned int vertex, fragment;

  vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &vcode, NULL);
  glCompileShader(vertex);
  CheckCompileErrors(vertex, "VERTEX");

  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &fcode, NULL);
  glCompileShader(fragment);
  CheckCompileErrors(fragment, "FRAGMENT");

  m_ID = glCreateProgram();
  glAttachShader(m_ID, vertex);
  glAttachShader(m_ID, fragment);
  glLinkProgram(m_ID);
    // Print linking errors if any
  CheckCompileErrors(m_ID, "PROGRAM");

    // Delete the shaders as they're linked into our program now and no longer necessary
  glDeleteShader(vertex);
  glDeleteShader(fragment);
}

void Shader::Use()
{
  glUseProgram(m_ID);
}

void Shader::SetBool(const std::string &name, bool value) const
{
  glUniform1i(glGetUniformLocation(m_ID, name.c_str()), (int)value);
}
void Shader::SetInt(const std::string &name, int value) const
{
  glUniform1i(glGetUniformLocation(m_ID, name.c_str()), value);
}
void Shader::SetFloat(const std::string &name, float value) const
{
  glUniform1f(glGetUniformLocation(m_ID, name.c_str()), value);
}

/*void Shader::setVec2(const std::string &name, const glm::vec2 &value) const
{
    glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}*/
void Shader::setVec2(const std::string &name, float x, float y) const
{
    glUniform2f(glGetUniformLocation(m_ID, name.c_str()), x, y);
}
// ------------------------------------------------------------------------
/*void Shader::setVec3(const std::string &name, const glm::vec3 &value) const
{
    glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}*/
void Shader::setVec3(const std::string &name, float x, float y, float z) const
{
    glUniform3f(glGetUniformLocation(m_ID, name.c_str()), x, y, z);
}
// ------------------------------------------------------------------------
/*void Shader::setVec4(const std::string &name, const glm::vec4 &value) const
{
    glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}*/
void Shader::setVec4(const std::string &name, float x, float y, float z, float w) const
{
    glUniform4f(glGetUniformLocation(m_ID, name.c_str()), x, y, z, w);
}
// ------------------------------------------------------------------------
/*void Shader::setMat2(const std::string &name, const glm::mat2 &mat) const
{
    glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
// ------------------------------------------------------------------------
void Shader::setMat3(const std::string &name, const glm::mat3 &mat) const
{
    glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
// ------------------------------------------------------------------------
void Shader::setMat4(const std::string &name, const glm::mat4 &mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
*/
void Shader::CheckCompileErrors(unsigned int shader, std::string type)
{
  int success;
  char infoLog[1024];
  if(type != "PROGRAM")
  {
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
      glGetShaderInfoLog(shader, 1024, NULL, infoLog);
      //Log::Critical("Shader Compilation error of type"+type+" : " +infoLog, 3);
      std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n\t" << infoLog << "\n\n";
    }
  }
  else
  {
    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    {
      if(!success)
      {
        glGetProgramInfoLog(shader, 1024, NULL, infoLog);
        //Log::Critical("Shader Linking error of type"+type+" : " +infoLog, 4);
        std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n\t" << infoLog << "\n\n";
      }
    }
  }
}
