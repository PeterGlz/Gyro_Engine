#include "Atlas.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>

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
                     nombre = pch;
                else if(contador == 1)
                    TopX = atof(pch);
                else if(contador == 2)
                    TopY = atof(pch);
                else if(contador == 3)
                    Width = atof(pch);
                else if(contador == 4)
                    height = atof(pch);
                contador++;
                pch = strtok (NULL, ",");
            }
            cout << "Nombre: " << nombre << endl;
            cout << "TopX: " << TopX << endl;
            cout << "TopY: " << TopY << endl;
            cout << "Width: " << Width << endl;
            cout << "Height: " << height << endl;
            delete[] y;
          //cout << line << '\n';
        }
        myfile.close();
      }

      else cout << "Unable to open file";

}
