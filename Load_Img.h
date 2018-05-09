#ifndef LOAD_IMG_H_INCLUDED
#define LOAD_IMG_H_INCLUDED

#include "SDL_image.h"
#include <string>

///void RenderGL::inicializar()
/*
//Definimos la imagen a cargar
img.LoadImg("mojado.jpg");
img2.LoadImg("mojado2.jpg");

//Cargamos la textura y le asignamos la imagen a cargar
img.InitOGL();
img2.InitOGL();
*/

///void RenderGL::liberar()
/*
//Cerramos la imagen
img.CloseImg();
img2.CloseImg();
*/

///void Textura (unsigned int hola, int x, int y)
/*
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
*/

///void RenderGL::render()
/*
glDisable(GL_TEXTURE_2D);
glColor3f(0.0f, 1.0f, 0.0f);
glPointSize(5.0f);
glBegin(GL_POINTS);
glVertex2f(0.0f, 0.0f);
glEnd();

Textura(img.m_ObjetoTextura, 0, 0);
Textura(img2.m_ObjetoTextura, -8, -8);
*/

class Imagen
{
     public:
        Imagen();
        virtual ~Imagen();

        static void InitImg();
        void LoadImg (std::string img);
        void InitOGL();
        void CloseImg ();

         SDL_Surface * image;
         SDL_Texture * texture;
         unsigned int m_ObjetoTextura;

    private:
};

#endif // LOAD_IMG_H_INCLUDED
