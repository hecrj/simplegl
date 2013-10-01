#hdr
#include <State.h>
#end

class StateMachine
{
    map<unsigned char, State*> states;
    State* current;
    
public:
    StateMachine()
    {
    }
    
    void add(unsigned char key, State* state)
    {
        if(states.empty())
            current = state;
        
        states[key] = state;
    }
    
    void init()
    {
        current->enter();
    }
    
    void trigger(unsigned char keyTrigger)
    {
        map<unsigned char, State*>::const_iterator it = states.find(keyTrigger);
        
        if(it != states.end())
        {
            current->leave();
            current = it->second;
            current->enter();
        }
    }
    
    void printHelp()
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
    
    State* getCurrentState()
    {
        return current;
    }
};
