/* 
 * File:   Camera.h
 * Author: hector0193
 */

#include "Point.h"
#include "Viewport.h"
#include "Object.h"

#ifndef CAMERA_H
#define	CAMERA_H

class Camera
{
    Point position;
    Viewport* viewport;
    Object* target;
    double angleX, angleY;
    double radius, distance, zNear, zFar;
    bool located;
    
public:
    Camera(Viewport* viewport);
    virtual ~Camera();
    
    void init();
    void reshape(int width, int height);
    void locate(double x, double y, double z);
    void rotate(double x, double z);
    Viewport* getViewport();
    void focus(Object* target);
    void focus(Object* target, double distance);
    void render();
    
private:
    void refocus();
    void relocate();
    void drawFocusSphere() const;
};

#endif	/* CAMERA_H */

