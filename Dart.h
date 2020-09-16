#ifndef DART_H
#define DART_H

class Dart
{
public:
    float x;
    float y;
    float z;

    Dart();
    Dart(float x,float y,float z);
    float nextPosistion(float vx,float vy,float vz,float dt,float g);
    void reset();
};


#endif // DART_H
