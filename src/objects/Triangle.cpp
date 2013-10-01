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

class Triangle : public Object
{
    Vertex* a;
    Vertex* b;
    Vertex* c;
    
public:
    static Triangle* def()
    {
        return new Triangle(
            new Vertex(-0.5, -1.0 / 3.0, 0),
            new Vertex(0.5, -1.0 / 3.0, 0),
            new Vertex(0, 2.0 / 3.0, 0)
        );
    }
    
    Triangle(Vertex* a, Vertex* b, Vertex *c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    
    ~Triangle()
    {
        delete a;
        delete b;
        delete c;
    }
    
    virtual void draw() const
    {
        Object::draw();
        
        glBegin(GL_TRIANGLES);
        
        a->draw();
        b->draw();
        c->draw();
        
        glEnd();
    }
};
