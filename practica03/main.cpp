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

bool ingreso (string,string);

bool signin(string, string, int);

bool login(string,string);

//1001111000111011001100100100011010010001000001010110111001101101011011001101010101101111011011110110111101101111a

int main()
{

    int problema = 1;

    while (problema != 0){

        cout<<"·___________________________________________·"<<endl;
        cout<<"|           Menu de la practica 3           |"<<endl;
        cout<<"º-------------------------------------------º"<<endl;
        cout<<"|Para crear un archivo presione 1 (1)       |"<<endl;
        cout<<"|Para desencriptar un archivo presione 2 (2)|"<<endl;
        cout<<"|Para Usar el banco presione 3 (3)          |"<<endl;
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

                cout<<"Por favor ingrese el contenido del texto: ";
                getline(cin,contenido);

                cout<<"Por favor ingrese la cemilla de encriptacion: ";
                cin>>cemilla;

                cout<<"Por favor ingrese el metodo de encriptacion: ";
                cin>>metodo;
                cin.ignore();

                for (int i = 0 ; i < contenido.length() ; i++){
                    bin += txtbin.ascii_bin(contenido[i]); // bin = contenido en binario.
                }

                escribir(nombre_in,bin);

                bin_en =_out.encriptado(cemilla, metodo, bin);

                escribir(nombre_out, bin_en);

                break;

            }

            case 2:{
                string nombre_out = "", contenido= "", traduccion = "", desencr="",desencr2="";
                int cemilla=0;
                cout << "Ingrese el nombre del archivo que quiere desencriptar: ";
                getline(cin,nombre_out);
                cout<<"Ingrese la cemilla con la que encripto el archivo "<<nombre_out<<": ";
                cin>>cemilla;
                cin.ignore();

                contenido = leer(nombre_out);

                desencriptar _in(cemilla,contenido);
                binario _traduccion(contenido);

                desencr=_in.desencriptado(cemilla,contenido);

                cout<<"El archivo desencriptado es: "<<desencr<<endl;

                for(int i=0; i<contenido.length() ; i+=8){
                    for(int j =0; j<8 ; j++){
                        desencr2 += desencr[i+j];
                    }
                    traduccion+=_traduccion.bin_ascii(desencr2);
                    desencr2="";
                }
                cout<<"Traduciendolo a lenguaje alfabetico: "<<traduccion<<endl;
                break;


            }

            case 3:{

            string user="", password="";
            cout<<"Autentifiquese como administrador para usar el banco."<<endl;
            cout<<"Ingrese su usuario: ";
            cin>>user;
            cout<<"Ingrese su contraseña: ";
            cin>>password;

            if (ingreso (user,password)){
                cout<<"·________________·"<<endl;
                cout<<"|   BIENVENIDO   |"<<endl;
                cout<<"º----------------º"<<endl;

                int problemabanco = 1;

                while (problemabanco != 0){

                    cout<<"·___________________________________________·"<<endl;
                    cout<<"|               Menu del Banco              |"<<endl;
                    cout<<"º-------------------------------------------º"<<endl;
                    cout<<"|Iniciar sesion (1)                         |"<<endl;
                    cout<<"|Registrarse (2)                            |"<<endl;
                    cout<<"|Para salir presione (0)                    |"<<endl;
                    cout<<"---------------------------------------------"<<endl;
                    cin>>problemabanco;
                    cin.ignore();

                    switch (problemabanco) {
                        case 2:{
                        string user="",password="";
                        int money=0;
                        cout<<"Ingrese un nombre: ";
                        cin>>user;
                        cout<<"Ingrese una contraseña: ";
                        cin>>password;
                        cout<<"¿Cuanto dinero va a deposita en su nueva cuenta?: ";
                        cin>>money;
                        signin(user, password, money);


                        break;
                        }
                    }
                    }
            }
            else{
                cout<<"contraseña o usuario incorrecto."<<endl;
            }


            break;
            }
        }
    }




    return 0;
}




void escribir(string nombre, string bin){
    ofstream archivo_w;

    archivo_w.open("/home/juan/practica03/"+nombre, ios::out );

    if (archivo_w.fail()){
        cout<<"No se pudo abrir el archivo."<<endl;
        exit(1);
    }
    archivo_w<<bin;
    archivo_w<<"\n";

    archivo_w.close();

}

string leer(string nombre_out){
    ifstream archvo_r;
    string texto1="",texto2="";
    archvo_r.open("/home/juan/practica03/"+nombre_out, ios::in);

    if (archvo_r.fail()){
        cout<<"No se pudo abrir el archivo."<<endl;
        exit(1);
    }

    while(!archvo_r.eof()){
        getline(archvo_r,texto1);
        texto2 += texto1;
    }

    archvo_r.close();

    return (texto2);


}

bool ingreso (string user, string passwor){
    ifstream leer ("/home/juan/practica03/sudo", ios::in);
    if (leer.fail()){
        cout<<"No se pudo abrir el archivo."<<endl;
        exit(1);
    }
    string usuario="",clave="",bina="",desencr="",desencr2="",traduccion="";
    leer>>bina;
    desencriptar _in(4,bina);
    binario _traduccion(bina);
    desencr=_in.desencriptado(4,bina);

    for(int i=0; i<bina.length() ; i+=8){
        for(int j =0; j<8 ; j++){
            desencr2 += desencr[i+j];
        }
        traduccion+=_traduccion.bin_ascii(desencr2);
        desencr2="";
    }

    usuario = traduccion.substr(0,traduccion.find(" "));

    traduccion.erase(0,traduccion.find(" ")+1);

    clave = traduccion.substr(0,traduccion.find(" "));;


    if (usuario == user && passwor == clave){
        return true;
        leer.close();}
    else{
        return false;
        leer.close();}
}

bool signin(string user, string password, int money){

    string bin="";
    binario txtbin(0);
    encriptar txten(4,1,"");
    ofstream archivo_w;
    archivo_w.open("/home/juan/practica03/sudo", ios::out | ios::app);

    for (int i = 0 ; i < user.length() ; i++){
        bin += txtbin.ascii_bin(user[i]); // bin = contenido en binario.
    }
    bin+="00100000";
    for (int i = 0 ; i < password.length() ; i++){
        bin += txtbin.ascii_bin(password[i]); // bin = contenido en binario.
    }
    bin+="00100000";

    bin+= txtbin.ascii_bin(money);

    archivo_w<<txten.encriptado(4,1,bin)<<endl;

}
