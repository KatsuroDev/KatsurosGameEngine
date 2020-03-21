#include "JustArenderTest.h"
#include <iostream>
#include <GL/glew.h>

void somethingStatic::staticMain()
{
  std::cout << "Nothing much";
  int width, height;
  unsigned char *data = SOIL_load_image("image.png", &width, &height, 0, SOIL_LOAD_AUTO);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
  glGenerateMipmap(GL_TEXTURE_2D);
  SOIL_free_image_data(data);
  glBindTexture(GL_TEXTURE_2D);
  GLuint tex_2d = SOIL_load_OGL_texture("img.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
}
