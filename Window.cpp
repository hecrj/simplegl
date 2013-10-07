/** 
 * File:   Window.cpp
 * Author: hector
 */

#include "Window.h"

#if defined(__APPLE__)
  #include <OpenGL/OpenGl.h>
  #include <GLUT/GLUT.h>
#else
  #include <GL/gl.h>
  #include <GL/freeglut.h>
#endif

Window::Window(const char* name, int width, int height)
{
    this->name = name;
    this->width = width;
    this->height = height;

    viewport = new Viewport(width, height);
}

Window::~Window()
{

}

int Window::getWidth()
{
    return width;
}

int Window::getHeight()
{
    return height;
}

void Window::reshape(int width, int height)
{
    this->width = width;
    this->height = height;

    viewport->reshape(width, height);
}

void Window::init()
{
    glutInitWindowSize(width, height);
    glutCreateWindow(name);
}

Point* Window::getViewportVertex(int x, int y)
{
    return viewport->getVertex(x, y);
}
