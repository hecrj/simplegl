/* 
 * File:   Engine.h
 * Author: hector
 */

#include <map>
#include <string>
#include "Window.h"
#include "Object.h"

using namespace std;

#ifndef ENGINE_H
#define	ENGINE_H

class Engine
{
public:
    Window* window;
    map<string, Object*> objects;
    
    Engine(const char* windowName);
    virtual ~Engine();
    Window* getWindow();
    void init(int *argc, char **argv);
    void loop();
    void addObject(string name, Object* object);
    void removeObject(string name);
    void draw() const;
private:
    void drawAxis() const;
};

#endif	/* ENGINE_H */

