#include "SDL.h"
#include "RenderGL.h"
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>

#include "Load_Img.h"
#include "SevenUp.h"

using namespace std;

//Dimensiones de la ventana
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

//Inicializa SDL, crea ventana y lo liga a openGL
bool init();
//Manejador de teclado con posicion del mouse
void handleKeys(unsigned char _key, int _x, int _y);
//Manejador de mouse
void handleMouse(SDL_Event* _evt, int _x, int _y);

//Liberar media y SDL
void close();

//Referencia a la ventana de windows
SDL_Window* gWindow = NULL;

//Referencia a OpenGl con SDL
SDL_GLContext gContext;

//------CORE ------------------------------------------------------------------------------------

///Teclado
void handleKeys(unsigned char _key, int _x, int _y)
{
	//Toggle quad
	if (_key == 'a')
	{
	     cout << "Inferior Izq: " << g_renderGL.spr2.coord1 << endl;
         cout << "Superior Izq: " << g_renderGL.spr2.coord2 << endl;
         cout << "Superior Der: " << g_renderGL.spr2.coord3 << endl;
         cout << "Inferior Der: " << g_renderGL.spr2.coord4 << endl;
         cout << endl;
	}
}

///Mouse
void handleMouse(SDL_Event* _evt, int _x, int _y)
{
    //if(_x >= g_renderGL.spr2.coord1 && _x >= g_renderGL.spr2.coord2 && _y <= g_renderGL.spr2.coord3 && _y >= g_renderGL.spr2.coord4){

        if(_evt->type == SDL_MOUSEBUTTONDOWN)
        {
            if(_evt->button.button == SDL_BUTTON_LEFT){
                SDL_Log("Mouse Button is pressed.");
            }
        }
   // }

	//Click mouse izq

}

//------ FIN CORE -------------------------------------------------------------------------------


bool init()
{

    ///Inicializamos la imagen
    Imagen::InitImg();


	///Initialization flag
	bool success = true;

	///Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		///Indicamos que usaremos OPenGL
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

		///Iniciamos para escribir texto
        if( TTF_Init() == -1 )
        {
            printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
            return false;
        }
        ///Cargamos fuente
        g_renderGL.gFont = TTF_OpenFont("Recursos/lazy.ttf", 15);

		///Creamos Ventana
		gWindow = SDL_CreateWindow("Toucan Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//SDL_GetRendererOutputSize(gWindow, &g_renderGL.w, &g_renderGL.h);
			g_renderGL.renderSDL = SDL_GetRenderer(gWindow);
			g_renderGL.w= SDL_GetWindowSurface(gWindow)->w;
			g_renderGL.h = SDL_GetWindowSurface(gWindow)->h;

			///Creamos COntexto de OpenGL
			gContext = SDL_GL_CreateContext(gWindow);
			if (gContext == NULL)
			{
				printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				///Activamos VSync
				if (SDL_GL_SetSwapInterval(1) < 0)
				{
					printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
				}

				///Inicializamos OpenGL
				g_renderGL.inicializar();
			}
		}
	}

	return success;
}

void close()
{
    ///Liberaos fuente
    TTF_CloseFont(g_renderGL.gFont);
    TTF_Quit();

	///Liberamos OpenGL
	g_renderGL.liberar();

	///Destruimos ventana
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	///Cerramos SDL
	SDL_Quit();
}

int main(int argc, char* args[])
{
	///Start up SDL and create window
	if (!init())
	{
		printf("Error al inicializar!\n");
	}
	else
	{
		///GameLoop
		bool GameLoop = false;

		///Manejador de evento
		SDL_Event e;

		///Se activa deteccion de teclado
		SDL_StartTextInput();

		///GameLoop
		while (!GameLoop)
		{
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT) ///Salir
				{
					GameLoop = true;
				}
				else if (e.type == SDL_TEXTINPUT) ///Evento de teclado
				{
					int x = 0, y = 0;
					SDL_GetMouseState(&x, &y);
					handleKeys(e.text.text[0], x, y);
				}
				else if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP || e.type == SDL_MOUSEMOTION)
				{
					//obtenemos mouse
					int x = 0, y = 0;
					SDL_GetMouseState(&x, &y);
					handleMouse(&e, x, y);
				}
			}

			///Update
			g_renderGL.update();
			///Dibujamos
			g_renderGL.render();

			///Actualizamos pantalla
			SDL_GL_SwapWindow(gWindow);
		}

		///Desactivamos detectar teclado
		SDL_StopTextInput();
	}

	///Cerramos y desactivamos SDL
	close();

	return 0;
}
