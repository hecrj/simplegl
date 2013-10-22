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

void NavigationTool::keyPressed(unsigned char key, int x, int y)
{
    double distance;
    distance = 0;
    
    if(key == 'w')
        distance = 0.2;
    else if(key == 's')
        distance = -0.2;
    
    list<Transformable*>::iterator it = objects.begin();
    
    while(it != objects.end())
    {
        (*it)->moveFront(distance);
        ++it;
    }
    
    glutPostRedisplay();
}
