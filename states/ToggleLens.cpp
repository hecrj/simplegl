/** 
 * File:   ToggleLens.cpp
 * Author: hector
 */

#include <GL/freeglut_std.h>

#include "ToggleLens.h"

ToggleLens::ToggleLens(Camera* camera)
{
    this->camera = camera;
    current = 0;
}

ToggleLens::~ToggleLens()
{

}

bool ToggleLens::isAction() const
{
    return true;
}

string ToggleLens::getDescription() const
{
    return "Toggle lens:\n"
           "Changes the lens of the active camera.";
}

void ToggleLens::addLens(Lens* lens)
{
    this->lens.push_back(lens);
}

void ToggleLens::enter()
{
    current = (current+1) % lens.size();
    
    camera->setLens(lens[current]);
}
