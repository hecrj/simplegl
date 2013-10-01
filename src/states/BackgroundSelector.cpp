#hdr
#include <State.h>
#include <Window.h>
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

class BackgroundSelector : public State
{
    Window* window;
    
public:
    BackgroundSelector(Window* window)
    {
        this->window = window;
    }
    
    string getDescription() const
    {
        return "Background selector:\n"
                "Hold the mouse pressed and move it around the window to select the background color.";
    }
    
    void mouseMotion(int x, int y)
    {
        double red = getRangedValue(x, window->width);
        double blue = getRangedValue(y, window->height);
        
        glClearColor(red, 0, blue, 1);
        glutPostRedisplay();
    }
    
private:
    double getRangedValue(int k, int max)
    {
        if(k < 0)
            k = -k;
        
        int a = k / max;
        
        double ranged = (double)(k % max);;
        
        if(a % 2 != 0)
            ranged = max - ranged;
            
        return ranged / max;
    }
};
