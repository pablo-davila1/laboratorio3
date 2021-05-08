#include "binario.h"
#include <string>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

binario::binario(int _ascii, string _bin)
{
    ascii = _ascii;
    bin = _bin;

}

binario::binario(int _ascii)
{
    ascii = _ascii;
}

binario::binario(string _bin)
{
    bin = _bin;
}

/*
 * este metodo convierte un numero entero es su representacion
 * a lenguaje binario
*/
string binario::ascii_bin(int _ascii)
{
    bin="";
    while(_ascii > 0){
        if (_ascii%2 == 0 )
            bin += "0";
        else
            bin += "1";

        _ascii= _ascii/2;

    }

    string bin2="";
    for (int i=bin.length() -1 ; i >= 0 ; i-- ){
        bin2 += bin[i];
    }
    while(bin2.length() < 8){
        bin2.insert(0,"00000000",8 - bin.length());
    }

    return bin2;

}

/*
 * este metodo comvierte un byte en un numero decimal
*/
string binario::bin_ascii(string _bin)
{
    string byts = "";
    int letter=0,c=0;
    for (int i = 0; i < _bin.length() ; i+=8){
        for(int j = 7 ; j>=0 ; j--){
            if(_bin[i+j] == '1')
                letter += pow(2,c);
            else
                letter+=0;

            c++;
        }
        byts += letter;
        letter=0;
        c=0;

    }

    return byts;

}
