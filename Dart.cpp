#include "Dart.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
Dart::Dart()
{
    x=0.0;
    y=0.0;
    z=75.0;
}


Dart::Dart(float x,float y,float z)
{
    this->x=x;
    this->y=y;
    this->z=z;
}

void Dart::reset()
{
    x=0.0;
    y=0.0;
    z=75.0;
}

float Dart::nextPosistion(float vx,float vy,float vz,float dt,float g){

this->x += vx * dt;
this->z +=(-1)*vz * dt;
vy=vy-g*dt;
this->y += vy*dt;
return vy;


}
