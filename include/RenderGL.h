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
};

extern RenderGL g_renderGL; //Singleton

#endif // RENDERGL_H
