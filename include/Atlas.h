#ifndef ATLAS_H
#define ATLAS_H
#include <vector>
#include <cstring>
#include <iostream>
#include "SevenUp.h"

///Pagina que se usara para crear el atlas https://www.leshylabs.com/apps/sstool/


class Atlas
{
    public:
        Atlas();
        virtual ~Atlas();
        void Read();
        void Init7up(Sprite* fresca, int index);
        void Load(const char* archivo);

    protected:
        char* nombre;
        float TopX;
        float TopY;
        float Width;
        float height;
        Imagen img;


    private:
        std::vector <std::string> Nom;
        std::vector <float> tX;
        std::vector <float> tY;
        std::vector <float> tW;
        std::vector <float> tH;
};

#endif // ATLAS_H
