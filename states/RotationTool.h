/* 
 * File:   RotationTool.h
 * Author: hector0193
 */
#include "../State.h"
#include "../Object.h"
#include <list>

using namespace std;

#ifndef ROTATIONTOOL_H
#define	ROTATIONTOOL_H

class RotationTool : public State
{
    list<Object*> objects;
    
public:
    RotationTool();
    RotationTool(const RotationTool& orig);
    virtual ~RotationTool();
    void add(Object* object);
    void remove(Object* object);
    string getDescription() const;
    void mouseMotion(int x, int y);
    
private:

};

#endif	/* ROTATIONTOOL_H */

