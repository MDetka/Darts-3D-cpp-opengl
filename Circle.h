#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"
class Circle
{
private:
    Point centre;
    float radius;

public:
    Circle();
    Circle(Point p,float radius,int multiplier);
    bool inside(Point p);
    int multiplier;
};
#endif // CIRCLE_H
