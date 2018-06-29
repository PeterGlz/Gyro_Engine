#ifndef ATLAS_H
#define ATLAS_H
#include <vector>
#include <cstring>
#include <iostream>
#include "SevenUp.h"

///Pagina que se usara para crear el atlas https://www.leshylabs.com/apps/sstool/
///Primero debemos cargar la imagen, aqui abajo esta el tutorial de como declarar para usar un Atlas
///Esto va en Inicializar
/*atl1.Load("gatoDavid.png");
atl1.Read("sprites.txt");
atl1.Init7up(&gato, 0);*/
///Esto va en el render
/*gato.SetRot(0);
gato.SetPos(0, 0);
gato.SetScale(10, 10);
gato.SetPriority(0.1f);
gato.Draw();*/

class Atlas
{
    public:
        Atlas();
        virtual ~Atlas();
        void Read(const char* textoA);
        void Init7up(Sprite* fresca, int index);
        void Load(const char* archivo);

    protected:
        Imagen img;

    private:
        std::vector <std::string> Nom;
        std::vector <float> tX;
        std::vector <float> tY;
        std::vector <float> tW;
        std::vector <float> tH;

        float hh;
        float ww;


};

#endif // ATLAS_H
