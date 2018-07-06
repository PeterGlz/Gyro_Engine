#include "RenderGL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>
#include <GL/glu.h>
#include <iostream>
#include "SevenUp.h"

RenderGL g_renderGL; //Singleton

RenderGL::RenderGL()
{
    //screenW = 800;
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

	//fondo.LoadImg("fondo.jpg");
	//fondo.InitOGL();

    atl1.Load("pokesprites.png");
    atl1.Read("pokesprites.txt");
    atl1.Init7up(&poke, 21);
    atl1.Init7up(&lick, 8);
    atl1.Init7up(&geng, 4);
    atl1.Init7up(&nine, 14);
    atl1.Init7up(&chori, 0);
    atl1.Init7up(&onix, 16);
    atl1.Init7up(&bola, 18);
    //poke.Load("pokesprites.png");
    fondo.Load("fondo.jpg");
}

void RenderGL::liberar()
{
}

void RenderGL::update()
{
}

void RenderGL::render()
{
	///Limpiamos pantalla
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    /*glDisable(GL_TEXTURE_2D);
    glColor3f(0.0f, 1.0f, 0.0f);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.0f);
    glEnd();
    glEnable(GL_TEXTURE_2D);*/

    fondo.SetRot(0);
    fondo.SetPos(-13.34, -10);
    fondo.SetScale(27, 20);
    fondo.SetPriority(0.0f);
    fondo.Draw();

    poke.SetRot(0);
    poke.SetPos(protaPosX, protaPosY);
    poke.SetScale(1, 1);
    poke.SetPriority(0.1f);
    poke.Draw();

    bola.SetRot(0);
    bola.SetPos(protaPosX+0.25, protaPosY+1);
    bola.SetScale(0.5f, 0.5f);
    bola.SetPriority(0.1f);
    bola.Draw();

    for(int i=-7; i<6; i++)
    {
        if(i%2!=0)
        {
            lick.SetRot(0);
            lick.SetPos(i, 0);
            lick.SetScale(1, 1);
            lick.SetPriority(0.1f);
            lick.Draw();
        }
    }
    for(int i=-7; i<6; i++)
    {
        if(i%2!=0)
        {
            geng.SetRot(0);
            geng.SetPos(i, 2);
            geng.SetScale(1, 1);
            geng.SetPriority(0.1f);
            geng.Draw();
        }
    }
    for(int i=-7; i<6; i++)
    {
        if(i%2!=0)
        {
            nine.SetRot(0);
            nine.SetPos(i, 4);
            nine.SetScale(1, 1);
            nine.SetPriority(0.1f);
            nine.Draw();
        }
    }
    for(int i=-7; i<6; i++)
    {
        if(i%2!=0)
        {
            chori.SetRot(0);
            chori.SetPos(i, 6);
            chori.SetScale(1, 1);
            chori.SetPriority(0.1f);
            chori.Draw();
        }
    }
    for(int i=-7; i<6; i++)
    {
        if(i%2!=0)
        {
            onix.SetRot(0);
            onix.SetPos(i, 8);
            onix.SetScale(1, 1);
            onix.SetPriority(0.1f);
            onix.Draw();
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
