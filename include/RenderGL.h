#ifndef RENDERGL_H
#define RENDERGL_H
#include "VectorMath.h"
#include "SDL_ttf.h"
#include "../Load_Img.h"
#include "SevenUp.h"
#include "Atlas.h"

class RenderGL
{
    private:
        float clipAreaXLeft;
		float clipAreaYTop;
		float clipAreaXRightt;
		float clipAreaYBottom;

	public:
		RenderGL();
		~RenderGL();
		int long tiempoA;
		int long tiempoB;

		///Funcion encarga de inicializar OpenGL
		///Regresa True si se inicio correctamente o false en caso cotrario
		void inicializar();
		///Se llama al momento de libarse
		void liberar();

		///Funcion que se actualiza cada frame
		void update();
		///Funcion encargado de dibujar
		void render();

		SDL_Renderer* renderSDL; ///Rendere de SDL para usar con texto
        TTF_Font *gFont = NULL; ///Fuente global
		int h;
		int w;

		int screenH = 600;
        int screenW = 800;

		double deltaTime;

        float hh;
		float ww;

        float WorldSize;
        float offsetMouseX;
        float offsetMouseY;

        Atlas atl1;
        Atlas atl2;
        Sprite poke;
        Sprite lick;
        Sprite geng;
        Sprite nine;
        Sprite chori;
        Sprite onix;
        Sprite bola;
        Sprite poke2;
        Sprite lick2;
        Sprite geng2;
        Sprite nine2;
        Sprite chori2;
        Sprite onix2;
        Sprite bola2;
        Sprite ditto1;
        Sprite ditto2;
        Sprite groudon1;
        Sprite groudon2;
        Sprite Lugiaa1;
        Sprite Lugiaa2;
        Sprite mewtwo1;
        Sprite mewtwo2;
        Sprite racuyaza1;
        Sprite racuyaza2;

        Sprite fondo;

        int protaPosX;
        int protaPosY;

        int balaPosX;
        int balaPosY;

        float misilPosX;
        float misilPosX1;
        float misilPosX2;
        float misilPosX3;
        float misilPosY;
        float misilPosY1;
        float misilPosY2;
        float misilPosY3;

        int fila1;
        int fila2;
        int fila3;
        int fila4;
        int fila5;

        int contEnem;

        int vidaDitto = 100;

        int enemf1 [14] = { };
        int enemf2 [14] = { };
        int enemf3 [14] = { };
        int enemf4 [14] = { };
        int enemf5 [14] = { };

        bool disparo;

        float contador;
        float delay;
        float delayA;
        float delayP;
        float delayP2;
        float delayP3;
        float delay2;
        float delay3;
        float delay4;
};

extern RenderGL g_renderGL; //Singleton

#endif // RENDERGL_H
