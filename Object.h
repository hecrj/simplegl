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
    Color color;
    Vertex angles;
    
public:
    Object();
    virtual ~Object();
    void rotate(double x, double y, double z);
    virtual void draw() const;
    
private:

};

#endif	/* OBJECT_H */
