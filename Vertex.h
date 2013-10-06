/* 
 * File:   Vertex.h
 * Author: hector
 */

#ifndef VERTEX_H
#define	VERTEX_H

struct Vertex
{
    double x, y, z;

    Vertex();
    Vertex(double x, double y, double z);
    virtual ~Vertex();
    void draw() const;
    
private:

};

#endif	/* VERTEX_H */
