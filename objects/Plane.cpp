/** 
 * File:   Plane.cpp
 * Author: hector
 */

#include "Plane.h"
#include "../utils/math.h"
#include <cmath>

#if defined(__APPLE__)
  #include <OpenGL/OpenGl.h>
  #include <GLUT/GLUT.h>
#else
  #include <GL/gl.h>
  #include <GL/freeglut.h>
#endif

Plane::Plane(double x, double y, double z, double length2) : Object(x, y, z)
{
    length = length2 / 2.0;
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

double Plane::getMaxDimension() const
{
    return max(triangle1->getMaxDimension(), triangle2->getMaxDimension(), 0);
}

double Plane::getContainerSphereRadius() const
{
    double d1 = getMaxDimension();
    double d2 = position.getDistance();
    
    return sqrt(d1*d1 + d2*d2);
}
