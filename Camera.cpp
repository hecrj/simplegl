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
#include "lens/OrthogonalLens.h"
#include <cmath>

Camera::Camera(Viewport* viewport)
{
    this->viewport = viewport;
    lens = new OrthogonalLens();
    radius = sqrt(3);
    distance = 1;
    located = false;
}

Camera::~Camera()
{
    delete lens;
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

void Camera::setLens(Lens* lens)
{
    this->lens = lens;
    
    located = false;
    
    refocus();
}

Lens* Camera::getLens() const
{
    return lens;
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

void Camera::translate(double x, double y, double z)
{
    Transformable::translate(x, y, z);
    
    located = false;
}

void Camera::rotate(double x, double y, double z)
{
    Transformable::rotate(x, y, z);
    
    located = false;
}

void Camera::render()
{
    glutSetWindow(viewport->getId());
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    if(!located)
        relocate();
    
    if(target != NULL)
        target->draw();
    
    drawFocusSphere();
    
    glutSwapBuffers();
}

void Camera::redisplay()
{
    glutSetWindow(viewport->getId());
    glutPostRedisplay();
}

void Camera::refocus()
{
    lens->focus(radius, distance, viewport->getAspectRatio());
}

void Camera::relocate()
{
    glLoadIdentity();
    
    lens->locate(radius, distance);
    
    glRotated(angles.x, 1, 0, 0);
    glRotated(angles.y, 0, 1, 0);
    glTranslated(-position.x, -position.y, -position.z);
    
    located = true;
}

void Camera::drawFocusSphere() const
{
    glColor3d(0.2, 0.2, 0.2);
    glutWireSphere(radius, 50, 50);
}
