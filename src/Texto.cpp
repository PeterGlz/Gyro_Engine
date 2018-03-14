#include "Texto.h"
#include "RenderGL.h"

///Para usar declarar una variable del tipo: Texto MiTexto;
///Inicializar con: MiTexto.Init("Esto es un texto", 1.0f, 1.0f, 0.0f); ///Texto, color
///Asignar posicion: MiTexto.SetPos(x, y);
/// En render solo llamar MiTexto.Dibujar();

Texto::Texto()
{
    posX= 0.0f;
    posY= 0.0f;
}

Texto::~Texto()
{
    SDL_FreeSurface( textoSurface );
}

void Texto::Init(const std::string &message, float r, float g, float b, float tam)
{
    ///Creamos color
    int red = r * 255;
    int green = g * 255;
    int blue = b * 255;
    SDL_Color color = {red, green, blue};
    ///Creamos textura
    textoSurface = CrearTextura(message, color);
    ///Lo hacemos compatible con textura
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textoSurface->w, textoSurface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, textoSurface->pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    sizeW= textoSurface->w * tam;
    sizeH= textoSurface->h * tam;
}

void Texto::SetPos(float _x, float _y)
{
    posX = _x;
    posY = _y;
}

void Texto::Dibujar()
{
    ///Indicamos que usaremos nuestra texura
    glBindTexture(GL_TEXTURE_2D, textureID);
    ///Dibujamos
    glBegin(GL_QUADS);
    {
        glTexCoord2f(0,1); glVertex2f(posX, posY);
        glTexCoord2f(1,1); glVertex2f(posX + sizeW, posY);
        glTexCoord2f(1,0); glVertex2f(posX + sizeW, posY + sizeH);
        glTexCoord2f(0,0); glVertex2f(posX, posY + sizeH);
    }
    glEnd();
}

SDL_Surface* Texto::CrearTextura(const std::string &message, SDL_Color color)
{
    ///Creamos Surface,, no existe fuga porque se libera en el destructor
    SDL_Surface *surf = TTF_RenderText_Blended(g_renderGL.gFont, message.c_str(), color);
    if (surf == NULL)
    {
        return NULL;
    }

    return surf;
}
