#ifndef TARGA_H
#define TARGA_H

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
/*
 *	Targa.h
 */

typedef struct
{
    GLuint bpp;		// iloœæ bitów na piksel
    GLuint width;	// rozmiary w pikselach
    GLuint height;
} TARGAINFO;

// Funkcje
GLubyte *LoadTGAImage(char *filename, TARGAINFO *info);
bool LoadTGATexture(char *filename);
bool LoadTGAMipmap(char *filename);
#endif
