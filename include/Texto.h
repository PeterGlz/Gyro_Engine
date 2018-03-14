#ifndef TEXTO_H
#define TEXTO_H

#include <string>
#include <GL/gl.h>
#include "SDL.h"

class Texto
{
    public:
        Texto();
        virtual ~Texto();
        ///Inicializa texto
        void Init(const std::string &message, float r, float g, float b, float tam = 0.005f );
        ///Asignamos posicon
        void SetPos(float _x, float _y);
        ///Dibujar
        void Dibujar();

    private:
        ///Crea la textua y la pasa a OpenGL
        SDL_Surface* CrearTextura(const std::string &message, SDL_Color color);

		unsigned int textureID = 0; ///ID de la textura
		SDL_Surface* textoSurface; ///Texto en textura
		///Tamaño y posicion del texto
		float sizeW;
		float sizeH;
		float posX;
		float posY;
};

#endif // TEXTO_H
