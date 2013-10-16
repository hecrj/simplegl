/* 
 * File:   RotationTool.cpp
 * Author: hector0193
 */

#include "RotationTool.h"

#if defined(__APPLE__)
  #include <OpenGL/OpenGl.h>
  #include <GLUT/GLUT.h>
#else
  #include <GL/gl.h>
  #include <GL/freeglut.h>
#include <list>
#endif

RotationTool::RotationTool()
{
    
}


RotationTool::~RotationTool()
{
    
}

string RotationTool::getDescription() const
{
    return "Rotation tool:\n"
            "Press and move the mouse to rotate some objects.";
}

void RotationTool::mousePressed(int buttonId, int state, int x, int y)
{
    if(buttonId != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
        return;
    
    lastX = x;
    lastY = y;
}

void RotationTool::mouseMotion(int x, int y)
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
