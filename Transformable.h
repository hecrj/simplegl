/* 
 * File:   Transformable.h
 * Author: hector
 */
#include "Point.h"

#ifndef TRANSFORMABLE_H
#define	TRANSFORMABLE_H

class Transformable
{
protected:
    Point position;
    Point angles;
    Point direction;
    
public:
    Transformable();
    virtual ~Transformable();
    virtual void rotate(double x, double y, double z);
    virtual void translate(double x, double y, double z);
    virtual void moveFront(double distance);
    virtual void toggle() = 0;
private:

};

#endif	/* TRANSFORMABLE_H */
