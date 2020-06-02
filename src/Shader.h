#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Math.h"

#define VERTEX_SHADER 0
#define FRAGMENT_SHADER 1
#define PROGRAM_SHADER 2


class Shader {
public:
  // The program ID
  unsigned int m_ID;

  // Constructor reads and builds the shader
  Shader() {}

  void Compile(const char* vcode, const char* fcode);
  //void Compile(const std::string &code, int type);
  // Use/Activate the shader
  void Use();
  // Utility uniform functions
  void SetBool(const std::string &name, bool value) const;
  void SetInt(const std::string &name, int value) const;
  void SetFloat(const std::string &name, float value) const;
// ------------------------------------------------------------------------
  //void setVec2(const std::string &name, const glm::vec2 &value) const;
  void SetVec2(const std::string &name, float x, float y) const;
// ------------------------------------------------------------------------
  //void setVec3(const std::string &name, const glm::vec3 &value) const;
  void SetVec3(const std::string &name, float x, float y, float z) const;
// ------------------------------------------------------------------------
  //void setVec4(const std::string &name, const glm::vec4 &value) const;
  void SetVec4(const std::string &name, float x, float y, float z, float w) const;
// ------------------------------------------------------------------------
  //void setMat2(const std::string &name, const glm::mat2 &mat) const;
// ------------------------------------------------------------------------
  void SetMat3(const std::string &name, const Mat3x3 &mat) const;
// ------------------------------------------------------------------------
  void SetMat4(const std::string &name, const Mat4x4 &mat) const;
private:
  void CheckCompileErrors(unsigned int shader, std::string type);
};

#endif
