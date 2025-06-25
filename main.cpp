#include <iostream>
#include "funciones.h"
#include <time.h>
#include "juego.h"
using namespace std;

int main() {

srand(time(0));
    srand(time(0));
    string maxNombre = "";
    int maxPuntaje = 0;


    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1:
            jugar( maxNombre, maxPuntaje);
            break;

        case 2:
            mostrarEstadisticas( maxNombre, maxPuntaje); 
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