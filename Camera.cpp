#include "Camera.h"
Camera::Camera()
{
    x=0;
    y=0;
    z=0;
    angle=0;
}


Camera::Camera(int x,int y, int z,int angle)
{
    this->x=x;
    this->y=y;
    this->z=z;
    this->angle=angle;

}

void Camera::reset()
{
    x=0;
    y=0;
    z=0;
    angle=0;
}
