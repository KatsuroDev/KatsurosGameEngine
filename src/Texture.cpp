#include "Texture.h"
#include <iostream>
#include <GL/glew.h>
/*
int m_mipmapLevel;
int m_internalFormat;
int m_width;
int m_height;
int m_format;
unsigned char* m_data;
int m_wrapS;
int m_wrapT;
int m_minFilter;
int m_magFilter;
*/

/*
Tex2Ddata m_texData;

*/


Tex2D::Tex2D()
{
}
Tex2D::Tex2D(Tex2Ddata texData)
{
  m_texData = texData;
}

Tex2D::~Tex2D()
{
}

void Tex2D::Generate(unsigned char* data)
{
  glGenTextures(1, &m_ID);
  glBindTexture(GL_TEXTURE_2D, m_ID);
  std::cout << m_texData.mipmapLevel << "\n" << m_texData.internalFormat << "\n" << m_texData.width << "\n" << m_texData.height << "\n" << m_texData.format << "\n";
  glTexImage2D(GL_TEXTURE_2D, m_texData.mipmapLevel, m_texData.internalFormat, m_texData.width, m_texData.height, 0, m_texData.format, GL_UNSIGNED_BYTE, data);

  //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1080, 1080, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
  std::cout << "something\n";

  // Set texture parameter
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_texData.wrapS);
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_texData.wrapT);
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_texData.minFilter);
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_texData.magFilter);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_texData.wrapS);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_texData.wrapT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_texData.minFilter);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_texData.magFilter);

  if(m_texData.minMipMapFilter != 0)
  {
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_texData.minMipMapFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_texData.magFilter);
  }
  glBindTexture(GL_TEXTURE_2D, 0);


}

void Tex2D::Bind() const
{
  glBindTexture(GL_TEXTURE_2D, m_ID);
}
