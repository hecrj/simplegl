/** 
 * File:   ToggleScene.cpp
 * Author: hector
 */

#include "ToggleScene.h"

ToggleScene::ToggleScene(string name, Scene* destination, Scene* toggler)
{
    this->name = name;
    this->destination = destination;
    this->toggler = toggler;
    show = false;
}

ToggleScene::~ToggleScene()
{

}

string ToggleScene::getDescription() const
{
    return "Toggle objects:\n"
           "Hides/Shows from the scene: " + name;
}

bool ToggleScene::isAction() const
{
    return true;
}

void ToggleScene::enter()
{
    if(show)
        destination->addObject(name, toggler);
    else
        destination->removeObject(name);
    
    show = !show;
}
