/* 
 * File:   ToggleLens.h
 * Author: hector
 */
#include "../State.h"
#include "../Camera.h"

#ifndef TOGGLELENS_H
#define	TOGGLELENS_H

class ToggleLens : public State
{
    Camera* camera;
    vector<Lens*> lens;
    int current;
    
public:
    ToggleLens(Camera* camera);
    virtual ~ToggleLens();
    string getDescription() const;
    bool isAction() const;
    void enter();
    void addLens(Lens* lens);
    
private:

};

#endif	/* TOGGLELENS_H */
