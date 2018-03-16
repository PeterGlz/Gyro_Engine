#include "SDL_image.h"
#include "RenderGL.h"

void Imagen::InitImg(){
    IMG_Init(IMG_INIT_JPG);

    //SDL_Renderer* renderer = NULL;
}

void Imagen::LoadImg(SDL_Window* gWindow){

    SDL_Window * newWindow;

    newWindow = gWindow;

    //SDL_Renderer * renderer = SDL_CreateRenderer(newWindow, -1, 0);
    g_renderGL.renderSDL;
    SDL_Surface * image = IMG_Load("gato_gordo.jpg");
    SDL_Texture * texture = SDL_CreateTextureFromSurface(g_renderGL.renderSDL, image);

    SDL_RenderCopy(g_renderGL.renderSDL, texture, NULL, NULL);
    //SDL_RenderPresent(renderer);

}

void Imagen::CloseImg(){
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);

    IMG_Quit();
}

