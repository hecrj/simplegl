/** 
 * File:   StateMachine.cpp
 * Author: hector
 */

#include "StateMachine.h"
#include <iostream>

using namespace std;

StateMachine::StateMachine()
{
    keysDown = vector<bool>(KEYS_SIZE, false);
}

StateMachine::~StateMachine()
{

}

void StateMachine::add(unsigned char key, State* state)
{
    if(states.empty())
        current = state;

    states[key] = state;
}

void StateMachine::init()
{
    current->enter();
}

void StateMachine::trigger(unsigned char keyTrigger)
{
    map<unsigned char, State*>::const_iterator it = states.find(keyTrigger);

    if(it != states.end())
    {
        if(it->second->isAction())
        {
            it->second->enter();
            it->second->leave();
        }
        else
        {
            current->leave();
            current = it->second;
            current->enter();            
        }
    }
}

void StateMachine::printHelp()
{
    cout << "-------------------" << endl;
    cout << "Available actions:" << endl;

    map<unsigned char, State*>::const_iterator it = states.begin();

    while(it != states.end())
    {
        cout << it->second->getDescription() << endl;
        cout << "Press '" << it->first << "' to enable it." << endl;
        cout << endl;

        ++it;
    }
}

State* StateMachine::getCurrentState()
{
    return current;
}

void StateMachine::keyDown(unsigned char key, int x, int y)
{
    keysDown[key] = true;
    
    current->keyDown(key, x, y, keysDown);
}

void StateMachine::keyUp(unsigned char key, int x, int y)
{
    keysDown[key] = false;
    
    if(key == 'h')
        printHelp();
    else
    {
        current->keyUp(key, x, y, keysDown);
        trigger(key);
    }
}

void StateMachine::idle()
{
    current->idle(keysDown);
}
