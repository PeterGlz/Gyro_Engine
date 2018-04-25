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

	//Definimos la imagen a cargar
    img.LoadImg("mojado.jpg");
    img2.LoadImg("mojado2.jpg");

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

	//Cargamos la textura y le asignamos la imagen a cargar
    img.InitOGL();
    img2.InitOGL();

	//Model view Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void RenderGL::liberar()
{
    //Cerramos la imagen
    img.CloseImg();
    img2.CloseImg();
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

void Textura (unsigned int hola, int x, int y)
{
    glPushMatrix();
    glTranslatef(x, y, 0);

    ///Se dibuja la textura
    glColor3f(1.0f, 1.0f, 1.0f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, hola);

    glBegin(GL_QUADS);
    glTexCoord2f(1, 1); glVertex3f(8, 0, 0);
    glTexCoord2f(0, 1); glVertex3f(0, 0, 0);
    glTexCoord2f(0, 0); glVertex3f(0, 8, 0);
    glTexCoord2f(1, 0); glVertex3f(8, 8, 0);
    glEnd();
    glPopMatrix();
}

void RenderGL::render()
{
	///Limpiamos pantalla
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glDisable(GL_TEXTURE_2D);
    glColor3f(0.0f, 1.0f, 0.0f);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.0f);
    glEnd();

    Textura(img.m_ObjetoTextura, 0, 0);
    Textura(img2.m_ObjetoTextura, -8, -8);

    Sprite s;
    s.Load();
}

