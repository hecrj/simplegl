/* 
 * File:   Teapot.h
 * Author: hector
 */

#include "../Object.h"

#ifndef TEAPOT_H
#define	TEAPOT_H

class Teapot : public Object
{
    double size;
    
public:
    Teapot(double size);
    virtual ~Teapot();

protected:
    void drawGeom() const;

};

#endif	/* TEAPOT_H */
