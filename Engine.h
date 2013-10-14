/* 
 * File:   Engine.h
 * Author: hector
 */

#include <map>
#include <string>
#include "Camera.h"
#include "Object.h"

using namespace std;

#ifndef ENGINE_H
#define	ENGINE_H

class Engine : public Object
{
    double x, y, z;
    double angleX, angleY, angleZ;
    Camera* camera;
    map<string, Object*> objects;
    
public:
    Engine(const char* windowName);
    virtual ~Engine();
    Camera* getCamera();
    void focus();
    void focus(double distance);
    void init(int *argc, char **argv);
    void loop();
    void addObject(string name, Object* object);
    void removeObject(string name);
    void draw() const;
    double getMaxDimension() const;
    
private:
    void drawAxis() const;
    void drawGeom() const;
};

#endif	/* ENGINE_H */

