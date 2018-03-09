#ifndef RENDERGL_H
#define RENDERGL_H

#include "VectorMath.h"

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

		///Funcion encarga de inicializar OpenGL
		///Regresa True si se inicio correctamente o false en caso cotrario
		void inicializar();
		///Se llama al momento de libarse
		void liberar();

		///Funcion que se actualiza cada frame
		void update();
		///Funcion encargado de dibujar
		void render();

		///Funcion encargada de cargar imagenees
		void dibujarimg();

		int h;
		int w;
};

extern RenderGL g_renderGL; //Singleton

#endif // RENDERGL_H
