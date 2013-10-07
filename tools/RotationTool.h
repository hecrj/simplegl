/* 
 * File:   RotationTool.h
 * Author: hector0193
 */
#include "../Tool.h"
#include "../Object.h"
#include <list>

using namespace std;

#ifndef ROTATIONTOOL_H
#define	ROTATIONTOOL_H

class RotationTool : public Tool
{
    int lastY;
    int lastX;
    
public:
    RotationTool();
    RotationTool(const RotationTool& orig);
    virtual ~RotationTool();
    string getDescription() const;
    void mousePressed(int buttonId, int state, int x, int y);
    void mouseMotion(int x, int y);
    
private:

};

#endif	/* ROTATIONTOOL_H */

