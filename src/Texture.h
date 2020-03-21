#ifndef TEXTURE_H
#define TEXTURE_H


#include <GL/glew.h>

class Tex2D
{
public:
  Tex2D();
  Tex2D(int width, int height, int mipmapLevel, int internalFormat, int format, int wrapS, int wrapT, int minMipMapFilter, int minFilter, int magFilter);
  ~Tex2D();


  /*inline void SetWidth(int width) { if(width > 0) {m_width = width;} }
  inline void SetHeight(int height) { if(height > 0) {m_height = height;} }
  inline void SetData(int &data) { if(!data) {m_data = data;} }
  inline void SetIFormat(int internalFormat) {m_internalFormat = internalFormat;}
  inline void SetFormat(int format) {m_format = format;}
  inline void SetMipmapLevel(int mipmapLevel) {m_mipmapLevel = mipmapLevel;}*/

  void Generate(int width, int height, unsigned char* data);

  void Bind();


// ALLO! :D Look my Set method.. x)
private:
  int m_ID;
  int m_mipmapLevel;
  int m_internalFormat;
  int m_width;
  int m_height;
  int m_format;
  //unsigned char* m_data;
  int m_wrapS;
  int m_wrapT;
  int m_minMipMapFilter;
  int m_minFilter;
  int m_magFilter;


  //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

};


#endif
