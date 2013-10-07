/* 
 * File:   Object.h
 * Author: hector
 */

#include "Color.h"
#include "Vertex.h"

#ifndef OBJECT_H
#define	OBJECT_H

class Object
{
    Vertex position;
    Color color;
    Vertex angles;
    
public:
    Object();
    Object(double x, double y, double z);
    virtual ~Object();
    virtual void setColor(double r, double g, double b);
    void rotate(double x, double y, double z);
    void translate(double x, double y, double z);
    virtual void draw() const;
    void drawTransformations() const;
    
protected:
    virtual void drawGeom() const = 0;

};

#endif	/* OBJECT_H */
