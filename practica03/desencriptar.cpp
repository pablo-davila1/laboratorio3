#include "desencriptar.h"

desencriptar::desencriptar(int _cemilla, string _txt)
{
    cemilla = _cemilla;
    txt = _txt;

}
/*
 * este metodo recive la cemilla de encriptacion y el binario encriptado,
 * retorna un string desencriptado en lenguaje binario.
*/
string desencriptar::desencriptado(int _cemilla, string _txt)
{
    char Metodo = _txt[_txt.length() -1];
    int one=0, cero =0,copyone=0, copycero=0;
    string encr = "", copyencr = "";

    for (int i = 0; i < _cemilla ; i++){
        copyencr += '0';
    }

    if (Metodo == 'a'){
        for (int i = 0; i < _txt.length() -1 ; i += _cemilla){
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
            }
            for (int i = 0; i< copyencr.length() ; i++){
                if (copyencr[i] == '1')
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
    }
    else{
        for (int i = 0; i < _txt.length()-1 ; i += _cemilla){
            for(int j = 1 ; j<_cemilla  ; j++){

                if (j==_cemilla -1){
                    encr+= _txt[i+j];
                    encr+= _txt[i];
                }
                else
                    encr+= _txt[j+i];
            }
        }
    }

    return encr;
}
