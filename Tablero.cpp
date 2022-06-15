#include <iostream>
using namespace std;

class Tablero
{
private:
    int x=45, y=16;
    int recibido[100];
    char matriz[16][45]; //Esta Matriz esta invertida su x e y
    void pintar(int,int);
    bool Flota[10][7]={false}; //esta es una matriz espejo que nos va a indicar donde estan los barcos
    void pintar(int x, int y,char vr)

public:
    Tablero();
    void PintarTablero();
    void Recibir(int x, int y);
    void crearMatriz();
    void crearFlota();
    
};

Tablero::Tablero()
{
    crearMatriz();
}


void Tablero::Recibir(int x, int y){
    cout<<"Disparaste en "<<x <<" Y en "<<y<<endl;
    pintar(x,y);
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

void Tablero::pintar(int x, int y){
    matriz[y*2][6+ (x*4)] = 'X';
    
}
void Tablero::pintar(int x, int y,char vr){
    matriz[y*2][6+ (x*4)] = vr;
    
}
/*

void Tablero::crearFlota(){
    int barcos=10;
    int l;
    while (barcos>0)
    {
        cout<<"Te quedan "<<barcos<<" Barcos para acomodar."<<endl;
        cout<<"Recuerda que ningun barco puede ser mas largo que 5."
        cin>>l;
        if(l>5 or l<0){
            cout<<"El valor es invalido.";
        
        }else{
            
        }

    }
    


}
*/