/** 
 * File:   StateMachine.cpp
 * Author: hector
 */

#include "StateMachine.h"
#include <iostream>

using namespace std;

StateMachine::StateMachine()
{

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
        current->leave();
        current = it->second;
        current->enter();
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
