/** 
 * File:   Player.cpp
 * Author: hector
 */

#include "Player.h"

Player::Player(string filename, Camera* camera) : Model(filename)
{
    this->camera = camera;
    
    camera->rotate(0, 180, 0);
}

void Player::translate(double x, double y, double z)
{
    Model::translate(x, y, z);
    
    camera->translate(x, y, z);
}

void Player::rotate(double x, double y, double z)
{
    Model::rotate(x, -y, z);
    
    camera->rotate(x, y, z);
}

Player::~Player()
{

}
