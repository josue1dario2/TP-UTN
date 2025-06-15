#include <iostream>
#include <string>S
#include "funciones.h"
using namespace std;

int main() {
    Estadisticas stats;
     stats.mejorJugador = "Jugador 1"; // Ejemplo para test
    stats.mayorPuntaje = 100;         // Ejemplo para test

  int opcion; 
do
    {
         cout << "\nMenu:\n";
        cout << "1 - Jugar\n";
        cout << "2 - Estadísticas\n";
        cout << "3 - Créditos\n";
        cout << "0 - Salir\n";
        cout << "Opción: ";
        cin >> opcion;
        
        if (opcion == 1)
        {
		    // TO DO funcionalidad de jugar
        }
        else if (opcion == 2)
        {
         	// TO DO funcionalidad de estadísticas
        }
        else if (opcion == 3)
        {
         	// TO DO funcionalidad de creditos
        }
        else if (opcion == 0)
        {
       		// TO DO funcionalidad de salir de juego preguntar si desea salir 
        }
        else
        {
            cout << "Opción inválida.";
        }
    } while (opcion != 0);
    return 0;
}