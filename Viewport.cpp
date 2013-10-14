/** 
 * File:   Window.cpp
 * Author: hector
 */

#include "Viewport.h"

#if defined(__APPLE__)
  #include <OpenGL/OpenGl.h>
  #include <GLUT/GLUT.h>
#else
  #include <GL/gl.h>
  #include <GL/freeglut.h>
#endif

Viewport::Viewport(const char* name, int width, int height)
{
    this->name = name;
    this->width = width;
    this->height = height;
}

Viewport::~Viewport()
{

}

int Viewport::getWidth()
{
    return width;
}

int Viewport::getHeight()
{
    return height;
}

void Viewport::reshape(int width, int height)
{
    this->width = width;
    this->height = height;

    glViewport(0, 0, width, height);
}

double Viewport::getAspectRatio()
{
    return width / (double) height;
}

void Viewport::init()
{
    glutInitWindowSize(width, height);
    glutCreateWindow(name);
}

Point* Viewport::getViewportVertex(int x, int y)
{
    return new Point(0, 0, 0); // TODO Reimplement!
}
