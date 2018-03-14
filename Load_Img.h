#include "SDL_image.h"

#ifndef LOAD_IMG_H_INCLUDED
#define LOAD_IMG_H_INCLUDED

void InitImg (){
    IMG_Init(IMG_INIT_JPG);

    //SDL_Renderer* renderer = NULL;
}

void LoadImg (SDL_Window* gWindow){

    SDL_Window * newWindow;

    newWindow = gWindow;

    SDL_Renderer * renderer = SDL_CreateRenderer(newWindow, -1, 0);
    SDL_Surface * image = IMG_Load("gato_gordo.jpg");
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);

    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

}

void CloseImg (){
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);

    IMG_Quit();
}

#endif // LOAD_IMG_H_INCLUDED
