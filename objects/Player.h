/* 
 * File:   Player.h
 * Author: hector
 */
#include "Model.h"
#include "../Camera.h"

#ifndef PLAYER_H
#define	PLAYER_H

class Player : public Model
{
    Camera* camera;
    
public:
    Player(string filename, Camera* camera);
    virtual ~Player();
    void translate(double x, double y, double z);
    void rotate(double x, double y, double z);
private:

};

#endif	/* PLAYER_H */
