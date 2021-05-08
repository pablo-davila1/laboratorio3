#include "encriptar.h"

encriptar::encriptar(int _cemilla, int _metodo, string _txt)
{
    cemilla = _cemilla;
    metodo = _metodo;
    txt = _txt;
}

/*
 *este meodo recibe la cemilla, el metodo y el binario a encriptar,
 *retorna un string con el binario encriptado.
*/
string encriptar::encriptado(int _cemilla, int _metodo, string _txt)
{
    int one=0, cero =0,copyone=0, copycero=0;
    string encr = "", copyencr = "";

    for (int i = 0; i < _cemilla ; i++){
        copyencr += '0';
    }
    if (_metodo == 1){

        for (int i = 0; i < _txt.length() ; i += _cemilla){
            for(int j = _cemilla -1 ; j>=0 ; j--){
                    if((copyone == 0) && (copycero == 0)){
                        if(_txt[i+j] == '1')
                            copyencr[j] = '0';
                        else
                            copyencr[j] = '1';
                    }
                    if(copyone==copycero){
                        if(_txt[i+j] == '1')
                            copyencr[j] = '0';
                        else
                            copyencr[j] = '1';
                    }
                    else if((copyone > copycero) && (j+1)%3 == 0  ){
                        if(_txt[i+j] == '1')
                            copyencr[j]= '0';
                        else
                            copyencr[j] = '1';
                    }
                    else if((copyone > copycero) && (j+1)%3 != 0){
                        if(_txt[i+j] == '1')
                            copyencr[j] = '1';
                        else
                            copyencr[j]= '0';
                    }
                    else if((copyone < copycero) && (j+1)%2 == 0 ){
                        if(_txt[i+j] == '1')
                            copyencr[j]= '0';
                        else
                            copyencr[j]= '1';
                    }
                    else if((copyone < copycero) && (j+1)%2 != 0 ){
                        if(_txt[i+j] == '1')
                            copyencr[j] = '1';
                        else
                            copyencr[j] = '0';
                    }

                    if(_txt[i+j] == '1')
                        one++;
                    else
                        cero++;
            }
            encr+= copyencr;
            copyone = one;
            copycero = cero;

            one=0;
            cero=0;
        }

        encr += 'a';

    }
    else{
        for (int i = 0; i < _txt.length() ; i += _cemilla){
            for(int j = 0 ; j<_cemilla -1 ; j++){
                if (j==0){
                    encr+= _txt[i + (_cemilla-1)];
                    encr+= _txt[j+i];
                }
                else
                    encr+= _txt[j+i];
            }
        }
        encr += 'b';
    }

    return encr;

}

