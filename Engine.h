/* 
 * File:   Glut.h
 * Author: hector
 */

#include "Camera.h"

#ifndef GLUT_H
#define	GLUT_H

class Engine
{
    
public:
    Engine();
    virtual ~Engine();
    void init(int *argc, char **argv);
    void loop();
    
private:
    
};

#endif	/* GLUT_H */
