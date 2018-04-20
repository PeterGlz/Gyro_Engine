#include "SDL_image.h"
#include "RenderGL.h"
#include <GL\GLU.h>
#include <GL/glu.h>
#include "../Load_Img.h"

Imagen::Imagen(){
};

Imagen::~Imagen(){
};

void Imagen::InitImg(){

    ///Inicializa la imagen
    IMG_Init(IMG_INIT_JPG);

}

void Imagen::LoadImg(std::string img){

    ///Carga la imagen
    ///image = IMG_Load("Recursos/mojado.jpg");
    std::string pic = "Recursos/" + img;

    image = IMG_Load(pic.c_str());

    texture = SDL_CreateTextureFromSurface(g_renderGL.renderSDL, image);

    SDL_RenderCopy(g_renderGL.renderSDL, texture, NULL, NULL);

    SDL_RenderPresent(g_renderGL.renderSDL);

}

void Imagen::InitOGL(){
    glGenTextures(1, &m_ObjetoTextura);
    glBindTexture(GL_TEXTURE_2D, m_ObjetoTextura);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->w, image->h, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
}

void Imagen::CloseImg(){

    ///Se libera la textura y surface
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);

    IMG_Quit();
}

