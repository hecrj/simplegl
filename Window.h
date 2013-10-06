/* 
 * File:   Window.h
 * Author: hector
 */
#include "Viewport.h"

#ifndef WINDOW_H
#define	WINDOW_H

class Window
{
    const char* name;
    int width;
    int height;
    Viewport* viewport;
    
public:
    Window(const char* name, int width = 600, int height = 600);
    virtual ~Window();
    void reshape(int width, int height);
    void init();
    Vertex* getViewportVertex(int x, int y);
    int getWidth();
    int getHeight();
    
private:

};

#endif	/* WINDOW_H */
