/** 
 * File:   Glut.cpp
 * Author: hector
 */

#include "Engine.h"

#if defined(__APPLE__)
  #include <OpenGL/OpenGl.h>
  #include <GLUT/GLUT.h>
#else
  #include <GL/gl.h>
  #include <GL/freeglut.h>
#endif

Engine::Engine()
{
    activeCamera = NULL;
}

Engine::~Engine()
{

}

void Engine::init(int *argc, char **argv)
{
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
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

void Engine::trigger(unsigned char key)
{
    map<unsigned char, Camera*>::const_iterator it = cameras.find(key);
    
    if(it != cameras.end())
    {
        activeCamera = it->second;
        activeCamera->refocus();
        activeCamera->relocate();
        activeCamera->redisplay();
    }
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
    
    // Focus camera
    activeCamera->refocus();
    
    glutMainLoop();
}

void Engine::render()
{
    activeCamera->render();
}

void Engine::reshape(int width, int height)
{
    activeCamera->reshape(width, height);
}
