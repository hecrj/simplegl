/* 
 * File:   Engine.h
 * Author: hector
 */

#include "Camera.h"
#include "StateMachine.h"
#include <map>
#include <utility>
#include <string>

using namespace std;

#ifndef ENGINE_H
#define	ENGINE_H

class Engine
{
    StateMachine* states;
    Camera* activeCamera;
    map<unsigned char, Camera*> cameras;
    map<unsigned char, pair<Transformable*, string>* > toggles;
    
public:
    Engine();
    virtual ~Engine();
    void init(int *argc, char **argv);
    void configureCallbacks(Viewport* viewport);
    void loop();
    void render();
    void printHelp();
    
    void addCamera(unsigned char key, Camera* camera);
    Camera* getActiveCamera();
    
    void addToggle(unsigned char key, Transformable* toggler, string description);
    
    void reshape(int width, int height);
    void mousePressed(int buttonId, int state, int x, int y);
    void mouseMotion(int x, int y);
    void keyUp(unsigned char key, int x, int y);
    void keyDown(unsigned char key, int x, int y);
    void idle();
    
    static Engine* getActive();
    
private:
    static Engine* ACTIVE;
    
    void triggerCamera(unsigned char key);
    void triggerToggle(unsigned char key);
};

void refresh_callback();
void reshape_callback(int width, int height);
void mousePressed_callback(int buttonId, int state, int x, int y);
void mouseMotion_callback(int x, int y);
void keyUp_callback(unsigned char key, int x, int y);
void keyDown_callback(unsigned char key, int x, int y);
void idle_callback();
void configureStates(StateMachine* states);

#endif	/* ENGINE_H */
