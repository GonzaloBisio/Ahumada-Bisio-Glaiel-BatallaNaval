#include <iostream>
using namespace std;
#include "Tablero.cpp"

class Jugador
{
private:
    string nombre;
    Tablero* tablero;
public:
    Jugador(string,Tablero*);
    void PintarTablero();
    bool Recibir(int,int);
    void Atacar(Jugador,int,int);
};

Jugador::Jugador(string n, Tablero* t)
{
    nombre=n;
    tablero=t;
}

void Jugador::PintarTablero(){
    string Texto="Tabla De ";
    Texto.append(nombre);
    int z = Texto.length();
    z=(44-z)/2;
    
    cout<<"+-------------------------------------------+"<<endl;
    if (z%2==0)
    {
        cout<<"|"<<string(z,' ')<<Texto<<string(z,' ')<<"|"<<endl;
    }else
    {
        cout<<"|"<<string(z,' ')<<Texto<<string(z-1,' ')<<"|"<<endl;
    }    
    cout<<"+-------------------------------------------+"<<endl;

    tablero->PintarTablero();
}


bool Jugador::Recibir(int x,int y){
    
    tablero->Recibir(x,y);
    
    tablero->PintarTablero();
}


void Jugador::Atacar(Jugador enemigo,int x,int y){
    cout<<"Atacando a "<<"El enemigo"<<endl;
    enemigo.Recibir(x,y);
}
