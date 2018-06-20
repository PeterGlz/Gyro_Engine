#include "Atlas.h"
//#include <iostream>
#include <fstream>
//#include <string.h>
#include <stdio.h>
//#include <cstring>
#include <stdlib.h>
#include <vector>
#include "RenderGL.h"


using namespace std;
///Pagina que se usara para crear el atlas https://www.leshylabs.com/apps/sstool/
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
    fresca->uvX = TopX;
    fresca->uvY = TopY;
    fresca->uvXX = Width;
    fresca->uvYY = height;
}

void Atlas::Load(const char* archivo)
{
    img.LoadImg(archivo);
    img.InitOGL();
}

void Atlas::Read()
{

    ifstream myfile ("sprites.txt");

      char* pch;
    string line;

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
                    //string st = pch;
                    Nom.push_back(nombre);
                }
                else if(contador == 1)
                {
                   TopX = atof(pch);
                   TopX = TopX/g_renderGL.screenW;
                    tX.push_back(TopX);
                }
                else if(contador == 2)
                {
                    TopY = atof(pch);
                    TopY = TopY/g_renderGL.screenH;
                    tY.push_back(TopY);
                }
                else if(contador == 3)
                {
                    Width = atof(pch);
                    Width = Width/g_renderGL.screenW;
                    tW.push_back(Width);
                }
                else if(contador == 4)
                {
                    height = atof(pch);
                    height = height/g_renderGL.screenH;
                    tH.push_back(height);
                }
                contador++;
                pch = strtok (NULL, ",");
            }
            /*cout << "\nSize : " << g1.size();
            cout << "\nCapacity : " << g1.capacity();
            cout << "\nMax_Size : " << g1.max_size();*/


            delete[] y;
          //cout << line << '\n';
        }
        cout << "Nombre: " << Nom[0] << endl;
            cout << "TopX: " << tX[0] << endl;
            cout << "TopY: " << tY[0] << endl;
            cout << "Width: " << tW[0] << endl;
            cout << "Height: " << tH[0] << endl;
        myfile.close();
      }

      else cout << "Unable to open file";

}
