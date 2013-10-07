/* 
 * File:   TriangleSelector.h
 * Author: hector
 */

#include "../State.h"
#include "../objects/Triangle.h"
#include "../Window.h"

#ifndef TRIANGLESELECTOR_H
#define	TRIANGLESELECTOR_H

class TriangleSelector : public State
{
    Window* window;   
    Triangle** triangle;
    Point* a;
    Point* b;
    Point* c;
    bool completed;
    
public:
    TriangleSelector(Window* window, Triangle** triangle);
    virtual ~TriangleSelector();
    string getDescription() const;
    void enter();
    void leave();
    void mousePressed(int buttonId, int state, int x, int y);
    
private:

};

#endif	/* TRIANGLESELECTOR_H */
