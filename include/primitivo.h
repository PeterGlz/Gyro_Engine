#ifndef PRIMITIVO_H_INCLUDED
#define PRIMITIVO_H_INCLUDED

#include <cmath>

///Funcion dibujar linea
            ///coordenadas X y Y 1          Coordenadas X y Y 2         Colores RGB
void DibLinea(float coorX1, float coorX2, float coorY1, float coorY2, float colR, float colG, float colB)
{
    if(colR==0 && colG==0 && colB==0)
    {
        colR = 1.0;
        colG = 1.0;
        colB = 1.0;
    }
    glPushMatrix();
        glColor3f(colR, colG, colB);
        glBegin(GL_LINES);
            glVertex2d(coorX1, coorX2);
            glVertex2d(coorY1, coorY2);
        glEnd();
    glPopMatrix();
}

///Funcion dibujar triangulo
                ///Traslacion en X y Y    Rotacion     Colores RGB                        Escala
void DibTriangulo(float traX, float traY, float rot, float colR, float colG, float colB, float esca)
{
    if(esca==0)
    {
        esca=1;
    }
    if(colR==0 && colG==0 && colB==0)
    {
        colR = 1.0;
        colG = 1.0;
        colB = 1.0;
    }
    glPushMatrix();
        glTranslatef(traX, traY, 0.0f);
        glRotatef(rot, 0.0f, 0.0f, 1.0f);
        glColor3f(colR, colG, colB);
        glScalef(esca, esca, 1.0f);
        glBegin(GL_TRIANGLES);
            glVertex3f(0.0f, 0.1f, 0.0f);
            glVertex3f(-0.1f, -0.1f, 0.0f);
            glVertex3f(0.1f, -0.1f, 0.0f);
        glEnd();
    glPopMatrix();
}

///Funcion dibujar rectangulo
                 ///Traslacion en X y Y    Rotacion     Colores RGB                        Escala
void DibRectangulo(float traX, float traY, float rot, float colR, float colG, float colB, float esca)
{
    if(esca==0)
    {
        esca=1;
    }
    if(colR==0 && colG==0 && colB==0)
    {
        colR = 1.0;
        colG = 1.0;
        colB = 1.0;
    }
    glPushMatrix();
        glTranslatef(traX, traY, 0.0f);
        glRotatef(rot, 0.0f, 0.0f, 1.0f);
        glColor3f(colR, colG, colB);
        glScalef(esca, esca, 1.0f);
        glBegin(GL_POLYGON);
            glVertex3f(-0.1f, 0.1f, 0.0f);
            glVertex3f(0.1f, 0.1f, 0.0f);
            glVertex3f(0.1f, -0.1f, 0.0f);
            glVertex3f(-0.1f, -0.1f, 0.0f);
        glEnd();
    glPopMatrix();
}

///Funcion dibujar circulo
            ///Posicion X y Y           Radio        Colores RGB
void DibCirculo(float posx, float posy, float rad, float colR, float colG, float colB)
{
    if(rad==0)
    {
        rad=0.1;
    }
    if(colR==0 && colG==0 && colB==0)
    {
        colR = 1.0;
        colG = 1.0;
        colB = 1.0;
    }
    glPushMatrix();
        const int seg = 64;
        glTranslatef(posx, posy, 0.0f);
        glColor3f(colR, colG, colB);
        glBegin(GL_TRIANGLE_FAN);
        for (int i = 0; i <= seg; i++)
        {
            float theta = M_PI * 2.0f * float(i) / float(seg);
            float x = rad * cosf(theta);
            float y = rad * sinf(theta);
            glVertex3f(x, y, 0.0f);
        }
        glEnd();
    glPopMatrix();
}

///Funcion dibujar circulo
             ///Posicion X y Y           Radio      Segmentos  Rotacion     Colores RGB
void DibPoligono(float posx, float posy, float rad, int seg, float rot, float colR, float colG, float colB)
{
    if(rad==0)
    {
        rad=0.1;
    }
    if(colR==0 && colG==0 && colB==0)
    {
        colR = 1.0;
        colG = 1.0;
        colB = 1.0;
    }
    glPushMatrix();
        glTranslatef(posx, posy, 0.0f);
        glRotatef(rot, 0.0f, 0.0f, 1.0f);
        glColor3f(colR, colG, colB);
        glBegin(GL_TRIANGLE_FAN);
        for (int i = 0; i < seg; i++)
        {
            float theta = M_PI * 2.0f * float(i) / float(seg);
            float x = rad * cosf(theta);
            float y = rad * sinf(theta);
            glVertex3f(x, y, 0.0f);
        }
        glEnd();
    glPopMatrix();
}

#endif // PRIMITIVO_H_INCLUDED
