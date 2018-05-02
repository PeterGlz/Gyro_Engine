#ifndef SEVENUP_H_INCLUDED
#define SEVENUP_H_INCLUDED

#include "../Load_Img.h"

class Sprite
{
    public:
        Sprite();
        virtual ~Sprite();
        /*float x;
        float y;
        float z;*/
        void Load(const char* archivo);
        void SetPos(float x,float y);
        void SetRot(float z);
        void SetScale(float x, float y);
        void SetPriority(float z);
        void Draw();
        void Close();

        Imagen img;


};


#endif // SEVENUP_H_INCLUDED
