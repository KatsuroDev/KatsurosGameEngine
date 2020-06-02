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
Tex2Ddata m_TexData;

*/


Tex2D::Tex2D()
{
}
Tex2D::Tex2D(Tex2Ddata texData)
{
  m_TexData = texData;
}

Tex2D::~Tex2D()
{
}

void Tex2D::Generate(unsigned char* data)
{
  glGenTextures(1, &m_ID);
  glBindTexture(GL_TEXTURE_2D, m_ID);
  std::cout << m_TexData.mipmapLevel << "\n" << m_TexData.internalFormat << "\n" << m_TexData.width << "\n" << m_TexData.height << "\n" << m_TexData.format << "\n";
  glTexImage2D(GL_TEXTURE_2D, m_TexData.mipmapLevel, m_TexData.internalFormat, m_TexData.width, m_TexData.height, 0, m_TexData.format, GL_UNSIGNED_BYTE, data);

  //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1080, 1080, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
  std::cout << "something\n";

  // Set texture parameter
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_TexData.wrapS);
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_TexData.wrapT);
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_TexData.minFilter);
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_TexData.magFilter);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_TexData.wrapS);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_TexData.wrapT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_TexData.minFilter);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_TexData.magFilter);

  if(m_TexData.minMipMapFilter != 0)
  {
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_TexData.minMipMapFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_TexData.magFilter);
  }
  glBindTexture(GL_TEXTURE_2D, 0);


}

void Tex2D::Bind() const
{
  glBindTexture(GL_TEXTURE_2D, m_ID);
}
