/* 
 * File:   Plane.h
 * Author: hector
 */
#include "../Object.h"
#include "Triangle.h"

#ifndef PLANE_H
#define	PLANE_H

class Plane : public Object
{
    Triangle* triangle1;
    Triangle* triangle2;
    
public:
    Plane(double x, double y, double z, double length);
    virtual ~Plane();
    void setColor(double r, double g, double b);
    
protected:
    void drawGeom() const;
};

#endif	/* PLANE_H */
