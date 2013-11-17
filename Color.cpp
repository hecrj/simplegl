#include "Color.h"

const Color Color::WHITE(0.8, 0.8, 0.8);
const Color Color::BLUE(0.3, 0.3, 0.8);
const Color Color::GREEN(0.3, 0.8, 0.3);

Color::Color()
{
    rgb[0] = rgb[1] = rgb[2] = rgb[3] = 1;
}

Color::Color(float r, float g, float b)
{
    rgb[0] = r;
    rgb[1] = g;
    rgb[2] = b;
    rgb[3] = 1;
}

Color::Color(float r, float g, float b, float a)
{
    rgb[0] = r;
    rgb[1] = g;
    rgb[2] = b;
    rgb[3] = a;
}

Color::~Color()
{
    
}
