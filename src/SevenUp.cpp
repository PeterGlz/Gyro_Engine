#include "SDL_image.h"
#include "RenderGL.h"
#include <GL\GLU.h>
#include <GL/glu.h>
#include "SevenUp.h"

Sprite::Sprite()
{

};

Sprite::~Sprite()
{

};



void Sprite::SetPos(float x, float y)
{
}

void Sprite::Load(const char* archivo)
{
        //Definimos la imagen a cargar
    img.LoadImg(archivo);
    img.InitOGL();
    //img2.LoadImg("mojado2.jpg");
}

void Sprite::SetRot(float z)
{

}

void Sprite::SetScale(float x, float y)
{

}

void Sprite::SetPriority(float z)
{

}

void Sprite::Draw()
{
    glPushMatrix();
    glTranslatef(0, 0, 0);

    ///Se dibuja la textura
    glColor3f(1.0f, 1.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, img.m_ObjetoTextura);

    glBegin(GL_QUADS);
    glTexCoord2f(1, 1); glVertex3f(8, 0, 0);
    glTexCoord2f(0, 1); glVertex3f(0, 0, 0);
    glTexCoord2f(0, 0); glVertex3f(0, 8, 0);
    glTexCoord2f(1, 0); glVertex3f(8, 8, 0);
    glEnd();
    glPopMatrix();


}

void Sprite::Close(){
    img.CloseImg();
}
