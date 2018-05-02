#ifndef SEVENUP_H_INCLUDED
#define SEVENUP_H_INCLUDED

#include "../Load_Img.h"

class Sprite
{
    public:
        Sprite();
        virtual ~Sprite();
        void Textura(unsigned int hola, int x, int y);
        /*float x;
        float y;
        float z;*/
        void Load();
        void SetPos(float x,float y);
        void SetRot(float z);
        void SetScale(float x, float y);
        void SetPriority(float z);
        void Draw();


		Imagen img;
		Imagen img2;

        unsigned int m_ObjetoTexturaDOS;
};


#endif // SEVENUP_H_INCLUDED
