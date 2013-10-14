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

Camera::Camera(const char* windowName)
{
    viewport = new Viewport(windowName);
    this->radius = sqrt(3);
    this->distance = 1;
}

Camera::~Camera() {

}

void Camera::init()
{
    viewport->init();
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
    this->radius = radius;
    this->distance = distance;
    
    refocus();
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
    
    glOrtho(left, right, bottom, top, -distance-radius, distance+radius);
    
    glMatrixMode(GL_MODELVIEW);
}

void Camera::drawContainerSphere() const
{
    glColor3d(0.3, 0.3, 0.3);
    glutWireSphere(radius, 50, 50);
}
