#hdr
#include <State.h>
#include <Triangle.h>
#end

#src
#if defined(__APPLE__)
  #include <OpenGL/OpenGl.h>
  #include <GLUT/GLUT.h>
#else
  #include <GL/gl.h>
  #include <GL/freeglut.h>
#endif
#end

class TriangleSelector : public State
{
    Window* window;
    
    Triangle** triangle;
    Vertex* a;
    Vertex* b;
    Vertex* c;
    bool completed;
    
public:
    TriangleSelector(Window* window, Triangle** triangle)
    {
        this->window = window;
        this->triangle = triangle;
        
        a = b = c = NULL;
    }
    
    string getDescription() const
    {
        return "Triangle selector:\n"
                "Click to define every vertex of the new triangle.";
    }
    
    void enter()
    {
        a = b = c = NULL;
        
        State::enter();
    }
    
    void leave()
    {
        if(a != NULL)
            delete a;
        
        if(b != NULL)
            delete b;
        
        if(c != NULL)
            delete c;
    }
    
    void mousePressed(int buttonId, int state, int x, int y)
    {
        if(buttonId != GLUT_LEFT_BUTTON || state == GLUT_DOWN)
            return;
        
        Vertex* v = window->getViewportVertex(x, y);
        
        cout << "New vertex defined at: (" << v->x << ", " << v->y << ", " << v->z << ")" << endl;
        
        if(a == NULL)
            a = v;
        else if(b == NULL)
            b = v;
        else
            c = v;
        
        if(c != NULL)
        {
            *triangle = new Triangle(a, b, c);
            a = b = c = NULL;
            
            glutPostRedisplay();
        }
    }
};
