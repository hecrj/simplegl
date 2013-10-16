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
    
}

Engine::~Engine()
{

}

void Engine::init(int *argc, char **argv)
{
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
}

void Engine::loop()
{
    glutMainLoop();
}
