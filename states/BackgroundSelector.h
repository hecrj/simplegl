/* 
 * File:   BackgroundSelector.h
 * Author: hector
 */
#include "../State.h"
#include "../Window.h"

#ifndef BACKGROUNDSELECTOR_H
#define	BACKGROUNDSELECTOR_H

class BackgroundSelector
{
    Window* window;
    
public:
    BackgroundSelector(Window* window);
    virtual ~BackgroundSelector();
    string getDescription() const;
    void mouseMotion(int x, int y);
    
private:
    double getRangedValue(int k, int max);

};

#endif	/* BACKGROUNDSELECTOR_H */
