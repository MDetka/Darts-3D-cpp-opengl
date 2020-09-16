#ifndef CAMERA_H
#define CAMERA_H

class Camera
{
public:
    int x;
    int y;
    int z;
    int angle;


    Camera();
    Camera(int x,int y,int z,int angle);

    void reset();
};


#endif // CIRCLE_H
