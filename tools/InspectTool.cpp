/** 
 * File:   InspectTool.cpp
 * Author: hector
 */

#include "InspectTool.h"

InspectTool::InspectTool(Engine* engine)
{
    this->engine = engine;
}

InspectTool::~InspectTool()
{

}

string InspectTool::getDescription() const
{
    return "Inspect tool:\n"
           "Press and move the mouse to rotate objects/cameras. You can use W, A, S, D too.";
}

void InspectTool::mouseMotion(int x, int y)
{
    int rX = x - lastX;
    int rY = y - lastY;
    
    lastX = x;
    lastY = y;
    
    engine->getActiveCamera()->rotate(rY, rX, 0);
    engine->getActiveCamera()->redisplay();
}
