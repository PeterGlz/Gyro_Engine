#ifndef HTTPR_H
#define HTTPR_H

#include <string>
#include <windows.h>
#include <stdio.h>

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
