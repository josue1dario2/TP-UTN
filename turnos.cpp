#include "turnos.h"
#include "dados.h"
#include "rlutil.h"
#include <iostream>
using namespace std;

int quienEmpieza(string jugador1, string jugador2)
{
    int dado1, dado2;

    do
    {
        dado1 = tirarDado(6);
        dado2 = tirarDado(6);
        cout << jugador1 << " tira: " << dado1 << endl;
        cout << jugador2 << " tira: " << dado2 << endl;

        if (dado1 == dado2)
        {
            cout << "¡Empate! Tirando de nuevo..." << endl;
        }
    } while (dado1 == dado2);

    cout << (dado1 > dado2 ? jugador1 : jugador2) << " gana la tirada inicial!" << endl;
    return dado1 > dado2 ? 1 : 2;
}

void cambiarTurno(int &puntos1, int &puntos2, int &stock1, int &stock2, int &turno)
{
    turno = (turno == 1) ? 2 : 1;
}