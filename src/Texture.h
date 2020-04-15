#ifndef TEXTURE_H
#define TEXTURE_H


#include <GL/glew.h>
// How do I do struct again ?
struct Tex2Ddata
{
  GLuint width = 0;
  GLuint height = 0;
  GLuint mipmapLevel = 0;
  GLuint internalFormat = 0;
  GLuint format = 0;
  GLuint wrapS = GL_CLAMP_TO_EDGE;
  GLuint wrapT = GL_CLAMP_TO_EDGE;
  GLuint minMipMapFilter = 0;
  GLuint minFilter = 0;
  GLuint magFilter = 0;
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
  GLuint m_ID;
  Tex2Ddata m_texData;


  //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

};


#endif
