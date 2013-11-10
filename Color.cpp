#include "Color.h"

Color::Color()
{
    rgb[0] = rgb[1] = rgb[2] = 1;
}

Color::Color(float r, float g, float b)
{
    rgb[0] = r;
    rgb[1] = g;
    rgb[2] = b;
}

Color::~Color()
{
    
}
