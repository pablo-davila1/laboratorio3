#ifndef DESENCRIPTAR_H
#define DESENCRIPTAR_H
#include <string>
#include <stdlib.h>
using namespace std;


class desencriptar
{
private:
    int cemilla=0;
    string txt ="";

public:
    desencriptar(int, string);
    string desencriptado (int, string);
};

#endif // DESENCRIPTAR_H
