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
    window = new Window(windowName);
    objects = map<string, Object*>();
    x = y = z = 0;
    angleX = angleY = angleZ = 0;
}

Engine::~Engine()
{
    
}

Window* Engine::getWindow()
{
    return window;
}

void Engine::init(int *argc, char **argv)
{
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    window->init();

    // Default clear color
    glClearColor(0, 0, 0, 1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_DEPTH_TEST);
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
    
    glLoadIdentity();
    
    drawTransformations();
    drawAxis();
    drawGeom();

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
}