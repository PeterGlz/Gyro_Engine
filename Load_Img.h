#include "SDL_image.h"

#ifndef LOAD_IMG_H_INCLUDED
#define LOAD_IMG_H_INCLUDED

class Imagen{

     public:
        Imagen();
        virtual ~Imagen();

        static void InitImg();
        void LoadImg (SDL_Window* gWindow);
        void CloseImg ();

    private:

        SDL_Surface * image;
        SDL_Texture * texture;
};

#endif // LOAD_IMG_H_INCLUDED
