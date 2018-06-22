#include "SDL_image.h"
#include "RenderGL.h"
#include <GL\GLU.h>
#include <GL/glu.h>
#include "SevenUp.h"
#include "RenderGL.h"

Sprite::Sprite()
{
    rotz = 0;
    scaX = 1.0f;
    scaY = 1.0f;
    priZ = 0;
    posX = 0;
    posY = 0;
    uvX = 0;
    uvXX = 1;
    uvY = 0;
    uvYY = 1;
};

Sprite::~Sprite()
{

};

///Definimos la imagen a cargar
void Sprite::Load(const char* archivo)
{
    img.LoadImg(archivo);
    img.InitOGL();
}

///Definimos la posicion de la imagen
void Sprite::SetPos(float x, float y)
{
    posX = x;
    posY = y;
}

///Definimos la rotacion de la imagen
void Sprite::SetRot(float z)
{
    rotz = z;
}

///Definimos la escala de la imagen
void Sprite::SetScale(float x, float y)
{
    scaX = x;
    scaY = y;
}

///Definimos la rpioridad de la imagen
void Sprite::SetPriority(float z)
{
    priZ = z;
}

void Sprite::Draw()
{
    glPushMatrix();
    glTranslatef(posX, posY, priZ);

    ///Se dibuja la textura
    glColor3f(1.0f, 1.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, img.m_ObjetoTextura);
    glRotatef(rotz, 0, 0, 1);

    glBegin(GL_QUADS);
    ///Dibuja coordenadas y escalas de los vertices
    glTexCoord2f(uvXX, uvYY); glVertex3f(scaX, 0, 0);
    glTexCoord2f(uvX, uvYY); glVertex3f(0, 0, 0);
    glTexCoord2f(uvX, uvY); glVertex3f(0, scaY, 0);
    glTexCoord2f(uvXX, uvY); glVertex3f(scaX, scaY, 0);
    /*glTexCoord2f(1, 1); glVertex3f(scaX, 0, 0);
    glTexCoord2f(0, 1); glVertex3f(0, 0, 0);
    glTexCoord2f(0, 0); glVertex3f(0, scaY, 0);
    glTexCoord2f(1, 0); glVertex3f(scaX, scaY, 0);*/
    glEnd();
    glPopMatrix();
}

void Sprite::Close()
{
    img.CloseImg();
}
