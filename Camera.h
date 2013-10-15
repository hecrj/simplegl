/* 
 * File:   Camera.h
 * Author: hector0193
 */

#include "Point.h"
#include "Viewport.h"

#ifndef CAMERA_H
#define	CAMERA_H

class Camera
{
    Point position;
    double angleX, angleY;
    double radius, distance, zNear, zFar;
    Viewport* viewport;
    bool applied;
    
public:
    Camera(Viewport* viewport);
    virtual ~Camera();
    
    void init();
    void reshape(int width, int height);
    void locate(double x, double y, double z);
    void rotate(double x, double z);
    Viewport* getViewport();
    void focus(double radius, double distance);
    void apply() const;
    void drawContainerSphere() const;
    
private:
    void refocus();
};

#endif	/* CAMERA_H */

