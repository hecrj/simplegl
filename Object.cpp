/** 
 * File:   Object.cpp
 * Author: hector
 */

#include "Object.h"

#if defined(__APPLE__)
  #include <OpenGL/OpenGl.h>
  #include <GLUT/GLUT.h>
#else
  #include <GL/gl.h>
  #include <GL/freeglut.h>
#endif

#include <math.h>
#include "utils/math.h"

Object::Object()
{
    position.x = position.y = position.z = 0;
    scales.x = scales.y = scales.z = 1;
}

Object::Object(double x, double y, double z)
{
    position.x = x;
    position.y = y;
    position.z = z;
    
    scales.x = scales.y = scales.z = 1;
}

Object::~Object()
{

}

void Object::setColor(double r, double g, double b)
{
    color.r = r;
    color.g = g;
    color.b = b;
}

void Object::rotate(double x, double y, double z)
{
    angles.x = fmod(angles.x + x, 360);
    angles.y = fmod(angles.y + y, 360);
    angles.z = fmod(angles.z + z, 360);
}

void Object::translate(double x, double y, double z)
{
    position.x += x;
    position.y += y;
    position.z += z;
}

void Object::scale(double x, double y, double z)
{
    scales.x = x;
    scales.y = y;
    scales.z = z;
}

void Object::draw() const
{
    glPushMatrix();
    
    drawTransformations();
    drawGeom();
    
    glPopMatrix();
}

void Object::drawTransformations() const
{
    glColor3d(color.r, color.g, color.b);
    glTranslated(position.x, position.y, position.z);
    glRotated(angles.x, 1, 0, 0);
    glRotated(angles.y, 0, 1, 0);
    glRotated(angles.z, 0, 0, 1);
    glScaled(scales.x, scales.y, scales.z);
}

double Object::getContainerSphereRadius() const
{
    double maxDim = getMaxDimension();
    
    maxDim = max(maxDim * scales.x, maxDim * scales.y, maxDim * scales.z);
    
    return maxDim + position.getDistance();
}
