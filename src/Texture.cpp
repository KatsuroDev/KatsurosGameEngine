#include "Texture.h"
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

Tex2d::~Tex2D()
{
}

void Tex2D::Generate(int width, int height, unsigned char* data)
{
  glGenTextures(1, &m_ID);
  glBindTexture(GL_TEXTURE_2D, m_ID);
  glTexImage2D(GL_TEXTURE_2D, m_mipmapLevel, m_internalFormat, m_width, m_height, 0, m_format, GL_UNSIGNED_BYTE, data);

  // Set texture parameter
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_wrapS);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_wrapT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_minFilter);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_magFilter);

  if(m_minMipMapFilter != 0)
  {
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_minMipMapFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_magFilter);
  }
  glBindTexture(GL_TEXTURE_2D, 0);


}

void Tex2D::Bind() const
{
  glBindTexture(GL_TEXTURE_2D, m_ID);
}
