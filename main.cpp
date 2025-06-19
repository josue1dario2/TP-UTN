#include <iostream>
#include "funciones.h"
#include <time.h>
using namespace std;

int main() {
srand(time(0));

    Estadisticas stats;
    stats.mayorPuntaje = 100;
    stats.mejorJugador = "Jugador 1";

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1:
            // TODO jugar
            cout << "Ingreso a la fucion jugar" << endl;
            break;

        case 2:
            mostrarEstadisticas(stats); // ← ESTADÍSTICAS
                break;
        case 3:
            mostrarCreditos();
            break;
        case 0:
        {
            char confirm;
            cout << "\nSeguro que queres salir? (s/n): ";
            cin >> confirm;
            if (confirm != 's')
                opcion = -1;
            break;
        }
        default:
            cout << "\nOpción incorrecta.\n";
            break;
        }
    } while (opcion != 0);
    return 0;
}
