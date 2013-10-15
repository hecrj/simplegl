/** 
 * File:   Engine.cpp
 * Author: hector
 */

#include "Engine.h"

#if defined(__APPLE__)
  #include <OpenGL/OpenGl.h>
  #include <GLUT/GLUT.h>
#else
  #include <GL/gl.h>
  #include <GL/freeglut.h>
#endif

Engine::Engine(const char* windowName)
{
    viewport = new Viewport(windowName);
    camera = new Camera(viewport);
    objects = map<string, Object*>();
    x = y = z = 0;
    angleX = angleY = angleZ = 0;
}

Engine::~Engine()
{
    
}

Camera* Engine::getCamera()
{
    return camera;
}

void Engine::init(int *argc, char **argv)
{
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    viewport->init();

    // Default clear color
    glClearColor(0, 0, 0, 1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_DEPTH_TEST);
    
    camera->init();
}

void Engine::focus()
{
    focus(0);
}

void Engine::focus(double distance)
{
    camera->focus(getMaxDimension(), distance);
}

double Engine::getMaxDimension() const
{
    double maxRadius = 0;
    
    // Draw objects
    map<string, Object*>::const_iterator it = objects.begin();

    while(it != objects.end())
    {
        double radius = (*it).second->getContainerSphereRadius();
        
        if(radius > maxRadius)
            maxRadius = radius;
        
        ++it;
    }
    
    return maxRadius;
}

void Engine::loop()
{
    glutMainLoop();
}

void Engine::addObject(string name, Object* object)
{
    objects[name] = object;
}

void Engine::removeObject(string name)
{
    map<string, Object*>::iterator it = objects.find(name);

    if(it == objects.end())
        return;

    delete (*it).second;
    objects.erase(it);
}

void Engine::draw() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    camera->apply();
    
    glPushMatrix();
    
    drawTransformations();
    drawAxis();
    drawGeom();
    
    glPopMatrix();
    
    glutSwapBuffers();
}

void Engine::drawAxis() const
{
    glBegin(GL_LINES);

    glColor3d(1, 0, 0);
    glVertex3d(0, 0, 0);
    glVertex3d(1, 0, 0);

    glColor3d(0, 1, 0);
    glVertex3d(0, 0, 0);
    glVertex3d(0, 1, 0);

    glColor3d(0, 0, 1);
    glVertex3d(0, 0, 0);
    glVertex3d(0, 0, 1);

    glEnd();
}

void Engine::drawGeom() const
{
    // Draw objects
    map<string, Object*>::const_iterator it = objects.begin();

    while(it != objects.end())
    {
        (*it).second->draw();
        ++it;
    }
    
    camera->drawContainerSphere();
}