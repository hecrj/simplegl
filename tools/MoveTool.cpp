/* 
 * File:   MoveTool.cpp
 * Author: hector0193
 */

#include "MoveTool.h"

#if defined(__APPLE__)
  #include <OpenGL/OpenGl.h>
  #include <GLUT/GLUT.h>
#else
  #include <GL/gl.h>
  #include <GL/freeglut.h>
#endif

MoveTool::MoveTool(Window* window)
{
    lastX = lastY = 0;
    this->window = window;
}

MoveTool::~MoveTool()
{
    
}

string MoveTool::getDescription() const
{
    return "MoveTool:\n"
            "Use the mouse to move around some objects.";
}

void MoveTool::mousePressed(int buttonId, int state, int x, int y)
{
    if(buttonId != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
        return;
    
    lastX = x;
    lastY = y;
}

void MoveTool::mouseMotion(int x, int y)
{
    double tX = (lastX - x) / (double)window->getWidth();
    double tY = (lastY - y) / (double)window->getHeight();
    
    lastX = x;
    lastY = y;
    
    list<Object*>::iterator it = objects.begin();
    
    while(it != objects.end())
    {
        (*it)->translate(-tX, tY, 0);
        ++it;
    }
    
    glutPostRedisplay();
}