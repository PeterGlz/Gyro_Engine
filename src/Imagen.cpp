#include "SDL_image.h"
#include "RenderGL.h"

#include "../Load_Img.h"

Imagen::Imagen(){
};

Imagen::~Imagen(){
};

void Imagen::InitImg(){

    ///Inicializa la imagen
    IMG_Init(IMG_INIT_JPG);

}

void Imagen::LoadImg(){

    ///Carga la imagen
    image = IMG_Load("Recursos/mojado.jpg");
    texture = SDL_CreateTextureFromSurface(g_renderGL.renderSDL, image);

    SDL_RenderCopy(g_renderGL.renderSDL, texture, NULL, NULL);

    SDL_RenderPresent(g_renderGL.renderSDL);

}

void Imagen::CloseImg(){

    ///Se libera la textura y surface
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);

    IMG_Quit();
}

