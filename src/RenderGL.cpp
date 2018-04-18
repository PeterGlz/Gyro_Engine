#include "RenderGL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>
#include <GL/glu.h>
#include <iostream>



RenderGL g_renderGL; //Singleton

RenderGL::RenderGL()
{
}

RenderGL::~RenderGL()
{
}

void CargarTextura(unsigned int hola2, Imagen Picture){
    glGenTextures(1, &hola2);
    glBindTexture(GL_TEXTURE_2D, hola2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Picture.image->w, Picture.image->h, 0, GL_RGB, GL_UNSIGNED_BYTE, Picture.image->pixels);
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

	//Model view Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/*///Cargamos la textura y le asignamos la imagen a cargar
	glGenTextures(1, &m_ObjetoTexturaUNO);
    glBindTexture(GL_TEXTURE_2D, m_ObjetoTexturaUNO);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img.image->w, img.image->h, 0, GL_RGB, GL_UNSIGNED_BYTE, img.image->pixels);*/

    CargarTextura(m_ObjetoTexturaUNO, img);

}

void RenderGL::liberar()
{
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

void Textura (unsigned int hola, int coord)
{
    ///Se dibuja la textura
    glColor3f(1.0f, 1.0f, 1.0f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, hola);

    glBegin(GL_QUADS);
    glTexCoord2f(1, 1); glVertex3f(8, 0, 0);
    glTexCoord2f(0, 1); glVertex3f(0, 0, 0);
    glTexCoord2f(0, 0); glVertex3f(0, 8, 0);
    glTexCoord2f(1, 0); glVertex3f(8, 8, 0);
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

    Textura(m_ObjetoTexturaUNO, 10);
    Textura(m_ObjetoTexturaDOS, 10);

    glEnd();




}

