/** 
 * File:   Teapot.cpp
 * Author: hector
 */

#include "Teapot.h"

#if defined(__APPLE__)
  #include <OpenGL/OpenGl.h>
  #include <GLUT/GLUT.h>
#else
  #include <GL/gl.h>
  #include <GL/freeglut.h>
#endif

Teapot::Teapot(double size)
{
    this->size = size;
}

Teapot::~Teapot()
{

}

void Teapot::drawGeom() const
{
    glutWireTeapot(size);
}
