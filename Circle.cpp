#include "Circle.h"
#include <math.h>
Circle::Circle()
{
    centre=Point(0,25,-50);
    radius = 3;
    multiplier=1;
}

Circle::Circle(Point p,float radius,int multiplier)
{
    centre = p;
    this->radius=radius;
    this->multiplier=multiplier;
}

bool Circle::inside(Point p)
{
    double wynik;
    double tmp = pow((double)p.getx()-(double)centre.getx(),2);
    double tmp2 = pow((double)p.gety()-(double)centre.gety(),2);
    wynik=sqrt(tmp+tmp2);
    return (wynik < radius);
}
