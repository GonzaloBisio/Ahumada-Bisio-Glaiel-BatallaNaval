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
    void pintar(int x, int y,char vr);
    void ponerBarco(int);


public:
    Tablero();
    void PintarTablero();
    void Recibir(int x, int y);
    void crearMatriz();
    void crearFlota();
    bool hayBarco();
};

Tablero::Tablero()
{
    crearMatriz();
}


void Tablero::Recibir(int x, int y){
    cout<<"Disparaste en "<<x <<" Y en "<<y<<endl;

    if (Flota[x][y])
    {
        cout<<"Acierto!"<<endl;
        pintar(x,y,'O');
    }
    else{
        cout<<"Agua"<<endl;
        pintar(x,y,'X');
    }

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


void Tablero::crearFlota(){
    while (true)
        {
        cout<<"Tienes dos opciones de flota: "<<endl<<"1) 2 barcos de 3 lugares y un barco de 4 lugares "<<endl<<"2) 3 barcos de 2 lugares y un barco de 4 lugares"<<endl;
        cin>>l;
        if (l==1)
        { 
            ponerBarco(3);
            ponerBarco(3);
            ponerBarco(4);
            break;

        }else if (l==2)
        {
            ponerBarco(2);
            ponerBarco(2);
            ponerBarco(2);
            ponerBarco(4);
            break;
        }else{
            cout<<"Ingresaste el numero "<< l <<" que no es ninguna opcion. Intente de nuevo.";
        }


    }
}

bool Tablero::hayBarco(int x, int y){
    return Flota[int x, int y];

};

void Tablero::ponerBarco(int l){
    int x;
    int y;
    int opcionLateral; //3 iz y der, 2 der, 1izq
    int opcionVertical;//3 ar y ab, 2 ar ,1 ab
    bool Condicion;
    int eleccion;
    cout<<"Ahora vamos a acomodar un barco de "<<l<<endl;
    do
    {
        Condicion=true;
        while(Condicion){
            cout<< "ingrese un valor de x: ";
            cin>>x;
            if (x+l-1 < 10 and x-l+1>0)
            {
               
                opcionLateral =3; //Izquierda y derecha
                Condicion=false;
                
            }else if (x+l-1 < 10 and x>0)
            {
                opcionLateral=2; //Derecha
                Condicion=false;

            }else if (x-l+1>0 and x<10)
            {
                opcionLateral=1;//Izquierda
                Condicion=false;
            
            }else
            {
                cout<<"Tu barco no entra en el tablero, ingresa una posicion nueva. Recuerda que tu barco mide "<<l<<endl;

            }
            
        }

        Condicion=true;
        while(Condicion){
            cout<< "ingrese un valor de y: ";
            cin>>y;

            if (y+l-1 < 7 and y-l+1>0)
            {
                opcionVertical =3; //arriba y abajo
                Condicion=false;
            
            }else if (y+l-1 < 7 and y > 0) 
            { 
                opcionVertical=1; //Abajo
                Condicion=false;

            }else if (y-l+1>0 and y<7)
            {
                opcionVertical=2; //Arriba
                Condicion=false;

            }else
            {
                cout<<"Tu barco no entra en el tablero, ingresa un barco nuevo."<<l<<endl;

            }
        }
        if (Flota[x][y])
        {
            cout<<"Ya hay un barco en ese lugar.";
        }
        
    } while (Flota[x][y]);
    ////////////////////////////////////////////////////////



    Condicion=true;

    while(Condicion){
        cout<<"Ingrese 1 si quiere ir arriba, 2 si quiere ir abajo, 3 si quiere ir a la derecha y 4 si quiere ir abajo. ";
        cin>>eleccion;
        switch (eleccion)
        {
        case 1:
            if (opcionVertical==3 or opcionVertical==1)
            {
                for (int t = x; t > (x-l); t--)
                {
                    Flota[t][y]=true;
                }
                
                Condicion=false;
            }else
            {
                cout<<"No pudes ir arriba, intente nuevamente";
            }

            break;
        case 2:
            if (opcionVertical==3 or opcionVertical==2)
            {

                for (int t = x; t < (x+l); t++)
                {
                    Flota[t][y]=true;
                }
                
                Condicion=false;
                

            }else
            {
                cout<<"No pudes ir abajo, intente nuevamente";
            }

            break;
        
        case 3:
            if (opcionLateral==3 or opcionLateral==2)
            {
                for (int t = y; t < (y+l); t++)
                {
                    Flota[x][t]=true;
                }
                Condicion=false;
            }else
            {
                cout<<"No pudes ir a la derecha, intente nuevamente";
            }

            break;
        
        case 4:
            if (opcionLateral==3 or opcionLateral==1)
            {
                for (int t = y; t < (y+l); t++)
                {
                    Flota[x][t]=true;
                }
                Condicion=false;
            }else
            {
                cout<<"No pudes ir a la izquierda, intente nuevamente";
            }

            break;

        default:
            cout<<"Valor incorrecto. ";
            break;
        }
    
    }
}