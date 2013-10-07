/* 
 * File:   Triangle.h
 * Author: hector
 */
#include "../Object.h"
#include "../Vertex.h"

#ifndef TRIANGLE_H
#define	TRIANGLE_H

class Triangle : public Object
{
    Vertex* a;
    Vertex* b;
    Vertex* c;
    
public:
    static Triangle* def();
    Triangle(Vertex* a, Vertex* b, Vertex *c);
    virtual ~Triangle();
    
protected:
    void drawGeom() const;
};

#endif	/* TRIANGLE_H */
