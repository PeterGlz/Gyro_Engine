#include "RenderGL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>
#include <GL/glu.h>
#include <iostream>
#include "SevenUp.h"
#include "primitivo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <cmath>

RenderGL g_renderGL; //Singleton

RenderGL::RenderGL()
{
}

RenderGL::~RenderGL()
{
}

void RenderGL::inicializar()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_DEPTH_CLAMP);
    glDepthMask(true);
    glDepthFunc(GL_LEQUAL);
    glDepthRange(0, 1);
    glClearDepth(1.0);
    ///Indicamos que hay texturas
    glEnable(GL_TEXTURE_2D);
    ///Activamos transparencias
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

	GLenum error = GL_NO_ERROR;
	//Para obtener error: error = glGetError();
	//Inicializamos Matrix
	glViewport(0, 0, w, h);    //establecemos la dimensiones
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float aspect =(float)w / (float)h;
    WorldSize= 10.0f; ///El mundo de opengl es de -10 a 10
    offsetMouseY = WorldSize;
    offsetMouseX = (WorldSize * aspect);

    contador = 2;

	if (w >= h)
	{
		clipAreaXLeft=-WorldSize*aspect;
		clipAreaXRightt = WorldSize*aspect;
		clipAreaYBottom = -WorldSize;
		clipAreaYTop = WorldSize;
	}
	else
	{
		clipAreaXLeft = -WorldSize;
		clipAreaXRightt = WorldSize;
		clipAreaYBottom = -WorldSize/aspect;
		clipAreaYTop = WorldSize/aspect;
	}

	gluOrtho2D(clipAreaXLeft, clipAreaXRightt, clipAreaYBottom, clipAreaYTop);

	///Model view Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Initialize clear color
	glClearColor(0.f, 0.f, 0.f, 1.f);

	protaPosX = -1;
	protaPosY = -8;
	delay = 1;
	delayA = 1;

	delay = 1;
	delayA = 1;

	delayP = 5;
	delayPA = 5;

	balaPosX = protaPosY;
	balaPosY = protaPosY;

	misilPosX = 0;
	misilPosY = 8;

	fila1 = 0;
	fila2 = 2;
	fila3 = 4;
	fila4 = 6;
	fila5 = 8;

    atl1.Load("pokesprites.png");
    atl1.Read("pokesprites.txt");
    atl1.Init7up(&poke, 21);
    atl1.Init7up(&lick, 8);
    atl1.Init7up(&geng, 4);
    atl1.Init7up(&nine, 14);
    atl1.Init7up(&chori, 0);
    atl1.Init7up(&onix, 16);
    atl1.Init7up(&bola, 18);
    atl1.Init7up(&poke2, 22);
    atl1.Init7up(&lick2, 9);
    atl1.Init7up(&geng2, 5);
    atl1.Init7up(&nine2, 15);
    atl1.Init7up(&chori2, 1);
    atl1.Init7up(&onix2, 17);
    atl1.Init7up(&bola2, 19);
    fondo.Load("fondo.jpg");
}

void RenderGL::liberar()
{
}

void RenderGL::update()
{
    contador -= 0.07;
    if(contador <= 0)
    {
        contador = 2;
    }
}

void RenderGL::render()
{
	///Limpiamos pantalla
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    ///Fondo-----------------------------------------------------------
    fondo.SetRot(0);
    fondo.SetPos(-13.34, -10);
    fondo.SetScale(27, 20);
    fondo.SetPriority(0.0f);
    fondo.Draw();

    ///Proyectil enemigo-----------------------------------------------------------
    DibTriangulo(misilPosX, misilPosY, 180, 0.3, 0.3, 1, 1, 1);
    delayP -= 0.18;
    if(delayP <= 0)
    {
        delay2 -= 0.18;
        if (delay2 <= 0)
        {
            misilPosY--;
            delay2 = delayA;
        }
        if(misilPosY <= -12)
        {
            misilPosY = 8;
            delayP = delayPA;
        }
    }


    ///Personaje-----------------------------------------------------------
    if(contador > 1)
    {
        poke.SetRot(0);
        poke.SetPos(protaPosX, protaPosY);
        poke.SetScale(1, 1);
        poke.SetPriority(0.1f);
        poke.Draw();
    }
    else if(contador <= 1)
    {
        poke2.SetRot(0);
        poke2.SetPos(protaPosX, protaPosY);
        poke2.SetScale(1, 1);
        poke2.SetPriority(0.1f);
        poke2.Draw();
    }

    ///Movimiento y velocidad de disparo-----------------------------------------------------------
    if(disparo == true)
    {
        delay -= 0.18;
        if (delay <= 0)
        {
            balaPosY++;
            delay = delayA;
        }
        if(balaPosY >= 10)
        {
            disparo = false;
            balaPosY = protaPosY;
        }
        bola.SetRot(0);
        bola.SetPos(protaPosX, balaPosY);
        bola.SetScale(0.5f, 0.5f);
        bola.SetPriority(0.2f);
        bola.Draw();
    }



    ///Enemigos-----------------------------------------------------------
    for(int i=0; i<14; i++)///Lickitung
    {
        if(i%2!=0 && enemf1[i] == 0)
        {
            if(contador > 1)
            {
                lick.SetRot(0);
                lick.SetPos(i-8, fila1);
                lick.SetScale(1, 1);
                lick.SetPriority(0.1f);
                lick.Draw();
                if(i-8 == protaPosX && fila1 == balaPosY)
                {
                    disparo = false;
                    balaPosY = protaPosY;
                    enemf1[i] = 1;
                }
            }
            else if(contador <= 1)
            {
                lick2.SetRot(0);
                lick2.SetPos(i-8, fila1);
                lick2.SetScale(1, 1);
                lick2.SetPriority(0.1f);
                lick2.Draw();
                if(i-8 == protaPosX && fila1 == balaPosY)
                {
                    disparo = false;
                    balaPosY = protaPosY;
                    enemf1[i] = 1;
                }
            }
        }
    }
    for(int i=0; i<14; i++)///Gengar
    {
        if(i%2!=0 && enemf2[i] == 0)
        {
            if(contador > 1)
            {
                geng.SetRot(0);
                geng.SetPos(i-8, fila2);
                geng.SetScale(1, 1);
                geng.SetPriority(0.1f);
                geng.Draw();
                if(i-8 == protaPosX && fila2 == balaPosY)
                {
                    disparo = false;
                    balaPosY = protaPosY;
                    enemf2[i] = 1;
                }
            }
            else if(contador <= 1)
            {
                geng2.SetRot(0);
                geng2.SetPos(i-8, fila2);
                geng2.SetScale(1, 1);
                geng2.SetPriority(0.1f);
                geng2.Draw();
                if(i-8 == protaPosX && fila2 == balaPosY)
                {
                    disparo = false;
                    balaPosY = protaPosY;
                    enemf2[i] = 1;
                }
            }
        }
    }
    for(int i=0; i<14; i++)///Ninetales
    {
        if(i%2!=0 && enemf3[i] == 0)
        {
            if(contador > 1)
            {
                nine.SetRot(0);
                nine.SetPos(i-8, fila3);
                nine.SetScale(1, 1);
                nine.SetPriority(0.1f);
                nine.Draw();
                if(i-8 == protaPosX && fila3 == balaPosY)
                {
                    disparo = false;
                    balaPosY = protaPosY;
                    enemf3[i] = 1;
                }
            }
            else if(contador <= 1)
            {
                nine2.SetRot(0);
                nine2.SetPos(i-8, fila3);
                nine2.SetScale(1, 1);
                nine2.SetPriority(0.1f);
                nine2.Draw();
                if(i-8 == protaPosX && fila3 == balaPosY)
                {
                    disparo = false;
                    balaPosY = protaPosY;
                    enemf3[i] = 1;
                }
            }
        }
    }
    for(int i=0; i<14; i++)///Charizard
    {
        if(i%2!=0 && enemf4[i] == 0)
        {
            if(contador > 1)
            {
                chori.SetRot(0);
                chori.SetPos(i-8, fila4);
                chori.SetScale(1, 1);
                chori.SetPriority(0.1f);
                chori.Draw();
                if(i-8 == protaPosX && fila4 == balaPosY)
                {
                    disparo = false;
                    balaPosY = protaPosY;
                    enemf4[i] = 1;
                }
            }
            else if(contador <= 1)
            {
                chori2.SetRot(0);
                chori2.SetPos(i-8, fila4);
                chori2.SetScale(1, 1);
                chori2.SetPriority(0.1f);
                chori2.Draw();
                if(i-8 == protaPosX && fila4 == balaPosY)
                {
                    disparo = false;
                    balaPosY = protaPosY;
                    enemf4[i] = 1;
                }
            }
        }
    }
    for(int i=0; i<14; i++)///Onix
    {
        if(i%2!=0 && enemf5[i] == 0)
        {
            if(contador > 1)
            {
                onix.SetRot(0);
                onix.SetPos(i-8, fila5);
                onix.SetScale(1, 1);
                onix.SetPriority(0.1f);
                onix.Draw();
                if(i-8 == protaPosX && fila5 == balaPosY)
                {
                    disparo = false;
                    balaPosY = protaPosY;
                    enemf5[i] = 1;
                }
            }
            else if(contador <= 1)
            {
                onix2.SetRot(0);
                onix2.SetPos(i-8, fila5);
                onix2.SetScale(1, 1);
                onix2.SetPriority(0.1f);
                onix2.Draw();
                if(i-8 == protaPosX && fila5 == balaPosY)
                {
                    disparo = false;
                    balaPosY = protaPosY;
                    enemf5[i] = 1;
                }
            }
        }
    }
}

bool Sprite::MouseEve (float _x, float _y)
{
     ///Para agregar otra imagen a la que se le pueda dar click es necesario agregar otro IF con la variable de Sprite que se quiera usar en ese caso
    if(_x >= coord1 && _x <=coord2 && _y  >= coord3 && _y <= coord4)
    {
        ///Aquí se detecta que boton del mouse es presionado
            ///En esta parte se pone la acción que se desee ejecutar al momento de dar click
            SDL_Log("Mouse Button is pressed.");
            return true;

    }
    return false;
}
