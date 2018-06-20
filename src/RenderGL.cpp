#include "RenderGL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>
#include <GL/glu.h>
#include <iostream>
#include "SevenUp.h"

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
    ///Indicamos que hay texturas
    glEnable(GL_TEXTURE_2D);
    ///Activamos transparencias
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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

	///Cargamos la textura y le asignamos la imagen a cargar
    spr.Load("taco.jpg");
    spr2.Load("mojado2.jpg");

	///Model view Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void RenderGL::liberar()
{
    ///Cerramos la imagen
    spr.Close();
    spr2.Close();
}

void RenderGL::update()
{
}

float vertices[]
{
    -0.5, 0.5, 0.0, ///top left
    0.5, 0.5, 0.0, ///top right
    0.5, -0.5, 0.0, ///bottom right
    -0.5, -0.5, 0.0 ///bottom left
};

void RenderGL::render()
{
	///Limpiamos pantalla
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glDisable(GL_TEXTURE_2D);
    glColor3f(0.0f, 1.0f, 0.0f);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glVertex2f(0, 0);
    glEnd();
    glEnable(GL_TEXTURE_2D);

    spr.Draw();
    spr.SetRot(0);
    spr.SetPos(0, 0);
    spr.SetScale(5, 5);
    spr.SetPriority(0.2f);

    spr2.Draw();
    spr2.SetRot(0);
    spr2.SetPos(-7, -5);
    spr2.SetScale(5, 5);
    spr2.SetPriority(0.3f);
}

bool Sprite::MouseEve (float _x, float _y)
{
     ///Para agregar otra imagen a la que se le pueda dar click es necesario agregar otro IF con la variable de Sprite que se quiera usar en ese caso
    if(_x >= coord1 && _x <=coord2 && _y  >= coord3 && _y <= coord4)
    {
        ///Aqu� se detecta que boton del mouse es presionado
            ///En esta parte se pone la acci�n que se desee ejecutar al momento de dar click
            SDL_Log("Mouse Button is pressed.");
            return true;


    }
    return false;
}
