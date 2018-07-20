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

        Sprite fondo;

        int protaPosX;
        int protaPosY;
        int balaPosX;
        int balaPosY;

        int misilPosX;
        int misilPoxY;

        int fila1;
        int fila2;
        int fila3;
        int fila4;
        int fila5;

        bool disparo;

        float contador;
        float delay;
        float delayA;
};

extern RenderGL g_renderGL; //Singleton

#endif // RENDERGL_H
