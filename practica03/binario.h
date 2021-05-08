#ifndef BINARIO_H
#define BINARIO_H
#include <string>
#include <stdlib.h>
using namespace std;

class binario
{
private:
    int ascii = 0;
    string bin= "";

public:
    binario(int , string);
    binario(int);
    binario(string);
    string ascii_bin (int);
    string bin_ascii (string);
};

#endif // BINARIO_H
