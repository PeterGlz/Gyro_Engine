#ifndef HTTPR_H
#define HTTPR_H

#include <string>
#include <windows.h>
#include <stdio.h>

///Agregar estas librerias en main.cpp
/*
#include <windows.h>
#include "include/httpR.h"
*/

///Agregar esto antes del main
/*
HINSTANCE hInst;
WSADATA wsaData;
httpR lector;
*/

///Agregar esto en el main
/*
const int bufLen = 1024;
    char *szUrl = "http://google.com";
    long fileSize;
    char *memBuffer, *headerBuffer;
    FILE *fp;

    memBuffer = headerBuffer = NULL;

    if ( WSAStartup(0x101, &wsaData) != 0)
        return -1;

    memBuffer = lector.readUrl2(szUrl, fileSize, &headerBuffer);
    printf("returned from readUrl\n");
    printf("data returned:\n%s", memBuffer);
    if (fileSize != 0)
    {
        printf("Got some data\n");
        fp = fopen("downloaded.file", "wb");
        fwrite(memBuffer, 1, fileSize, fp);
        fclose(fp);
         delete(memBuffer);
        delete(headerBuffer);
    }

    WSACleanup();
*/

using std::string;

class httpR
{
    public:
        httpR();
        virtual ~httpR();
        void mParseUrl(char *mUrl, string &serverName, string &filepath, string &filename);
        SOCKET connectToServer(char *szServerName, WORD portNum);

        int getHeaderLength(char *content);
        char* readUrl2(char *szUrl, long &bytesReturnedOut, char **headerOut);


    protected:

    private:
};

#endif // HTTPR_H
