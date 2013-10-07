/* 
 * File:   Tool.cpp
 * Author: hector0193
 */

#include "Tool.h"

Tool::Tool() {

}

Tool::~Tool() {

}

void Tool::add(Object* object)
{
    objects.push_back(object);
}

void Tool::remove(Object* object)
{
    objects.remove(object);
}
