#ifndef POINT_H
#define POINT_H
class Point
{
private:
    float x;
    float y;
    float z;
public:
    Point ();
    Point( float x, float y,float z);
    float getx();
    float gety();
    float getz();
    void setx(float newx);
    void sety(float newy);
    void setz(float newz);
};

#endif //POINT_H
