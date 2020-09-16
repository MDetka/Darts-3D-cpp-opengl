
#ifndef DARTBOARD_H
#define DARTBOARD_H

#include "Circle.h"
#include "Triangles.h"
#include "Point.h"
#include <math.h>
#include <time.h>

#ifndef M_PI
#define PI 3.14159265358979323846
#endif
class Dartboard
{
private:

    Circle  circles[6];
    int points_of_triangles[20] = {5,12,9,14,11,8,16,7,19,3,17,2,15,10,6,13,4,18,1,20};
    Point p;
public:
    Triangles tri[20];
    Dartboard();
    void create_circles();
    void create_triangles();
    void setpoint(int x,int y,int z);
    Point getpoint();
    int hit(int x, int y,int z);
};
#endif // DARTBOARD_H
