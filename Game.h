#ifndef GAME_H
#define GAME_H

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include<string.h>
#include "Targa.h"

#define ANIM_FPS 60

class Game
{
public:
    Game(void);
    static void ChangeSize(int w, int h);
    static void RenderScene(void);
    static void SetupScene(void);
    static void TimerFun(int val);
    static void KeyFun(unsigned char key, int x, int y);
    static void MotionFun(int x, int y);
    static void MouseFun(int button,int state,int x,int y);
    static void DrawRoom();
    static void drawAnim8orObject(struct Anim8orObject *obj);
    static void reset();
    static void menu();
    static void game();
    static void gameover();
    static void about();


};


#endif // GAME_H
