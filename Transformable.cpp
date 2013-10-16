/** 
 * File:   Transformable.cpp
 * Author: hector
 */

#include "Transformable.h"
#include <math.h>

Transformable::Transformable()
{
    position.x = position.y = position.z = 0;
    angles.x = angles.y = angles.z = 0;
}

Transformable::~Transformable()
{

}

void Transformable::rotate(double x, double y, double z)
{
    angles.x = fmod(angles.x + x, 360);
    angles.y = fmod(angles.y + y, 360);
    angles.z = fmod(angles.z + z, 360);
}

void Transformable::translate(double x, double y, double z)
{
    position.x += x;
    position.y += y;
    position.z += z;
}