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
    virtual void draw() const;
    
private:

};

#endif	/* TRIANGLE_H */
