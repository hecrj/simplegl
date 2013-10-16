/* 
 * File:   RotationTool.h
 * Author: hector0193
 */
#include "../State.h"
#include "../Camera.h"

using namespace std;

#ifndef ROTATIONTOOL_H
#define	ROTATIONTOOL_H

class RotationTool : public State
{
    Camera* camera;
    int lastY;
    int lastX;
    
public:
    RotationTool(Camera* camera);
    RotationTool(const RotationTool& orig);
    virtual ~RotationTool();
    string getDescription() const;
    void mousePressed(int buttonId, int state, int x, int y);
    void mouseMotion(int x, int y);
    
private:

};

#endif	/* ROTATIONTOOL_H */

