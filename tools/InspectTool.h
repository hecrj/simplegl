/* 
 * File:   InspectTool.h
 * Author: hector
 */
#include "../Tool.h"

#ifndef INSPECTTOOL_H
#define	INSPECTTOOL_H

class InspectTool : public Tool
{
protected:
    list<Transformable*> mouseRotate;
    int lastX;
    int lastY;
        
public:
    InspectTool();
    virtual ~InspectTool();
    virtual string getDescription() const;
    void addToMouseRotation(Transformable* object);
    void mousePressed(int buttonId, int state, int x, int y);
    void mouseMotion(int x, int y);
    void idle(const vector<bool> &keysDown);
    
private:

};

#endif	/* INSPECTTOOL_H */
