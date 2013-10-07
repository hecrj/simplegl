/* 
 * File:   Viewport.h
 * Author: hector
 */
#include "Point.h"

#ifndef VIEWPORT_H
#define	VIEWPORT_H

class Viewport
{
    int x;
    int y;
    int width;
    int height;
    
public:
    Viewport(int width, int height);
    virtual ~Viewport();
    void reshape(int windowWidth, int windowHeight);
    Point* getVertex(int mx, int my);
    
private:

};

#endif	/* VIEWPORT_H */
