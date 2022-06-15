#include <iostream>
using namespace std;
#include "Jugador.cpp"


int main()
{
    Tablero t;
    Jugador j1("Marcos",&t);
    Tablero t2;
    Jugador j2("Pedro",&t2);

    j1.Atacar(j2,3,4);
    j2.PintarTablero();

}



