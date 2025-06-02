#include <iostream>
#include <windows.h>
using namespace std;

// Cambia el color del texto en la consola
void cambiarColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Muestra el menú principal
void mostrarMenu() {
    cambiarColor(11); // aqua claro
    cout << "    _______   ____________  _______   ______  ___    ____  ____  _____\n";
    cout << "   / ____/ | / / ____/ __ \\/ ____/ | / / __ \\/   |  / __ \\/ __ \\/ ___/\n";
    cout << "  / __/ /  |/ / /_  / /_/ / __/ /  |/ / / / / /| | / / / / / / /\\__ \\\n";
    cout << " / /___/ /|  / __/ / _, _/ /___/ /|  / /_/ / ___ |/ /_/ / /_/ /___/ /\n";
    cout << "/_____/_/ |_/_/   /_/ |_/_____/_/ |_/_____/_/  |_/_____/\\____//_____/\n";

    cambiarColor(14); // amarillo 
    cout << "\n--- MENÚ PRINCIPAL ---\n";
    cout << "1 - JUGAR\n";
    cout << "2 - ESTADÍSTICAS\n";
    cout << "3 - CRÉDITOS\n";
    cout << "---------------------------\n";
    cout << "0 - SALIR\n";

    cambiarColor(7); 
    cout << "\nOpción: ";
}

int main() {
    int opcion;
    char confirmarSalida;

    do {
        system("cls"); // limpia la pantalla
        mostrarMenu(); 
        cin >> opcion;

        if (opcion == 1) {
            // TO DO: funcionalidad de jugar
        } else if (opcion == 2) {
            // TO DO: funcionalidad de estadísticas
        } else if (opcion == 3) {
            // TO DO: funcionalidad de créditos
        } else if (opcion == 0) {
            cout << "\n¿Seguro que desea salir? (s/n): ";
            cin >> confirmarSalida;
            if (confirmarSalida == 's' || confirmarSalida == 'S') {
                cambiarColor(12); // rojo claro
                cout << "\nSaliendo del juego...\n";
                cambiarColor(7);
                break; // sale del bucle
            } else {
                opcion = -1; // continuar en el menú
            }
        } else {
            cambiarColor(4); // rojo
            cout << "\nOpción inválida.\n";
            cambiarColor(7);
            system("pause");
        }

    } while (true);

    return 0;
}