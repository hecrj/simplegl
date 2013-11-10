#ifndef COLOR_H
#define	COLOR_H

#if defined(__APPLE__)
  #include <OpenGL/OpenGl.h>
  #include <GLUT/GLUT.h>
#else
  #include <GL/gl.h>
  #include <GL/freeglut.h>
#endif

struct Color
{
    GLfloat rgb[3];
    
    Color();
    Color(float r, float g, float b);
    virtual ~Color();
};

#endif	/* COLOR_H */
