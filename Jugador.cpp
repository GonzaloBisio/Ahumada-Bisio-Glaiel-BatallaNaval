#include <iostream>
using namespace std;
#include "Tablero.cpp"

class Jugador
{
private:
    string nombre;
    int puntaje;
    Tablero tablero;
public:
    Jugador(string);
    Jugador();
    void PintarTablero();
    bool Recibir(int,int);
    void Atacar(Jugador,int,int);
};

Jugador::Jugador(string n)
{
    nombre=n;
    puntaje = 0;
    tablero = Tablero();
}

Jugador::Jugador()
{
    nombre="NULL";
    puntaje = 0;
    tablero = Tablero();
}

void Jugador::PintarTablero(){
    string Texto="Tabla De ";
    Texto.append(nombre);
    int z = Texto.length();
    z=(44-z)/2;
    
    cout<<"+-------------------------------------------+"<<endl;
    if (z%2==0)
    {
        cout<<"|"<<string(z,' ')<<Texto<<string(z-1,' ')<<"|"<<endl;
    }else
    {
        cout<<"|"<<string(z,' ')<<Texto<<string(z,' ')<<"|"<<endl;
    }    
    cout<<"+-------------------------------------------+"<<endl;


    tablero.PintarTablero();
}


bool Jugador::Recibir(int x,int y){
    tablero.Bala(x,y);
}

void Jugador::Atacar(Jugador enemigo,int x,int y){
    //enemigo.PintarTablero();
    cout<<"Atacando a "<<nombre<<endl;
    enemigo.Recibir(x,y);
}
