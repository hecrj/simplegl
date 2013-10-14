/* 
 * File:   Camera.h
 * Author: hector0193
 */

#include "Viewport.h"

#ifndef CAMERA_H
#define	CAMERA_H

class Camera
{
    double radius, distance, zNear, zFar;
    Viewport* viewport;
    
public:
    Camera(const char *windowName);
    virtual ~Camera();
    
    void init();
    void reshape(int width, int height);
    Viewport* getViewport();
    void focus(double radius, double distance);
    void drawContainerSphere() const;
    
private:
    void refocus();
};

#endif	/* CAMERA_H */

