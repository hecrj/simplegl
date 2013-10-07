/* 
 * File:   Object.h
 * Author: hector
 */

#include "Color.h"
#include "Point.h"

#ifndef OBJECT_H
#define	OBJECT_H

class Object
{
protected:
    Point position;
    Point angles;
    Point scales;
    Color color;
    
public:
    Object();
    Object(double x, double y, double z);
    virtual ~Object();
    virtual void setColor(double r, double g, double b);
    void rotate(double x, double y, double z);
    void translate(double x, double y, double z);
    void scale(double x, double y, double z);
    virtual void draw() const;
    
protected:
    virtual void drawGeom() const = 0;
    virtual void drawTransformations() const;

};

#endif	/* OBJECT_H */
