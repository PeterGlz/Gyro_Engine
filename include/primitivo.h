#ifndef PRIMITIVO_H_INCLUDED
#define PRIMITIVO_H_INCLUDED

#include <cmath>

///Ejemplos para llamar a las funciones y dibujar las primitivas
/*DibLinea(-2, 1, 0, 1);
DibTriangulo(1, -1, 0);
DibRectangulo(-1, -1, 0);
DibCirculo(1, 1);
DibPoligono(3, -1, 1, 5);
DibPoligono(3, 1, 1, 6);
DibPoligono(-3, 1, 1, 7);
DibPoligono(-3, -1, 1, 8);*/

/*DibCirculo(-10, 8, 0, 1, 1, 0.2, 0, 0);
DibCirculo(-4, 7, 0, 1, 1, 1, 3, 0);
DibCirculo(-1, 6, 0, 1, 1, 1, 3, 0);
DibCirculo(6, 6, 0, 1, 1, 1, 3, 0);
DibCirculo(9, 5, 0, 1, 1, 1, 3, 0);
DibLinea(-20, -3, 20, -3, 0, 1, 0);
DibRectangulo(5, -1, 0, 0, 1, 1, 2, 2);
DibTriangulo(5, 3, 0, 1, 0, 0, 3, 2);
DibRectangulo(-8, -1, 0, 0.36, 0.25, 0.2, 0.5, 2);
DibPoligono(-8, 2, 2, 7, 0, 0, 1, 0);*/

///Funcion dibujar linea
            ///coordenadas X y Y 1          Coordenadas X y Y 2         Colores RGB
void DibLinea(float coorX1, float coorX2, float coorY1, float coorY2, float colR = 1.0f, float colG = 1.0f, float colB = 1.0f)
{
    glPushMatrix();
        glColor3f(colR, colG, colB);
        glBegin(GL_LINES);
            glVertex2d(coorX1, coorX2);
            glVertex2d(coorY1, coorY2);
        glEnd();
    glPopMatrix();
}

///Funcion dibujar triangulo
                ///Traslacion en X y Y    Rotacion     Base             Altura      Colores RGB
void DibTriangulo(float traX, float traY, float rot, float base = 1.0f, float alto = 1.0f, float colR = 1.0f, float colG = 1.0f, float colB = 1.0f)
{
    glPushMatrix();
        glTranslatef(traX, traY, 0.0f);
        glRotatef(rot, 0.0f, 0.0f, 1.0f);
        glColor3f(colR, colG, colB);
        glScalef(base, alto, 1.0f);
        glBegin(GL_TRIANGLES);
            glVertex3f(0.0f, 1.0f, 0.0f);
            glVertex3f(-1.0f, -1.0f, 0.0f);
            glVertex3f(1.0f, -1.0f, 0.0f);
        glEnd();
    glPopMatrix();
}

///Funcion dibujar rectangulo
                 ///Traslacion en X y Y    Rotacion     Base                Altura              Colores RGB
void DibRectangulo(float traX, float traY, float rot, float base = 1.0f, float alto = 1.0f, float colR = 1.0f, float colG = 1.0f, float colB = 1.0f)
{
    glPushMatrix();
        glTranslatef(traX, traY, 0.0f);
        glRotatef(rot, 0.0f, 0.0f, 1.0f);
        glColor3f(colR, colG, colB);
        glScalef(base, alto, 1.0f);
        glBegin(GL_POLYGON);
            glVertex3f(-1.0f, 1.0f, 0.0f);
            glVertex3f(1.0f, 1.0f, 0.0f);
            glVertex3f(1.0f, -1.0f, 0.0f);
            glVertex3f(-1.0f, -1.0f, 0.0f);
        glEnd();
    glPopMatrix();
}

///Funcion dibujar circulo
            ///Posicion X y Y           Radio               Base                ltura               Colores RGB
void DibCirculo(float posx, float posy, float rad = 1.0f, float base = 1.0f, float alto = 1.0f, float colR = 1.0f, float colG = 1.0f, float colB = 1.0f)
{
    glPushMatrix();
        const int seg = 64;
        glTranslatef(posx, posy, 0.0f);
        glColor3f(colR, colG, colB);
        glScalef(base, alto, 1.0f);
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
             ///Posicion X y Y          Segmentos  Rotacion     Radio            Colores RGB
void DibPoligono(float posx, float posy, int seg, float rot, float rad = 1.0f, float colR = 1.0f, float colG = 1.0f, float colB = 1.0f)
{
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
