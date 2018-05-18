#ifndef AUDIO_H
#define AUDIO_H
#include "SDL_mixer.h"
#include "SDL.h"
#include <string>
#include <stdio.h>

///Para usar la clase Audio declaras una variable Audio
///Hay dos funciones sonido y musica
///Se debe poner el audio en la carpeta de Resources
///En ambas se tiene que poner el nombre del archivo de audio con su extension
///Ejemplo declarando un sonido:   Audio().sonido("rombos.mp3")
///Ejemplo declarando musica:   Audio().musica("M1.mp3")
///En ambos ejemplos se puede en vez de Audio() poner la variable que declaraste como Audio



class Audio
{
    public:
        Audio();
        virtual ~Audio();

        Mix_Music *gMusic = NULL;
        Mix_Chunk *gSound = NULL;




 void musica (const char* nombre);
void sonido (const char* nombre);









    protected:

    private:


};

#endif // AUDIO_H
