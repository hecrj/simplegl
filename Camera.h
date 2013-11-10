/* 
 * File:   Camera.h
 * Author: hector0193
 */

#include "Point.h"
#include "Viewport.h"
#include "Object.h"
#include "Lens.h"
#include "Transformable.h"

#ifndef CAMERA_H
#define	CAMERA_H

class Camera : public Transformable
{
    Viewport* viewport;
    Lens* lens;
    Object* target;
    double radius, distance, zNear, zFar;
    bool located;
    bool focused;
    
public:
    Camera(Viewport* viewport, Lens* lens);
    virtual ~Camera();
    
    Lens* getLens() const;
    Viewport* getViewport();
    
    void setLens(Lens* lens);
    void reshape(int width, int height);
    virtual void translate(double x, double y, double z);
    virtual void rotate(double x, double y, double z);
    void focus(Object* target);
    void focus(Object* target, double distance);
    void render();
    void redisplay();
    void refocus();
    void relocate();
    
private:
    void drawFocusSphere() const;
};

#endif	/* CAMERA_H */

