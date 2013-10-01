#hdr
#include <Color.h>
#include <Vertex.h>
#end

#src
#if defined(__APPLE__)
  #include <OpenGL/OpenGl.h>
  #include <GLUT/GLUT.h>
#else
  #include <GL/gl.h>
  #include <GL/freeglut.h>
#endif

#include <math.h>
#end

class Object
{
    Color color;
    Vertex angles;
    
    public:
        virtual ~Object() {}
        
        void rotate(double x, double y, double z)
        {
            angles.x = fmod(angles.x + x, 360);
            angles.y = fmod(angles.y + y, 360);
            angles.z = fmod(angles.z + z, 360);
        }
        
        virtual void draw() const
        {
            glColor3d(color.r, color.g, color.b);
            
            glLoadIdentity();
            glRotated(angles.x, 1, 0, 0);
            glRotated(angles.y, 0, 1, 0);
            glRotated(angles.z, 0, 0, 1);
        }
};
