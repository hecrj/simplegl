/* 
 * File:   StateMachine.h
 * Author: hector
 */

#include "State.h"
#include <map>

using namespace std;

#ifndef STATEMACHINE_H
#define	STATEMACHINE_H

class StateMachine
{
    map<unsigned char, State*> states;
    State* current;
    
public:
    StateMachine();
    virtual ~StateMachine();
    void add(unsigned char key, State* state);
    void init();
    void trigger(unsigned char keyTrigger);
    void printHelp();
    State* getCurrentState();
    
private:

};

#endif	/* STATEMACHINE_H */
