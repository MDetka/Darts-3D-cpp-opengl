#include "Game.h"
#include "Player.h"
#include "Dartboard.h"
#include "rzutka.c"
#include "tarcza.c"
#include "Dart.h"
#include "Camera.h"

GLfloat screenW = 600;
GLfloat screenH = 800;

GLfloat angleX=0;

GLuint tex[9];

Dart dart = Dart();
Player player1= Player();
Player player2= Player();
Dartboard db = Dartboard();
Camera camera = Camera();


int point=0;
float mousex,mousey;
float counter = 1.0;
float mouseDx=0;
float mouseDy=0;
float throwy,throwx,vektory,vektorx;
float vz=20;
float dt=counter/60.0;
bool viewer =false;
bool thrown= false;
bool scored=false;
bool pressed = false;
bool player=true;

void Game::reset()
{
    dart.reset();
    mouseDx = 0;
    mouseDy = 0;
    angleX = 0;
    thrown= false;
    pressed = false;
    scored=false;
    glLoadIdentity();
    if(!viewer){
    gluLookAt(0,0,95,0,0,-50,0,1,0);
    }
    else{
    gluLookAt(20,0,120,0,0,-30,0,1,0);
    }
}

// Parametry oswietlenia:
GLfloat lightPos[] = {0.0f, 40.0f, 150.0f, 1.0f};
GLfloat lightDif[] = {0.9f, 0.9f, 0.9f, 1.0f};
GLfloat lightSpe[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat lightAmb[] = {0.1f, 0.1f, 0.1f, 0.8f};
GLfloat specRef[] = {1.0f, 1.0f, 1.0f, 1.0f};


enum GameState {MENU,GAME,ABOUT,GAMEOVER,END};

GameState stateOfGame;


Game::Game(void)
{
     stateOfGame=MENU;
}

void Game::menu()
{
    player1.setscore(301);
    player2.setscore(301);
    vektorx =0.0;
    vektory =0.0;
    reset();
    viewer=false;


    //glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, screenW, 0.0, screenH);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

        glClearColor(0.0, 0.0, 0.0, 1.0);

    glBindTexture(GL_TEXTURE_2D, tex[3]);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 1);
    glVertex2f(0,screenH);
    glTexCoord2f(1, 1);
    glVertex2f(screenW,screenH);
    glTexCoord2f(1, 0);
    glVertex2f(screenW,0);
    glTexCoord2f(0, 0);
    glVertex2f(0,0);
    glEnd();


    // WYCOWYFANIE ZMIAN
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
  //  glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glutSwapBuffers();

}
void Game::gameover()
{
//   glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, screenW, 0.0, screenH);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    if(player1.getscore()<player2.getscore()){
    glBindTexture(GL_TEXTURE_2D, tex[7]);
    }
    if(player2.getscore()<player1.getscore()){
    glBindTexture(GL_TEXTURE_2D,tex[8]);
    }



    glBegin(GL_QUADS);
    glTexCoord2f(0, 1);
    glVertex2f(0,screenH);
    glTexCoord2f(1, 1);
    glVertex2f(screenW,screenH);
    glTexCoord2f(1, 0);
    glVertex2f(screenW,0);
    glTexCoord2f(0, 0);
    glVertex2f(0,0);
    glEnd();

    // WYCOWYFANIE ZMIAN
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
   // glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glutSwapBuffers();

}


void Game::about()
{
    //   glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, screenW, 0.0, screenH);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glBindTexture(GL_TEXTURE_2D, tex[4]);



    glBegin(GL_QUADS);
    glTexCoord2f(0, 1);
    glVertex2f(0,screenH);
    glTexCoord2f(1, 1);
    glVertex2f(screenW,screenH);
    glTexCoord2f(1, 0);
    glVertex2f(screenW,0);
    glTexCoord2f(0, 0);
    glVertex2f(0,0);
    glEnd();

    // WYCOWYFANIE ZMIAN
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
   // glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glutSwapBuffers();

}


void Game::game()
{

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, screenW/screenH, 1, 400);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    // ustawienie punktu kamery oraz punktu ktory widzi
    if(!viewer){
    gluLookAt(0,0,95,0,0,-50,0,1,0);
    }
    else{
    gluLookAt(20,0,120,0,0,-30,0,1,0);
    }
    // przesuniecia kamery
    glTranslatef(camera.x,0,0);
    glTranslatef(0,camera.y,0);
    glTranslatef(0,0,camera.z);

    glRotatef(camera.angle,0,1,0);
    // Umiejscowienie swiatla
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    //Narysowanie pokoju
    DrawRoom();

    // Narysowanie modelu tarczy
    glBindTexture(GL_TEXTURE_2D,tex[6]);
    glPushMatrix();
    glTranslated(0,25,-50);
    glScalef(0.75,0.75,0.75);
    drawAnim8orObject(&object_dartboard);
    glPopMatrix();


    // przesuniecie rzutki jak sie trzyma przycisk myszy
    if(!thrown)
    {
        glTranslatef(mouseDx,mouseDy,dart.z);
    }

    // rzutka leci....
    if(thrown)
    {
        glTranslatef(dart.x,dart.y,dart.z);
    }
    glRotatef(-70+angleX, 1, 0, 0);

    glBindTexture(GL_TEXTURE_2D, tex[5]);
    drawAnim8orObject(&object_rzutka);

    // RYSOWNAN22IE HUDU

    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, screenW, 0.0, screenH);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    void * font = GLUT_BITMAP_TIMES_ROMAN_24;
    glColor3d(1.0, 1.0, 1.0);
    glRasterPos2i(screenW/2-30, 40);
        std::string points ="Punkty: "+std::to_string(point);
        for (std::string::iterator i = points.begin(); i != points.end(); ++i)
        {
            char c = *i;
            glutBitmapCharacter(font, c);
        }
    if(scored)
    {







        glRasterPos2i(screenW/2-75, 10);
        std::string str = "Nacisnij LPM";
        for (std::string::iterator i = str.begin(); i != str.end(); ++i)
        {
            char c = *i;
            glutBitmapCharacter(font, c);
        }
    }
        glRasterPos2i(screenW/4-50, 40);
        std::string position;
        position = "x: "+std::to_string(vektorx) +"  y: "+ std::to_string(vektory);
        for (std::string::iterator i = position.begin(); i != position.end(); ++i)
        {
            char c = *i;
            glutBitmapCharacter(font, c);
        }

        glRasterPos2i(screenW/4-50, 10);
        std::string position2;
        if(pressed){
        position2 = "x: "+std::to_string(mouseDx) +"  y: "+ std::to_string(mouseDy);
      }
        for (std::string::iterator i = position2.begin(); i != position2.end(); ++i)
        {
            char c = *i;
            glutBitmapCharacter(font, c);
        }

    glRasterPos2i(10, 10);
    std::string p1 = "Player1: " + std::to_string(player1.getscore());

    for (std::string::iterator i = p1.begin(); i != p1.end(); ++i)
    {
        char c = *i;
        glutBitmapCharacter(font, c);
    }

    glRasterPos2i(screenW-150, 10);
    std::string p2 = "Player2: " + std::to_string(player2.getscore());

    for (std::string::iterator i = p2.begin(); i != p2.end(); ++i)
    {
        char c = *i;
        glutBitmapCharacter(font, c);
    }
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);


    glutSwapBuffers();


}

void Game::ChangeSize(int w, int h)
{
    if(h==0)
        h=1;
    glViewport(0, 0, w, h);
    screenW = (GLfloat)w;
    screenH = (GLfloat)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(50, screenW/screenH, 1, 400);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Game:: RenderScene()
{

    if(stateOfGame!=END)
    {
        switch (stateOfGame)
        {
        case MENU:
            menu();
            break;
        case GAME:
            game();
            break;
        case ABOUT:
            about();
            break;
        case GAMEOVER:
            gameover();
            break;
        case END:
            exit(0);
        }
    }
}

void Game:: SetupScene()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_CULL_FACE);

    glGenTextures(9, tex);

    glBindTexture(GL_TEXTURE_2D, tex[0]);
    LoadTGAMipmap("brick.tga");
    glBindTexture(GL_TEXTURE_2D, tex[1]);
    LoadTGAMipmap("floor.tga");
    glBindTexture(GL_TEXTURE_2D, tex[2]);
    LoadTGAMipmap("ceiling.tga");
    glBindTexture(GL_TEXTURE_2D, tex[3]);
    LoadTGAMipmap("menu2.tga");
    glBindTexture(GL_TEXTURE_2D, tex[4]);
    LoadTGAMipmap("about2.tga");

    glBindTexture(GL_TEXTURE_2D, tex[5]);
    LoadTGAMipmap("dart.tga");
    glBindTexture(GL_TEXTURE_2D, tex[6]);
    LoadTGAMipmap("dartboard.tga");
    glBindTexture(GL_TEXTURE_2D, tex[7]);
    LoadTGAMipmap("gracz1.tga");
    glBindTexture(GL_TEXTURE_2D, tex[8]);
    LoadTGAMipmap("gracz2.tga");


    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightAmb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  lightDif);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpe);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glEnable(GL_LIGHT0);


    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    glMaterialfv(GL_FRONT, GL_SPECULAR, specRef);
    glMateriali(GL_FRONT, GL_SHININESS, 100);
}


void Game::DrawRoom(){
    glBindTexture(GL_TEXTURE_2D, tex[0]);   // tekstura scian
    glBegin(GL_QUADS);
    //tylna
    glTexCoord2f(8, 8);
    glVertex3f(50.0f, 50.0f, -50.0f);
    glTexCoord2f(0, 8);
    glVertex3f(-50.0f, 50.0f, -50.0f);
    glTexCoord2f(0, 0);
    glVertex3f(-50.0f, -50.0f, -50.0f);
    glTexCoord2f(8, 0);
    glVertex3f(50.0f, -50.0f, -50.0f);

    //przednia
    glTexCoord2f(8, 8);
    glVertex3f(50.0f, -50.0f, 100.0f);
    glTexCoord2f(0, 8);
    glVertex3f(-50.0f, -50.0f, 100.0f);
    glTexCoord2f(0, 0);
    glVertex3f(-50.0f, 50.0f, 100.0f);
    glTexCoord2f(8, 0);
    glVertex3f(50.0f, 50.0f, 100.0f);

    //lewa
    glTexCoord2f(10, 10);
    glVertex3f(-50.0f, -50.0f, 100.0f);
    glTexCoord2f(0, 10);
    glVertex3f(-50.0f, -50.0f, -50.0f);
    glTexCoord2f(0, 0);
    glVertex3f(-50.0f, 50.0f, -50.0f);
    glTexCoord2f(10, 0);
    glVertex3f(-50.0f, 50.0f, 100.0f);

    //prawa
    glTexCoord2f(10, 10);
    glVertex3f(50.0f, 50.0f, 100.0f);
    glTexCoord2f(0, 10);
    glVertex3f(50.0f, 50.0f, -50.0f);
    glTexCoord2f(0, 0);
    glVertex3f(50.0f, -50.0f, -50.0f);
    glTexCoord2f(10, 0);
    glVertex3f(50.0f, -50.0f, 100.0f);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, tex[1]);  // tekstura podłogi

    glBegin(GL_QUADS);
    //podłoga
    glTexCoord2f(5, 5);
    glVertex3f(50.0f, -50.0f, 100.0f);
    glTexCoord2f(0, 5);
    glVertex3f(50.0f, -50.0f, -50.0f);
    glTexCoord2f(0, 0);
    glVertex3f(-50.0f, -50.0f, -50.0f);
    glTexCoord2f(5, 0);
    glVertex3f(-50.0f, -50.0f, 100.0f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, tex[2]);  // tekstura sufitu

    glBegin(GL_QUADS);
    //sufit
    glTexCoord2f(10, 10);
    glVertex3f(-50.0f, 50.0f, 100.0f);
    glTexCoord2f(0, 10);
    glVertex3f(-50.0f, 50.0f, -50.0f);
    glTexCoord2f(0, 0);
    glVertex3f(50.0f, 50.0f, -50.0f);
    glTexCoord2f(10, 0);
    glVertex3f(50.0f, 50.0f, 100.0f);
    glEnd();
}


void Game::drawAnim8orObject(struct Anim8orObject *obj)
{

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);


    for(int m=0; m < obj->nMeshes; m++)
    {

        glColor4fv(obj->meshes[m]->materials[0].diffuse);

        glVertexPointer(3, GL_FLOAT, 0, obj->meshes[m]->coordinates);

        glNormalPointer(GL_FLOAT, 0, obj->meshes[m]->normals);

        glTexCoordPointer(2, GL_FLOAT, 0, obj->meshes[m]->texcoords);

        glDrawElements(GL_TRIANGLES, obj->meshes[m]->nIndices, GL_UNSIGNED_INT, obj->meshes[m]->indices);
    }
}


void Game::KeyFun(unsigned char key, int x, int y)
{

    if(key=='f' || key=='F')
    {
        if(camera.y<45)
            camera.y += 5;
    }
    if(key=='r' || key=='R')
    {
        if(camera.y>-45)
            camera.y -= 5;
    }
    if(key=='w' || key=='W')
    {
        if(camera.z<95)
            camera.z += 5;
    }
    if(key=='s' || key=='S')
    {
        if(camera.z>-10)
            camera.z -= 5;
    }
    if(key=='a' || key=='A')
    {
        if(camera.x<45)
            camera.x += 5;
    }
    if(key=='d' || key=='D')
    {
        if(camera.x>-35)
            camera.x -= 5;
    }
    if(key=='q' || key=='Q'){
        camera.angle+=10;
    }
    if(key=='e' || key=='E'){
        camera.angle-=10;
    }
    if(key=='t'||key=='T'){
        if(viewer){
            viewer=false;
        }
        else{
            viewer=true;
        }
    }




   if(key=='1' && stateOfGame==MENU )
    {
        stateOfGame=GAME;
		reset();
        game();
    }
    if(key=='2' && stateOfGame ==MENU)
    {
        stateOfGame=ABOUT;
        about();
    }

    if(key=='x' || key=='X')
    {
        camera.reset();
		reset();
    }


    if(key == 0x1B)
    {
        if(stateOfGame==MENU)
        {
            stateOfGame=END;
            exit(0);
        }
        stateOfGame=MENU;
    }
}


void Game::TimerFun(int val)
{
    if(stateOfGame==GAME)
    {
        if(thrown)
        {
            counter+=1.0;
            dt=counter/60;
            mouseDy=dart.nextPosistion(mouseDx,mouseDy,vz,dt,0.5);

            angleX -=0.45;
        }
        if(((dart.z) <= -50)||((dart.x)<=-45) || ((dart.x) >= 45)||((dart.y)<=-48) || ((dart.y)>=48))
        {
            if(thrown){
            vektorx=throwx;
            vektory=throwy;
            }
            thrown = false;
            mouseDx=dart.x;
            mouseDy=dart.y;
            counter=0;
            if(!scored)
            {
                if(player)
                {
                    player1.update(point=db.hit(dart.x,dart.y,dart.z));
                    player = false;
                }
                else if (!player)
                {
                    player2.update(point=db.hit(dart.x,dart.y,dart.z));
                    player = true;
                }
            }
            scored = true;
            glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
        }
        if(player1.getscore()<=0 || player2.getscore()<=0)
        {
            stateOfGame=GAMEOVER;
            reset();
            gameover();
        }
    }




    glutPostRedisplay();
    glutTimerFunc(1000/ANIM_FPS, TimerFun, 0);
}
void Game::MotionFun(int x,int y)
{
    if(!thrown)
    {
        mouseDx = (float)(x-mousex)/20;
        mouseDy = (float)(mousey-y)/20;



            throwx = (float)(x-mousex)/20;
            throwy = (float)(mousey-y)/20;


        if(stateOfGame==GAME)
            glutSetCursor(GLUT_CURSOR_NONE);
    }
}

void Game::MouseFun(int button,int state,int x,int y)
{
    mousex=x;
    mousey=y;

    if(stateOfGame==GAME)
    {


        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            pressed = true;


        }

        if(thrown==false&&(button == GLUT_LEFT_BUTTON && state == GLUT_UP))
        {



            thrown = true;
            pressed=false;

            dart.x=mouseDx;
            dart.y=mouseDy;


        }
        if(scored &&(button == GLUT_LEFT_BUTTON && state == GLUT_UP)){

        camera.reset();
		reset();

        }
    }



    if(stateOfGame==MENU){

        if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
        {
            if(mousex>0.25*screenW && mousex<0.75*screenW){
                if(mousey > 0.5*screenH && mousey < 0.5625*screenH) {
                    stateOfGame = GAME;
                }
                if(mousey > 0.6375*screenH && mousey < 0.7*screenH) {
                    stateOfGame = ABOUT;
                }
                if(mousey > 0.7625*screenH && mousey < 0.825*screenH) {
                    exit(0);
                }
            }
        }
    }

        if(stateOfGame==ABOUT||stateOfGame==GAMEOVER){
            if(mousex > 0.080 * screenW && mousex<0.350 *screenW){
                if(mousey>0.85*screenH && mousey<0.97 *screenH){
                    stateOfGame = MENU;
                }
            }

        }

}
