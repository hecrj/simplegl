/* 
 * File:   Tool.cpp
 * Author: hector0193
 */

#include "Tool.h"

Tool::Tool() {

}

Tool::~Tool() {

}

void Tool::add(Transformable* object)
{
    objects.push_back(object);
}

void Tool::remove(Transformable* object)
{
    objects.remove(object);
}
