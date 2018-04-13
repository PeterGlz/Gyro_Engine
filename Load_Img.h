#include "SDL_image.h"

#ifndef LOAD_IMG_H_INCLUDED
#define LOAD_IMG_H_INCLUDED

class Imagen{

     public:
        Imagen();
        virtual ~Imagen();

        static void InitImg();
        void LoadImg ();
        void CloseImg ();

         SDL_Surface * image;
         SDL_Texture * texture;

    private:



};

#endif // LOAD_IMG_H_INCLUDED
