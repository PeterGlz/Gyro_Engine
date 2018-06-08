#include "Atlas.h"
#include <iostream>
#include <fstream>
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
  string line;
  ifstream myfile ("sprites.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file";

}
