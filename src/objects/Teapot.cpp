#hdr
#include <Object.h>
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

class Teapot : public Object
{
    double size;
    
public:
    Teapot(double size)
    {
        this->size = size;
    }
    
    virtual void draw() const
    {
        Object::draw();
        
        glutWireTeapot(size);
    }
};
