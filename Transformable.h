/* 
 * File:   Transformable.h
 * Author: hector
 */
#include "Point.h"
#include "Toggler.h"

#ifndef TRANSFORMABLE_H
#define	TRANSFORMABLE_H

class Transformable : public Toggler
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
    
private:

};

#endif	/* TRANSFORMABLE_H */
