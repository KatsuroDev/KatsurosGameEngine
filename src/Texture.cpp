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

Tex2D::Tex2D() :
  m_mipmapLevel(0), m_internalFormat(GL_RGB), m_width(0), m_height(0), m_format(GL_RGBA), m_wrapS(GL_CLAMP_TO_EDGE), m_wrapT(GL_CLAMP_TO_EDGE), m_minFilter(GL_NEAREST), m_magFilter(GL_NEAREST), m_minMipMapFilter(0)
{

}
Tex2D::Tex2D( int width, int height, int mipmapLevel, int internalFormat, int format, int wrapS, int wrapT, int minFilter, int magFilter, int minMipMapFilter) :
  m_width(width), m_height(height), m_mipmapLevel(mipmapLevel), m_internalFormat(internalFormat), m_format(format), m_wrapS(wrapS), m_wrapT(wrapT), m_minFilter(minFilter), m_magFilter(magFilter), m_minMipMapFilter(m_minMipMapFilter);
{

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
