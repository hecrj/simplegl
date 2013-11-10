/* 
 * File:   ToggleScene.h
 * Author: hector
 */
#include "../State.h"
#include "../Scene.h"

#ifndef TOGGLESCENE_H
#define	TOGGLESCENE_H

class ToggleScene : public State
{
    string name;
    Scene* destination;
    Scene* toggler;
    bool show;
    
public:
    ToggleScene(string name, Scene* destination, Scene* scene);
    virtual ~ToggleScene();
    string getDescription() const;
    bool isAction() const;
    void enter();
    
private:

};

#endif	/* TOGGLESCENE_H */
