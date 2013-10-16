/* 
 * File:   RotationTool.h
 * Author: hector0193
 */
#include "../Tool.h"
#include "../Camera.h"

using namespace std;

#ifndef ROTATIONTOOL_H
#define	ROTATIONTOOL_H

class RotationTool : public Tool
{
    int lastY;
    int lastX;
    
public:
    RotationTool();
    virtual ~RotationTool();
    string getDescription() const;
    void mousePressed(int buttonId, int state, int x, int y);
    void mouseMotion(int x, int y);
    
private:

};

#endif	/* ROTATIONTOOL_H */

