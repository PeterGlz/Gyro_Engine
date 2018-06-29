#include "Atlas.h"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "RenderGL.h"

using namespace std;

Atlas::Atlas()
{
    //ctor
};

Atlas::~Atlas()
{
    //dtor
};

void Atlas::Init7up(Sprite* fresca, int index)
{
    fresca->img = img;
    fresca->uvX = tX[index];
    fresca->uvY = tY[index];
    fresca->uvXX = tX[index]+tW[index];
    fresca->uvYY = tY[index]+tH[index];
}

void Atlas::Load(const char* archivo)
{
    img.LoadImg(archivo);
    img.InitOGL();
    ww = (float)img.image->w;
    hh = (float)img.image->h;
}

void Atlas::Read(const char* textoA)
{
    ifstream myfile (textoA);
    char* pch;
    string line;
    char* nombre;
    float topX;
    float topY;
    float width;
    float height;

      if (myfile.is_open())
      {
        while ( getline (myfile,line) )
        {
            int contador = 0;
            char *y = new char[line.length() + 1];
            std::strcpy(y, line.c_str());
            pch = strtok (y, ",");
            while (pch != NULL)
            {
                if(contador == 0)
                {
                    nombre = pch;
                    Nom.push_back(nombre);
                }
                else if(contador == 1)
                {
                    topX = atof(pch);
                    topX = topX/ww;
                    tX.push_back(topX);
                }
                else if(contador == 2)
                {
                    topY = atof(pch);
                    topY = topY/hh;
                    tY.push_back(topY);
                }
                else if(contador == 3)
                {
                    width = atof(pch);
                    width = width/ww;
                    tW.push_back(width);
                }
                else if(contador == 4)
                {
                    height = atof(pch);
                    height = height/hh;
                    tH.push_back(height);
                }
                contador++;
                pch = strtok (NULL, ",");
            }
            delete[] y;
        }
        myfile.close();
      }
      else cout << "Unable to open file";
}
