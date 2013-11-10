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
    global = NULL;
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

void StateMachine::setGlobal(State* global)
{
    if(this->global != NULL)
        this->global->leave();
    
    this->global = global;
    
    this->global->enter();
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
    
    if(global != NULL)
        global->keyDown(key, x, y, keysDown);
    
    current->keyDown(key, x, y, keysDown);
}

void StateMachine::keyUp(unsigned char key, int x, int y)
{
    keysDown[key] = false;
    
    if(key == 'h')
        printHelp();
    else
    {
        if(global != NULL)
            global->keyUp(key, x, y, keysDown);
        
        current->keyUp(key, x, y, keysDown);
        trigger(key);
    }
}

void StateMachine::idle()
{
    if(global != NULL)
        global->idle(keysDown);
    
    current->idle(keysDown);
}
