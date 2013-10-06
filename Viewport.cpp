/** 
 * File:   Viewport.cpp
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

Viewport::Viewport(int width, int height)
{
    x = 0;
    y = 0;
    this->width = width;
    this->height = height;
}

Viewport::~Viewport()
{

}

void Viewport::reshape(int windowWidth, int windowHeight)
{
    x = y = 0;
    width = windowWidth;
    height = windowHeight;

    if(width > height)
    {
        x = (width - height) / 2;
        width = height;
    }
    else
    {
        y = (height - width) / 2;
        height = width;
    }

    glViewport(x, y, width, height);
}

Vertex* Viewport::getVertex(int mx, int my)
{
    mx = mx - x;
    my = (height - my) + y;

    double vx = ((double)mx / width) * 2 - 1;
    double vy = ((double)my / height) * 2 - 1;

    return new Vertex(vx, vy, 0);
}
