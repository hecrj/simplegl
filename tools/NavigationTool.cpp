/* 
 * File:   RotationTool.cpp
 * Author: hector0193
 */

#include "NavigationTool.h"

#if defined(__APPLE__)
  #include <OpenGL/OpenGl.h>
  #include <GLUT/GLUT.h>
#else
  #include <GL/gl.h>
  #include <GL/freeglut.h>
#include <list>
#endif

NavigationTool::NavigationTool()
{
    
}


NavigationTool::~NavigationTool()
{
    
}

string NavigationTool::getDescription() const
{
    return "Rotation tool:\n"
            "Press and move the mouse to rotate some objects.";
}

void NavigationTool::mousePressed(int buttonId, int state, int x, int y)
{
    if(buttonId != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
        return;
    
    lastX = x;
    lastY = y;
}

void NavigationTool::mouseMotion(int x, int y)
{
    int rX = x - lastX;
    int rY = y - lastY;
    
    lastX = x;
    lastY = y;
    
    list<Transformable*>::iterator it = objects.begin();
    
    while(it != objects.end())
    {
        (*it)->rotate(rY, rX, 0);
        ++it;
    }
    
    glutPostRedisplay();
}

void NavigationTool::idle(const vector<bool> &keysDown)
{
    double distance = 0;
    double rotateY = 0;
    
    if(keysDown['w'])
        distance = 0.15;
    
    if(keysDown['s'])
        distance = -0.15;
    
    if(keysDown['d'])
        rotateY = 5;
    
    if(keysDown['a'])
        rotateY = -5;
    
    list<Transformable*>::iterator it = objects.begin();
    
    while(it != objects.end())
    {
        (*it)->rotate(0, rotateY, 0);
        (*it)->moveFront(distance);
        ++it;
    }
    
    glutPostRedisplay();
}
