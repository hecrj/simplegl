/* 
 * File:   Tool.h
 * Author: hector0193
 */
#include "State.h"
#include "Transformable.h"
#include <list>

using namespace std;


#ifndef TOOL_H
#define	TOOL_H

class Tool : public State
{
protected:
    list<Transformable*> objects;
    
public:
    Tool();
    virtual ~Tool();
    void add(Transformable* object);
    void remove(Transformable* object);
    
private:

};

#endif	/* TOOL_H */

