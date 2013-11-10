/* 
 * File:   Glut.h
 * Author: hector
 */

#include "Camera.h"
#include <map>

using namespace std;

#ifndef GLUT_H
#define	GLUT_H

class Engine
{
    Camera* activeCamera;
    map<unsigned char, Camera*> cameras;
    
public:
    Engine();
    virtual ~Engine();
    void init(int *argc, char **argv);
    void loop();
    void render();
    void reshape(int width, int height);
    void addCamera(unsigned char key, Camera* camera);
    Camera* getActiveCamera();
    void trigger(unsigned char key);
    
private:
    
};

#endif	/* GLUT_H */
