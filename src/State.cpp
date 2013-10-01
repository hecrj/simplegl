class State
{
public:
    State()
    {
    }
    
    // Description
    virtual string getDescription() const { return "Unknow description"; }
    
    // Actions called when entering/leaving a state
    virtual void enter()
    {
        cout << "-------------------" << endl;
        cout << getDescription() << endl;
    }
    
    virtual void leave() { }
    
    // Default mouse state actions
    virtual void mouseMotion(int x, int y){ }
    virtual void mousePressed(int buttonId, int released, int x, int y) { }
};
