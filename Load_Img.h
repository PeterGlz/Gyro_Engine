#ifndef LOAD_IMG_H_INCLUDED
#define LOAD_IMG_H_INCLUDED

#include "SDL_image.h"
#include <string>

class Imagen{

     public:
        Imagen();
        virtual ~Imagen();

        static void InitImg();
        void LoadImg (std::string img);
        void CloseImg ();

         SDL_Surface * image;
         SDL_Texture * texture;

    private:



};

#endif // LOAD_IMG_H_INCLUDED
