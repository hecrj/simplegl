#src
#if defined(__APPLE__)
  #include <OpenGL/OpenGl.h>
  #include <GLUT/GLUT.h>
#else
  #include <GL/gl.h>
  #include <GL/freeglut.h>
#endif
#end

struct Vertex
{
    double x, y, z;
    
    Vertex()
    {
        x = y = z = 0;
    }
    
    Vertex(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    
    ~Vertex()
    { }
    
    void draw() const
    {
        glVertex3d(x, y, z);
    }
};
