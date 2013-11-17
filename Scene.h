/* 
 * File:   Engine.h
 * Author: hector
 */

#include <map>
#include <string>
#include "Camera.h"
#include "Object.h"

using namespace std;

#ifndef SCENE_H
#define	SCENE_H

class Scene : public Object
{
    map<string, Object*> objects;
    
public:
    Scene();
    virtual ~Scene();
    void addObject(string name, Object* object);
    void removeObject(string name);
    double getMaxDimension() const;
    
protected:
    virtual void drawGeom() const;
    
private:
    void drawAxis() const;
};

#endif	/* ENGINE_H */

