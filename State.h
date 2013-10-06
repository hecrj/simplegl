/* 
 * File:   State.h
 * Author: hector
 */
#include <string>

using namespace std;

#ifndef STATE_H
#define	STATE_H

class State
{

public:
    State();
    virtual ~State();
    virtual string getDescription() const;
    virtual void enter();
    virtual void leave();
    virtual void mouseMotion(int x, int y);
    virtual void mousePressed(int buttonId, int released, int x, int y);
    
private:

};

#endif	/* STATE_H */
