#include "turnos.h"
#include "dados.h"
#include "constantes.h"
#include "rlutil.h"
#include <iostream>
using namespace std;

int quienEmpieza(string jugador1, string jugador2)
{
    int dado1, dado2;

    rlutil::setColor(rlutil::YELLOW);
    cout << "\n🎲 ¡Tirada inicial para decidir quién comienza! 🎲\n";
    rlutil::resetColor();
    do
    {
        dado1 = tirarDado(DADOS_JUGADOR);
        dado2 = tirarDado(DADOS_JUGADOR);
        cout << "🎲 " << jugador1 << " tira: " << dado1 << endl;
        cout << "🎲 " << jugador2 << " tira: " << dado2 << endl;
        rlutil::resetColor();

        if (dado1 == dado2)
        {
            rlutil::setColor(rlutil::RED);
            cout << "😅 ¡Empate! Tirando de nuevo...\n"
                 << endl;
            rlutil::resetColor();
        }
    } while (dado1 == dado2);

    rlutil::setColor(rlutil::YELLOW);
    cout << "🏆 " << (dado1 > dado2 ? jugador1 : jugador2) << " gana la tirada inicial! 🏆\n";
    rlutil::resetColor();
    return dado1 > dado2 ? 1 : 2;
}

void cambiarTurno(int &puntos1, int &puntos2, int &stock1, int &stock2, int &turno)
{
    turno = (turno == 1) ? 2 : 1;
}