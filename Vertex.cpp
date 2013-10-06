/** 
 * File:   Vertex.cpp
 * Author: hector
 */

#include "Vertex.h"

#if defined(__APPLE__)
  #include <OpenGL/OpenGl.h>
  #include <GLUT/GLUT.h>
#else
  #include <GL/gl.h>
  #include <GL/freeglut.h>
#endif

Vertex::Vertex()
{
    x = y = z = 0;
}

Vertex::Vertex(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vertex::~Vertex()
{ }

void Vertex::draw() const
{
    glVertex3d(x, y, z);
}
