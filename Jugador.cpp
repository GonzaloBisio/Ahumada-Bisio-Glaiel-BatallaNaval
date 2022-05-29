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
    Jugador(string,int,int);
    Jugador();
    void PintarTablero();
    bool Recibir(int,int);
    void Atacar(Jugador,int,int);
};

Jugador::Jugador(string nombre,int x,int y)
{
    nombre=nombre;
    puntaje = 0;
    tablero = Tablero(x,y);
}

Jugador::Jugador()
{
}

void Jugador::PintarTablero(){
    tablero.PintarTablero();
}


bool Jugador::Recibir(int x,int y){

}

void Atacar(Jugador enemigo,int x,int y){
    
}
