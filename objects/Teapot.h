/* 
 * File:   Teapot.h
 * Author: hector
 */

#include "../Object.h"

#ifndef TEAPOT_H
#define	TEAPOT_H

class Teapot : Object
{
    double size;
    
public:
    Teapot(double size);
    virtual ~Teapot();
    virtual void draw() const;
private:

};

#endif	/* TEAPOT_H */
