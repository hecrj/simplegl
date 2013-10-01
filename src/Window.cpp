#hdr
#include <Viewport.h>
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

struct Window
{
    const char* name;
    int width;
    int height;
    Viewport* viewport;
    
    Window(const char* name, int width = 600, int height = 600)
    {
        this->name = name;
        this->width = width;
        this->height = height;
        
        viewport = new Viewport(width, height);
    }
    
    void reshape(int width, int height)
    {
        this->width = width;
        this->height = height;
        
        viewport->reshape(width, height);
    }
    
    void init()
    {
        glutInitWindowSize(width, height);
        glutCreateWindow(name);
    }
    
    Vertex* getViewportVertex(int x, int y)
    {
        return viewport->getVertex(x, y);
    }
};

