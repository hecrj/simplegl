/* 
 * File:   Tool.h
 * Author: hector0193
 */
#include "State.h"
#include "Object.h"
#include <list>

using namespace std;


#ifndef TOOL_H
#define	TOOL_H

class Tool : public State
{
protected:
    list<Object*> objects;
    
public:
    Tool();
    virtual ~Tool();
    void add(Object* object);
    void remove(Object* object);
    
private:

};

#endif	/* TOOL_H */

