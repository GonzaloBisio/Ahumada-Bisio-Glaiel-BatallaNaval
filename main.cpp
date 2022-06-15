#include <iostream>
using namespace std;
#include "Jugador.cpp"

int main()
{

    // t1.crearFlota():

    string pl[7] = {"a", "b", "c", "d", "e", "f", "g"};
    int pn[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    string n1;
    string n2;

    cout << "\n BIENVENIDO A LA BATALLA NAVAL!" << endl;
    cout <<"El jugador que alcance un puntaje de 10 será el ganador"<<endl;
    cout << "Para empezar a jugar, ingrese los nombres de los jugadores: " << endl;
    cout << "\nJugador 1: " << endl;
    cin >> n1;
    cout << "\n"
         << n1 << " Listo! \n"
         << endl;
    cout << "Jugador 2: " << endl;
    cin >> n2;
    cout << "\n"
         << n2 << " Listo!";

    Tablero t;
    Jugador j1(n1, &t);
    Tablero t2;
    Jugador j2(n2, &t2);

    int q;
    int n;
    string l;
    bool wrong = true;
    bool wrongn = true;
    bool ataque = false;

    cout<< "Ingrese 1 para comenzar, cualquier otro caracter para salir"<<endl;
    cin>>q;
    while (q == 1)
    {

        //turno 1

        cout<< "\nEs el turno de " << n1 << endl;
        cout << "\nA que letra atacamos capitán? " << endl;
        cin >> l;
    
        for (int i = 0; i < 8; i++)
        {
            if (pl[i] == l)
            {
                cout << "Excelente! Ahora número: " << endl;
                cin >> n;
                for (int i = 0; i < 11; i++)
                {
                    if (pn[i] == n)
                    {
                        cout << "Coordenadas establecidas!" << endl;
                        ataque = true;
                        j1.Atacar(j2, n, 7);
                    }
                    else
                    {
                        wrongn = false;
                    }
                }
            }
            else
            {
                wrong = false;
            }
        }

        if (wrong = false)
        {
            cout << "Lo siento, la letra debe que ser de la A hasta la G" << endl;
        }
        if (wrongn = false)
        {
            cout << "Lo siento, el número ingresado debe ser del 0 al 9" << endl;
        }

        //turno 2
        
        cout<< "\nEs el turno de " << n2 << endl;
        cout << "\nA que letra atacamos comandante? " << endl;
        cin >> l;
    
        for (int i = 0; i < 8; i++)
        {
            if (pl[i] == l)
            {
                cout << "Excelente! Ahora número: " << endl;
                cin >> n;
                for (int i = 0; i < 11; i++)
                {
                    if (pn[i] == n)
                    {
                        cout << "Coordenadas establecidas!" << endl;
                        ataque = true;
                        j2.Atacar(j1, n, 5);
                    }
                    else
                    {
                        wrongn = false;
                    }
                }
            }
            else
            {
                wrong = false;
            }
        }

        if (wrong = false)
        {
            cout << "Lo siento, la letra debe que ser de la A hasta la G" << endl;
        }
        if (wrongn = false)
        {
            cout << "Lo siento, el número ingresado debe ser del 0 al 9" << endl;
        }

    }
}
