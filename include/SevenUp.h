#ifndef SEVENUP_H_INCLUDED
#define SEVENUP_H_INCLUDED


class Sprite
{
    public:
        Sprite();
        virtual ~Sprite();
        void Textura();
        /*float x;
        float y;
        float z;*/
        void Load();
        void SetPos(float x,float y);
        void SetRot(float z);
        void SetScale(float x, float y);
        void SetPriority(float z);
        void Draw();
};


#endif // SEVENUP_H_INCLUDED
