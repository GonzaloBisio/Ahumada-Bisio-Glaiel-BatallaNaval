#include <iostream>
using namespace std;
#include "Jugador.cpp"


int main()
{
    int x,y;
    Jugador jugadores[10];
    jugadores[0]= Jugador("Marcos",2,2);
    jugadores[0].PintarTablero();

}
