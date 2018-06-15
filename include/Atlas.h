#ifndef ATLAS_H
#define ATLAS_H
#include <vector>
#include <cstring>
#include <iostream>
///Pagina que se usara para crear el atlas https://www.leshylabs.com/apps/sstool/

class Atlas
{
    public:
        Atlas();
        virtual ~Atlas();
        void Read();

    protected:
        char* nombre;
        float TopX;
        float TopY;
        float Width;
        float height;


    private:
        std::vector <std::string> Nom;
        std::vector <float> tX;
        std::vector <float> tY;
        std::vector <float> tW;
        std::vector <float> tH;
};

#endif // ATLAS_H
