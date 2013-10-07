/* 
 * File:   Triangle.h
 * Author: hector
 */
#include "../Object.h"
#include "../Point.h"

#ifndef TRIANGLE_H
#define	TRIANGLE_H

class Triangle : public Object
{
    Point* a;
    Point* b;
    Point* c;
    
public:
    static Triangle* def();
    Triangle(Point* a, Point* b, Point *c);
    virtual ~Triangle();
    
protected:
    void drawGeom() const;
};

#endif	/* TRIANGLE_H */
