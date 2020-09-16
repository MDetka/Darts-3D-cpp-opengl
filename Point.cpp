#include "Point.h"
Point::Point ()
{
    x=0.0;
    y=0.0;
    z=0.0;
}
Point::Point(float x, float y,float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

float Point::getx()
{
    return x;
}

float Point::gety()
{
    return y;
}

float Point::getz()
{
    return z;
}

void Point::setx(float newx)
{
    x=newx;
}
void Point::sety(float newy)
{
    y=newy;
}
void Point::setz(float newz)
{
    z=newz;
}

