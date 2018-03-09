#include "RenderGL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>
#include <GL/glu.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

RenderGL g_renderGL; //Singleton

RenderGL::RenderGL()
{
}

RenderGL::~RenderGL()
{
}

void RenderGL::inicializar()
{
	GLenum error = GL_NO_ERROR;
	//Para obtener error: error = glGetError();
	//Inicializamos Matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Model view Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	float aspect =(float)w / (float)h;
	const float WorldSize= 10.0f; ///El mundo de opengl es de -10 a 10

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
	//Initialize clear color
	glClearColor(0.f, 0.f, 0.f, 1.f);
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

    glColor3f(0.0f, 1.0f, 0.0f);
    glPointSize(3.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.0f);
    glEnd();


}

void RenderGL::dibujarimg()
{
    int flags=IMG_INIT_JPG|IMG_INIT_PNG;
    int initted=IMG_Init(flags);

    SDL_Surface *img;

    img = IMG_Load("gato_gordo.jpg");

}
