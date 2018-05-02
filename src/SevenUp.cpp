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

void Sprite::Textura (unsigned int hola, int x, int y)
{
    glPushMatrix();
    glTranslatef(x, y, 0);

    ///Se dibuja la textura
    glColor3f(1.0f, 1.0f, 1.0f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, hola);

    glPopMatrix();
}

void Sprite::SetPos(float x, float y)
{
}

void Sprite::Load()
{
    glPushMatrix();
    glBegin(GL_QUADS);
    glTexCoord2f(1, 1); glVertex3f(8, 0, 0);
    glTexCoord2f(0, 1); glVertex3f(0, 0, 0);
    glTexCoord2f(0, 0); glVertex3f(0, 8, 0);
    glTexCoord2f(1, 0); glVertex3f(8, 8, 0);
    glEnd();
    glPopMatrix();
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
    Textura(img.m_ObjetoTextura, 0, 0);
    Textura(img2.m_ObjetoTextura, -8, -8);


}
