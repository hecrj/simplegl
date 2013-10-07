/** 
 * File:   Snowman.cpp
 * Author: hector
 */

#include "Snowman.h"

Snowman::Snowman(double x, double y, double z) : Object(x, y, z)
{
    body = new Sphere(0, 0, 0, 0.4);
    head = new Sphere(0, 0.6, 0, 0.2);
    nose = new Cone(0.1, 0.6, 0, 0.1, 0.2);
    nose->setColor(1, 0.5, 0.3);
    nose->rotate(0, 90, 0);
}

Snowman::~Snowman()
{
    delete body;
    delete head;
    delete nose;
}

void Snowman::drawGeom() const
{
    body->draw();
    head->draw();
    nose->draw();
}
