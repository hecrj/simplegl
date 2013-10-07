/** 
 * File:   Plane.cpp
 * Author: hector
 */

#include "Plane.h"

#if defined(__APPLE__)
  #include <OpenGL/OpenGl.h>
  #include <GLUT/GLUT.h>
#else
  #include <GL/gl.h>
  #include <GL/freeglut.h>
#endif

Plane::Plane(double x, double y, double z, double length) : Object(x, y, z)
{
    length /= 2.0;
    triangle1 = new Triangle(
            new Point(-length, 0, -length),
            new Point(-length, 0, length),
            new Point(length, 0, length)
            );
    
    triangle2 = new Triangle(
            new Point(-length, 0, -length),
            new Point(length, 0, -length),
            new Point(length, 0, length)
            );
}

Plane::~Plane()
{
    delete triangle1;
    delete triangle2;
}

void Plane::setColor(double r, double g, double b)
{
    triangle1->setColor(r, g, b);
    triangle2->setColor(r, g, b);
}

void Plane::drawGeom() const
{
    triangle1->draw();
    triangle2->draw();
}
