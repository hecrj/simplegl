/** 
 * File:   Model.cpp
 * Author: hector
 */

#include "Model.h"
#include "../utils/math.h"

#if defined(__APPLE__)
  #include <OpenGL/OpenGl.h>
  #include <GLUT/GLUT.h>
#else
  #include <GL/gl.h>
  #include <GL/freeglut.h>
#endif

Model::Model()
{
    
}

Model::~Model()
{

}

inline void Model::updateBoundingBox(double x, double y, double z)
{
    if(x < bottom.x) bottom.x = x;
    if(x > top.x)    top.x = x;
    
    if(y < bottom.y) bottom.y = y;
    if(y > top.y)    top.y = y;
    
    if(z < bottom.z) bottom.z = z;
    if(z > top.z)    top.z = z;
}

void Model::load(string filename)
{
    ModelLoader::load(filename);
    
    top.x = bottom.x = _vertices[0];
    top.y = bottom.y = _vertices[1];
    top.z = bottom.z = _vertices[2];
    
    for(int i = 0; i < _vertices.size(); i += 3)
        updateBoundingBox(_vertices[i], _vertices[i+1], _vertices[i+2]);
    
    width = top.x - bottom.x;
    height = top.y - bottom.y;
    depth = top.z - bottom.z;
    
    center.x = top.x - width / 2.0;
    center.y = top.y - height / 2.0;
    center.z = top.z - depth / 2.0;
    
    rightFrontBottom.x = top.x - center.x;
    rightFrontBottom.y = bottom.y - center.y;
    rightFrontBottom.z = top.z - center.z;
    
    double scaleFactor = 2.0;
    
    if(width > height)
    {
        if(width > depth) scaleFactor /= width;
        else scaleFactor /= depth;
    }
    else
    {
        if(height > depth) scaleFactor /= height;
        else scaleFactor /= depth;
    }
    
    scale(scaleFactor, scaleFactor, scaleFactor);
}

double Model::getWidth() const
{
    return width;
}

double Model::getHeight() const
{
    return height;
}

double Model::getDepth() const
{
    return depth;
}

double Model::getRFBX() const
{
    return rightFrontBottom.x * scales.x;
}

double Model::getRFBY() const
{
    return rightFrontBottom.y * scales.y;
}

double Model::getRFBZ() const
{
    return rightFrontBottom.z * scales.z;
}

double Model::getMaxDimension() const
{
    return max(width / 2, height / 2, depth / 2);
}

void Model::drawTransformations() const
{   
    Object::drawTransformations();
    
    glTranslated(-center.x, -center.y, -center.z);
}

void Model::drawGeom() const
{
    glBegin(GL_TRIANGLES);
    
    for(int i = 0; i < _faces.size(); ++i)
    {
        glColor4fv(Materials[_faces[i].mat].diffuse);
        glNormal3dv(_faces[i].normalC);
        
        for(int j = 0; j < 3; ++j)
            glVertex3dv(&_vertices[_faces[i].v[j]]);
    }
    
    glEnd();
    
    drawBoundingBox();
}

void Model::drawBoundingBox() const
{
    glColor3d(0.7, 0.7, 0.7);

    drawBase(0);
    drawBase(height);
}

void Model::drawBase(double height) const
{
    glBegin(GL_LINE_STRIP);
    
    glVertex3d(bottom.x, bottom.y + height, bottom.z);
    glVertex3d(bottom.x + width, bottom.y + height, bottom.z);
    
    glVertex3d(bottom.x, bottom.y + height, bottom.z);
    glVertex3d(bottom.x, bottom.y + height, bottom.z + depth);
    
    glVertex3d(bottom.x + width, bottom.y + height, bottom.z);
    glVertex3d(bottom.x + width, bottom.y + height, bottom.z + depth);
    
    glVertex3d(bottom.x, bottom.y + height, bottom.z + depth);
    glVertex3d(bottom.x + width, bottom.y + height, bottom.z + depth);
    
    glEnd();
}
