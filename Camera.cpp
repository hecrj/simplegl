/* 
 * File:   Camera.cpp
 * Author: hector0193
 */
#if defined(__APPLE__)
  #include <OpenGL/OpenGl.h>
  #include <GLUT/GLUT.h>
#else
  #include <GL/gl.h>
  #include <GL/freeglut.h>
#endif

#include "Camera.h"
#include <cmath>

Camera::Camera(Viewport* viewport)
{
    this->viewport = viewport;
    position.x = position.y = position.z = 0;
    angleX = angleY = 0;
    radius = sqrt(3);
    distance = 1;
    applied = false;
}

Camera::~Camera()
{
    delete viewport;
}

void Camera::init()
{
    refocus();
}

void Camera::reshape(int width, int height)
{
    viewport->reshape(width, height);
    
    refocus();
}

Viewport* Camera::getViewport()
{
    return viewport;
}

void Camera::focus(double radius, double distance)
{
    this->radius = radius + position.getDistance();
    this->distance = distance;
    
    applied = false;
    refocus();
}

void Camera::locate(double x, double y, double z)
{
    position.x = x;
    position.y = y;
    position.z = z;
    
    applied = false;
}

void Camera::rotate(double x, double y)
{
    angleX = x;
    angleY = y;
    
    applied = false;
}

void Camera::refocus()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    double top, left, right, bottom;
    top = right = radius;
    left = bottom = -radius;
    
    double r = viewport->getAspectRatio();
    
    if(r > 1)
    {
        left *= r;
        right *= r;
    }
    else
    {
        top /= r;
        bottom /= r;
    }
    
    glOrtho(left, right, bottom, top, -distance, distance+2*radius);
    glMatrixMode(GL_MODELVIEW);
}

void Camera::apply() const
{
    if(applied)
        return;
    
    glLoadIdentity();
    
    glTranslated(0, 0, -radius);
    glRotated(angleX, 1, 0, 0);
    glRotated(angleY, 0, 1, 0);
    glTranslated(-position.x, -position.y, -position.z);
}

void Camera::drawContainerSphere() const
{
    glColor3d(0.2, 0.2, 0.2);
    glutWireSphere(radius, 50, 50);
}
