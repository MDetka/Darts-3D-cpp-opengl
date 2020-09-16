#include "Dartboard.h"
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
int tempz = -50;
Dartboard::Dartboard()
{
    create_circles();
    create_triangles();

}
void Dartboard::create_circles()
{
    Point p = Point(0,25,tempz);
    circles[0] = Circle(p,0.75,50);
    circles[1] = Circle(p,1.5,25);
    circles[2] = Circle(p,8,1);
    circles[3] = Circle(p,10,3);
    circles[4] = Circle(p,13.5,1);
    circles[5] = Circle(p,15.5,2);
}


void Dartboard::create_triangles()
{
    float xy[20];
    float yy[20];
    double start_angle=98;
    double angle=start_angle;
    double step=360/20;
    float radius = 20;
    int i = 0;
    Point centre = Point(0,25,tempz);

    for(i=0; i<20; i++)
    {
        xy[i]=0 + radius * cos(angle*PI/180);
        yy[i]=25 + radius * sin(angle*PI/180);
        angle+=step;
    }
    for(int i=0; i<19; i++)
    {
        tri[i] = Triangles(centre,Point(xy[i],yy[i],tempz),Point(xy[i+1],yy[i+1],tempz));
    }
    tri[19] = Triangles(centre,Point(xy[19],yy[19],tempz),Point(xy[0],yy[0],tempz));

}



int Dartboard::hit(int x,int y,int z)
{

    setpoint(x,y,z);
    Point p = Point(x,y,z);

    if(circles[0].inside(p))
    {
        return 50;
    }
    else if(circles[1].inside(p))
    {
        return 25;
    }
    else
    {

        for(int j=2; j<6; j++)
        {
            if(circles[j].inside(p))
            {
                for(int i=0; i<20; i++)
                {
                    if(tri[i].inside(p))
                    {
                        return points_of_triangles[i] * circles[j].multiplier;
                    }
                }
            }
        }
    }

    return 0;

}

void Dartboard::setpoint(int x,int y,int z)
{
    p.setx(x);
    p.sety(y);
    p.setz(z);
}
