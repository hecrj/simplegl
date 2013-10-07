/* 
 * File:   RotationTool.cpp
 * Author: hector0193
 */

#include "RotationTool.h"

RotationTool::RotationTool()
{
    
}


RotationTool::~RotationTool()
{
    
}

void RotationTool::add(Object* object)
{
    objects.push_back(object);
}

void RotationTool::remove(Object* object)
{
    objects.remove(object);
}

string RotationTool::getDescription() const
{
    return "Rotation tool:\n"
            "Press and move the mouse to rotate some objects.";
}

void RotationTool::mouseMotion(int x, int y)
{
    list<Object*>::iterator it = objects.begin();
    
    while(it != objects.end())
        (*it)->rotate(x, y, 0);
}
