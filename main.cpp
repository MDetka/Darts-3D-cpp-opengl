#include "Game.h"
int main(int argc, char *argv[])
{
    Game game;
    glutInit(&argc, argv);
    // Okno:
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 800);
    glutCreateWindow("Darts3D");
    glutFullScreen();
    // Funkcje zwrotne:
    glutDisplayFunc(Game::RenderScene);
    glutReshapeFunc(Game::ChangeSize);
    glutKeyboardFunc(Game::KeyFun);
    glutMouseFunc(Game::MouseFun);
    glutMotionFunc(Game::MotionFun);
    // Inicjalizacja OpenGL:
//	glutFullScreen();
    Game::SetupScene();
    glutTimerFunc(1000/ANIM_FPS, Game::TimerFun, 0);


    glutMainLoop();
    return(0);
}
