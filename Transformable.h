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
    
public:
    Transformable();
    virtual ~Transformable();
    virtual void rotate(double x, double y, double z);
    virtual void translate(double x, double y, double z);
    
private:

};

#endif	/* TRANSFORMABLE_H */
