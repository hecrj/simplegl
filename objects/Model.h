/* 
 * File:   Model.h
 * Author: hector
 */

#include "../vendor/ModelLoader.h"
#include <string>

using namespace std;

#ifndef MODEL_H
#define	MODEL_H

class Model : public ModelLoader
{
    Point bottom;
    Point top;
    Point center;
    Point rightFrontBottom;
    
    double width;
    double height;
    double depth;
    
public:
    Model();
    virtual ~Model();
    void load(string filename);
    double getWidth() const;
    double getHeight() const;
    double getDepth() const;
    double getRFBX() const;
    double getRFBY() const;
    double getRFBZ() const;

protected:
    void drawGeom() const;
    void drawTransformations() const;
    
private:
    void updateBoundingBox(double x, double y, double z);
    void drawBoundingBox() const;
    void drawBase(double height) const;

};

#endif	/* MODEL_H */
