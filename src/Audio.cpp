#include "Audio.h"

Audio::Audio()
{
    //ctor

}

Audio::~Audio()
{
    //dtor
}

void Audio::musica(const char* nombre2)
{

        char buffer[100];
            sprintf(buffer, "Recursos/%s", nombre2 );

        gMusic = Mix_LoadMUS( buffer);


        Mix_PlayMusic( gMusic, -1 );
}

void Audio::sonido(const char* nombre2)
{

        char buffer[100];
            sprintf(buffer, "Recursos/%s", nombre2 );

        gSound = Mix_LoadWAV( buffer);


         Mix_PlayChannel( -1, gSound, 0 );
}
