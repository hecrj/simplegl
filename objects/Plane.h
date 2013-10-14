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
    double length;
    Triangle* triangle1;
    Triangle* triangle2;
    
public:
    Plane(double x, double y, double z, double length);
    virtual ~Plane();
    void setColor(double r, double g, double b);
    double getMaxDimension() const;
    
protected:
    void drawGeom() const;
};

#endif	/* PLANE_H */
