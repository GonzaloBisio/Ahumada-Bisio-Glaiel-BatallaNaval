#include <iostream>
using namespace std;

class Tablero
{
private:
    int x=45, y=16;
    int recibido[100];
    char matriz[16][45];
public:
    Tablero();
    void PintarTablero();
    void Bala(int x, int y);
    void crearMatriz();

};

Tablero::Tablero()
{
    crearMatriz();
}


void Tablero::Bala(int x, int y){
    cout<<"Disparaste en "<<x <<" Y en "<<y;
}

void Tablero::PintarTablero(){
    for(int i=0; i<y; i++)
    {
        for(int j=0; j<x; j++)
        {
            cout<<matriz[i][j];
        }
        cout<<endl;
    }


}

void Tablero::crearMatriz(){

    for(int i=0; i<y; i++)
    {
        for(int j=0; j<x; j++)
        {
            matriz[i][j] = ' ';
        }
    }
    matriz[0][2]='x';
    char num = '0';
    for(int i=6; i<x; i+=4)
    {
        matriz[0][i] = num++;
    }
    char val= 'A';

    for(int i=2; i<y; i+=2)
    {
        matriz[i][2] = val++;
    }

    for(int i=0; i<y; i++)
    {
        if(i > 0 && i%2==1)
        {
            for(int j=0; j<x; j++)
            {
                matriz[i][j] = '-';
            }
        }
        for(int j=0; j<x; j+=4)
        {
            matriz[i][j] = '|';
        }
    }

    
    cout<<"Termine de crear la tabla"<<endl;
}