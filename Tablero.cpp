#include <iostream>
using namespace std;

class Tablero
{
private:
    int x,y;
public:
    Tablero(int x, int y);
    Tablero();
    void PintarTablero();
};

Tablero::Tablero(int x, int y)
{
    x=x;
    y=y;
}

Tablero::Tablero()
{
}


void Tablero::PintarTablero(){
    cout<<"Tablero";
}