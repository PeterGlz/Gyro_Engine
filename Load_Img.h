#include "SDL_image.h"

#ifndef LOAD_IMG_H_INCLUDED
#define LOAD_IMG_H_INCLUDED

class Imagen{

     public:
        Imagen();
        virtual ~Imagen();

        void InitImg();
        void LoadImg (SDL_Window* gWindow);
        void CloseImg ();

    private:
};

#endif // LOAD_IMG_H_INCLUDED
