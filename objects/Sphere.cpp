/* 
 * File:   Sphere.cpp
 * Author: hector0193
 */

#include "Sphere.h"

#if defined(__APPLE__)
  #include <OpenGL/OpenGl.h>
  #include <GLUT/GLUT.h>
#else
  #include <GL/gl.h>
  #include <GL/freeglut.h>
#endif

Sphere::Sphere(double x, double y, double z, double radius) : Object(x, y, z)
{
    this->radius = radius;
}

Sphere::~Sphere() {

}

void Sphere::drawGeom() const
{
    glutWireSphere(radius, 10, 10);
}