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
        new Vertex(-0.5, -1.0 / 3.0, 0),
        new Vertex(0.5, -1.0 / 3.0, 0),
        new Vertex(0, 2.0 / 3.0, 0)
    );
}

Triangle::Triangle(Vertex* a, Vertex* b, Vertex *c)
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

void Triangle::draw() const
{
    Object::draw();

    glBegin(GL_TRIANGLES);

    a->draw();
    b->draw();
    c->draw();

    glEnd();
}
