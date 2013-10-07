/** 
 * File:   Triangle.cpp
 * Author: hector
 */

#include "Triangle.h"

#if defined(__APPLE__)
  #include <OpenGL/OpenGl.h>
  #include <GLUT/GLUT.h>
#else
  #include <GL/gl.h>
  #include <GL/freeglut.h>
#endif

Triangle* Triangle::def()
{
    return new Triangle(
        new Point(-0.5, -1.0 / 3.0, 0),
        new Point(0.5, -1.0 / 3.0, 0),
        new Point(0, 2.0 / 3.0, 0)
    );
}

Triangle::Triangle(Point* a, Point* b, Point *c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

Triangle::~Triangle()
{
    delete a;
    delete b;
    delete c;
}

void Triangle::drawGeom() const
{
    glBegin(GL_TRIANGLES);

    a->draw();
    b->draw();
    c->draw();

    glEnd();
}
