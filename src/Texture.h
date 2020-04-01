#ifndef TEXTURE_H
#define TEXTURE_H


#include <GL/glew.h>
// How do I do struct again ?
struct Tex2Ddata
{
  int width = 0;
  int height = 0;
  int mipmapLevel = 0;
  int internalFormat = 0;
  int format = 0;
  int wrapS = GL_CLAMP_TO_EDGE;
  int wrapT = GL_CLAMP_TO_EDGE;
  int minMipMapFilter = 0;
  int minFilter = 0;
  int magFilter = 0;
};

class Tex2D
{
public:
  Tex2D();
  Tex2D(Tex2Ddata texData);
  ~Tex2D();


  /*inline void SetWidth(int width) { if(width > 0) {m_width = width;} }
  inline void SetHeight(int height) { if(height > 0) {m_height = height;} }
  inline void SetData(int &data) { if(!data) {m_data = data;} }
  inline void SetIFormat(int internalFormat) {m_internalFormat = internalFormat;}
  inline void SetFormat(int format) {m_format = format;}
  inline void SetMipmapLevel(int mipmapLevel) {m_mipmapLevel = mipmapLevel;}*/

  void Generate(unsigned char* data);

  void Bind() const;


private:
  int m_ID;
  Tex2Ddata m_texData;


  //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

};


#endif
