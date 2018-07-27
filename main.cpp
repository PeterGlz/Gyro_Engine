#include "SDL.h"
#include "RenderGL.h"
#include "Audio.h"
#include <stdio.h>
#include <string>
#include <math.h>
#include <iostream>
#include <sstream>
#include "Atlas.h"

using namespace std;

#include "SDL_mixer.h"
#include "Audio.h"


//Dimensiones de la ventana
const int SCREEN_WIDTH = g_renderGL.screenW;
const int SCREEN_HEIGHT = g_renderGL.screenH;


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
	    if(g_renderGL.protaPosX >= -6)
        {
            g_renderGL.protaPosX--;
        }
	}
	if (_key == 'd')
	{
	    if(g_renderGL.protaPosX <= 4)
        {
            g_renderGL.protaPosX++;
        }
	}
	if(_key == 'k')
    {
        g_renderGL.disparo = true;
        g_renderGL.balaPosX = g_renderGL.protaPosX;
    }
}

///Mouse
void handleMouse(SDL_Event* _evt, int _x, int _y)
{
    if(_evt->type == SDL_MOUSEBUTTONDOWN)
    {

        float x = _x/(float)SCREEN_WIDTH * g_renderGL.offsetMouseX * 2 - g_renderGL.offsetMouseX;
        float y = _y/(float)SCREEN_HEIGHT * g_renderGL.offsetMouseY * 2 - g_renderGL.offsetMouseY;
        y = -y;

        if(_evt->button.button == SDL_BUTTON_LEFT)
        {
        }
    }

}

//------ FIN CORE -------------------------------------------------------------------------------
void Prueba()
{
    //std::cout << "Hola";
}

bool init()
{
    Prueba();
    ///Inicializamos la imagen
    Imagen::InitImg();

	///Initialization flag
	bool success = true;

	///Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{

	    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
            success = false;
        }

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
		gWindow = SDL_CreateWindow("Gyro Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
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



	Mix_Quit();
	SDL_Quit();
}

int main(int argc, char* args[])
{
    int long tiempoA = SDL_GetTicks();
    double t = 0.0;

	///Start up SDL and create window
	if (!init())
	{
		printf("Error al inicializar!\n");
	}
	else
	{
	     Audio().musica("Pokemon_Fondo.mp3");

		///GameLoop
		bool GameLoop = false;

		///Manejador de evento
		SDL_Event e;

		///Se activa deteccion de teclado
		SDL_StartTextInput();

		std::cout << tiempoA << std::endl;
		///GameLoop
		while (!GameLoop)
		{
		    int long tiempoB = SDL_GetTicks();
		    g_renderGL.deltaTime = (tiempoB - tiempoA)/1000.0f;

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
			tiempoA = tiempoB;

		}

		///Desactivamos detectar teclado
		SDL_StopTextInput();
	}

	///Cerramos y desactivamos SDL
	close();

	return 0;
}
