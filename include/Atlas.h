#ifndef ATLAS_H
#define ATLAS_H
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
};

#endif // ATLAS_H
