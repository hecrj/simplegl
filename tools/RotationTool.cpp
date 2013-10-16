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
#endif

RotationTool::RotationTool(Camera* camera)
{
    this->camera = camera;
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
    int rX = lastX - x;
    int rY = lastY - y;
    
    lastX = x;
    lastY = y;
    
    camera->rotate(-rY, -rX);
    
    glutPostRedisplay();
}
