#ifndef ENCRIPTAR_H
#define ENCRIPTAR_H
#include <string>
#include <stdlib.h>
using namespace std;

class encriptar
{
private:
    int cemilla=0, metodo=0;
    string txt ="";
public:
    encriptar(int,int,string);
    string encriptado (int,int,string);
};

#endif // ENCRIPTAR_H
