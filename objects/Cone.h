/* 
 * File:   Cone.h
 * Author: hector0193
 */
#include "../Object.h"

#ifndef CONE_H
#define	CONE_H

class Cone : public Object
{
    double base;
    double height;
    
public:
    Cone(double x, double y, double z, double base, double height);
    virtual ~Cone();

protected:
    void drawGeom() const;

};

#endif	/* CONE_H */
