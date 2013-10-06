#ifndef COLOR_H
#define	COLOR_H

struct Color
{
    double r, g, b;
    Color();
    Color(double r, double g, double b);
    virtual ~Color();
};

#endif	/* COLOR_H */
