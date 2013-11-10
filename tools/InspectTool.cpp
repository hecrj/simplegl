/** 
 * File:   InspectTool.cpp
 * Author: hector
 */

#include "InspectTool.h"

#if defined(__APPLE__)
  #include <OpenGL/OpenGl.h>
  #include <GLUT/GLUT.h>
#else
  #include <GL/gl.h>
  #include <GL/freeglut.h>
#include <list>
#endif

InspectTool::InspectTool()
{

}

InspectTool::~InspectTool()
{

}

string InspectTool::getDescription() const
{
    return "Inspect tool:\n"
           "Press and move the mouse to rotate objects/cameras. You can use W, A, S, D too.";
}

void InspectTool::addToMouseRotation(Transformable* object)
{
    mouseRotate.push_back(object);
}

void InspectTool::mousePressed(int buttonId, int state, int x, int y)
{
    if(buttonId != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
        return;
    
    lastX = x;
    lastY = y;
}

void InspectTool::mouseMotion(int x, int y)
{
    int rX = x - lastX;
    int rY = y - lastY;
    
    lastX = x;
    lastY = y;
    
    list<Transformable*>::iterator it = mouseRotate.begin();
    
    while(it != mouseRotate.end())
    {
        (*it)->rotate(rY, rX, 0);
        ++it;
    }
    
    glutPostRedisplay();
}

void InspectTool::idle(const vector<bool> &keysDown)
{
    double rotateX = 0;
    double rotateY = 0;
    
    if(keysDown['w'])
        rotateX = 5;
    
    if(keysDown['s'])
        rotateX = -5;
    
    if(keysDown['d'])
        rotateY = 5;
    
    if(keysDown['a'])
        rotateY = -5;
    
    list<Transformable*>::iterator it = objects.begin();
    
    while(it != objects.end())
    {
        (*it)->rotate(rotateX, rotateY, 0);
        ++it;
    }
    
    glutPostRedisplay();
}
