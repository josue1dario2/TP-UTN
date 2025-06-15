#include <iostream>
SCRUM-30-mostrar-estadisticas
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

#include "funciones.h"
using namespace std;

int main()
{
    srand(time(0));

    int opcion;
    do
    {
        mostrarMenu();
        cin >> opcion;
        switch (opcion)
developer
        {
        case 1:
            // TODO jugar
            cout << "Ingreso a la fucion jugar" << endl;
            break;
        case 2:
            // TODO estadisticas
            cout << "Ingreso a la funcion estadisticas" << endl;
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
        }
    } while (opcion != 0);
    return 0;
}