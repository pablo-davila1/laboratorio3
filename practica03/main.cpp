#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <binario.h>
#include <encriptar.h>
#include <desencriptar.h>

using namespace std;

void escribir(string, string);
string leer(string);

int main()
{

    int problema = 1;

    while (problema != 0){

        cout<<"·___________________________________________·"<<endl;
        cout<<"|          Menu de la practica 2            |"<<endl;
        cout<<"º-------------------------------------------º"<<endl;
        cout<<"|Para crear un archivo presione 1 (1)       |"<<endl;
        cout<<"|Para desencriptar un archivo presione 2 (2)|"<<endl;
        cout<<"|Para Usar el banco presione 4 (4)          |"<<endl;
        cout<<"|Para salir presione (0)                    |"<<endl;
        cout<<"---------------------------------------------"<<endl;
        cin>>problema;
        cin.ignore();

        switch (problema) {
            case 1:{
                string contenido = "",nombre_out = "",nombre_in = "", bin="", bin_en="";
                binario txtbin(0);
                encriptar _out(0,0,"");
                int cemilla = 0, metodo=0;

                cout<<"Por favor ingrese un nombre para el archivo de texto sin codificar: ";
                getline(cin,nombre_in);

                cout<<"Por favor ingrese un nombre para el archivo de texto codificado: ";
                getline(cin,nombre_out);

                cout<<"Por favor ingrese el contenido texto: ";
                getline(cin,contenido);

                cout<<"Por favor ingrese la cemilla de encriptacio: ";
                cin>>cemilla;

                cout<<"Por favor ingrese el metodo de encriptacio: ";
                cin>>metodo;
                cin.ignore();

                for (int i = 0 ; i < contenido.length() ; i++){
                    bin += txtbin.ascii_bin(contenido[i]); // bin = contenido en binario.
                }

                escribir(nombre_in,bin);

                bin_en =_out.encriptado(cemilla, metodo, bin);

                escribir(nombre_out, bin_en);

            }

            case 2:{



            }
        }
    }




    return 0;
}
















void escribir(string nombre, string bin){
    ofstream prueba;

    prueba.open("/home/juan/practica03/"+nombre, ios::out);

    if (prueba.fail()){
        cout<<"No se pudo abrir el archivo."<<endl;
        exit(1);
    }
    prueba<<bin;

    prueba.close();

}
