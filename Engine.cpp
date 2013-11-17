/** 
 * File:   Engine.cpp
 * Author: hector
 */

#include "Engine.h"
#include <iostream>

#if defined(__APPLE__)
  #include <OpenGL/OpenGl.h>
  #include <GLUT/GLUT.h>
#else
  #include <GL/gl.h>
  #include <GL/freeglut.h>
#endif

Engine* Engine::ACTIVE = NULL;

Engine* Engine::getActive()
{
    return ACTIVE;
}

Engine::Engine()
{
    activeCamera = NULL;
    states = new StateMachine();
    ACTIVE = this;
}

Engine::~Engine()
{
    delete states;
    
    if(ACTIVE == this)
        ACTIVE = NULL;
}

void Engine::init(int *argc, char **argv)
{
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    configureStates(states);
}

void Engine::configureCallbacks(Viewport* viewport)
{
    glutSetWindow(viewport->getId());
    
    glutDisplayFunc(refresh_callback);
    glutReshapeFunc(reshape_callback);
    glutMouseFunc(mousePressed_callback);
    glutMotionFunc(mouseMotion_callback);
    glutKeyboardFunc(keyDown_callback);
    glutKeyboardUpFunc(keyUp_callback);
    glutIdleFunc(idle_callback);
}

void Engine::printHelp()
{
    cout << "Help:" << endl;
    cout << "Use the keys and the mouse to perform actions and change between states and tools." << endl;
    cout << endl;
    
    cout << "Actions:" << endl;
    cout << "    " << "Key " << "    " << "Description" << endl;
    
    map<unsigned char, pair<Transformable*, string>* >::const_iterator it = toggles.begin();
    while(it != toggles.end())
    {
        cout << "    ";
        cout << it->first << "   " << "    ";
        cout << it->second->second << endl;
        
        ++it;
    }
    
    cout << endl;
    
    states->printHelp();
}

void Engine::addCamera(unsigned char key, Camera* camera)
{
    if(activeCamera == NULL)
        activeCamera = camera;
    
    cameras[key] = camera;
}

Camera* Engine::getActiveCamera()
{
    return activeCamera;
}

void Engine::loop()
{
    // Default clear color
    glClearColor(0, 0, 0, 1);
    
    // Set identity in top modelview
    glLoadIdentity();
    
    // Enable depth
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_DEPTH_TEST);
    
    // Enable lights
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    
    GLfloat position[] = { 0, 0, 0, 1 };
    
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    
    // Focus camera
    activeCamera->refocus();
    
    glutMainLoop();
}

void Engine::addToggle(unsigned char key, Transformable* toggler, string description)
{
    toggles[key] = new pair<Transformable*, string>(toggler, description);
}

void Engine::render()
{
    activeCamera->render();
}

void Engine::reshape(int width, int height)
{
    activeCamera->reshape(width, height);
}

void Engine::keyUp(unsigned char key, int x, int y)
{
    if(key == 'h')
        printHelp();
    
    triggerCamera(key);
    triggerToggle(key);
    
    states->keyUp(key, x, y);
}

void Engine::triggerCamera(unsigned char key)
{
    map<unsigned char, Camera*>::const_iterator it = cameras.find(key);
    
    if(it != cameras.end())
    {
        activeCamera = it->second;
        activeCamera->refocus();
        activeCamera->relocate();
        activeCamera->redisplay();
    }
    
    if(key == 'p')
        activeCamera->toggle();
}

void Engine::triggerToggle(unsigned char key)
{
    map<unsigned char, pair<Transformable*, string>* >::const_iterator it = toggles.find(key);
    
    if(it != toggles.end())
        it->second->first->toggle();
}

void Engine::keyDown(unsigned char key, int x, int y)
{
    states->keyDown(key, x, y);
}

void Engine::mouseMotion(int x, int y)
{
    states->mouseMotion(x, y);
}

void Engine::mousePressed(int buttonId, int state, int x, int y)
{
    states->mousePressed(buttonId, state, x, y);
}

void Engine::idle()
{
    states->idle();
}

/** FUNCTIONAL CALLBACKS */
void refresh_callback()
{
    Engine::getActive()->render();
}

void reshape_callback(int width, int height)
{
    Engine::getActive()->reshape(width, height);
}

void mousePressed_callback(int buttonId, int state, int x, int y)
{
    Engine::getActive()->mousePressed(buttonId, state, x, y);
}

void mouseMotion_callback(int x, int y)
{
    Engine::getActive()->mouseMotion(x, y);
}

void keyUp_callback(unsigned char key, int x, int y)
{
    Engine::getActive()->keyUp(key, x, y);
}

void keyDown_callback(unsigned char key, int x, int y)
{
    Engine::getActive()->keyDown(key, x, y);
}

void idle_callback()
{
    Engine::getActive()->idle();
}
