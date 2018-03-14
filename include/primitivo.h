#ifndef PRIMITIVO_H_INCLUDED
#define PRIMITIVO_H_INCLUDED

void dibtriangulo(float traX, float traY, float rot, float colR, float colG, float colB, float esca)
{
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

void dibrectangulo()
{
    glPushMatrix();
        glBegin(GL_POLYGON);
            glVertex3f(0.0f, 0.1f, 0.0f);
            glVertex3f(0.1f, 0.1f, 0.0f);
            glVertex3f(0.1f, 0.0f, 0.0f);
            glVertex3f(0.0f, 0.0f, 0.0f);
        glEnd();
    glPopMatrix();
}

#endif // PRIMITIVO_H_INCLUDED
