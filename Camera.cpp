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
#include "Object.h"
#include <cmath>

Camera::Camera(Viewport* viewport)
{
    this->viewport = viewport;
    position.x = position.y = position.z = 0;
    angleX = angleY = 0;
    radius = sqrt(3);
    distance = 1;
    located = false;
}

Camera::~Camera()
{
    delete viewport;
}

void Camera::init()
{
    viewport->init();
    
    // Default clear color
    glClearColor(0, 0, 0, 1);
    
    // Default focus
    refocus();
    
    // Set identity in top modelview
    glLoadIdentity();
    
    // Enable depth
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_DEPTH_TEST);
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

void Camera::focus(Object* target)
{
    focus(target, 0);
}

void Camera::focus(Object* target, double distance)
{
    this->target = target;
    this->radius = target->getContainerSphereRadius() + position.getDistance();
    this->distance = distance;
    
    located = false;
    refocus();
}

void Camera::locate(double x, double y, double z)
{
    position.x = x;
    position.y = y;
    position.z = z;
    
    located = false;
}

void Camera::rotate(double x, double y)
{
    angleX = fmod(angleX + x, 360);
    angleY = fmod(angleY + y, 360);
    
    located = false;
}

void Camera::render()
{
    if(!located)
        relocate();
    
    if(target != NULL)
        target->draw();
    
    drawFocusSphere();
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

void Camera::relocate()
{
    glLoadIdentity();
    
    glTranslated(0, 0, -radius);
    glRotated(angleX, 1, 0, 0);
    glRotated(angleY, 0, 1, 0);
    glTranslated(-position.x, -position.y, -position.z);
    
    located = true;
}

void Camera::drawFocusSphere() const
{
    glColor3d(0.2, 0.2, 0.2);
    glutWireSphere(radius, 50, 50);
}