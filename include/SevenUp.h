#ifndef SEVENUP_H_INCLUDED
#define SEVENUP_H_INCLUDED

#include "../Load_Img.h"

///Ejemplo de cómo dibujar sprites
/*spr.Draw();
spr.SetRot(15);
spr.SetPos(0, 0);
spr.SetScale(5, 5);
spr.SetPriority(0.1f);

spr2.Draw();
spr2.SetRot(-15);
spr2.SetPos(2, 3);
spr2.SetScale(5, 5);
spr2.SetPriority(0.2f);*/

class Sprite
{
    public:
        Sprite();
        virtual ~Sprite();
        void Load(const char* archivo);
        void SetPos(float x,float y);
        void SetRot(float z);
        void SetScale(float x, float y);
        void SetPriority(float z);
        void Draw();
        void Close();
        bool MouseEve(float _x, float _y);

        float coord1;
        float coord2;
        float coord3;
        float coord4;

    private:
        float rotz;
        float scaY;
        float scaX;
        float priZ;
        float posX;
        float posY;
        Imagen img;

        float uvX;
        float uvXX;
        float uvY;
        float uvYY;

        friend class Atlas;
};

#endif // SEVENUP_H_INCLUDED
