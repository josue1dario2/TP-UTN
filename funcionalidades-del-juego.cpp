#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Variables globales para estadísticas
int partidasJugadas = 0;
int partidasGanadasJ1 = 0;
int partidasGanadasJ2 = 0;

int main() {
    int opcion;
    srand(time(0)); // Inicializa la semilla del generador de números aleatorios

    do {
        // Menú principal
        cout << "\n--- MENÚ PRINCIPAL ---\n";
        cout << "1. Jugar\n";
        cout << "2. Mostrar estadísticas\n";
        cout << "3. Mostrar créditos\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cout << endl; // Separación visual

        if (opcion == 1) {
            // Funcionalidad de Jugar
            cout << "\nComienza una nueva partida...\n";
            int numeroSecreto = rand() % 100 + 1;
            int intentoJ1, intentoJ2;

            // Pedir intentos a los jugadores
            cout << "Jugador 1, ingrese su intento (1-100): ";
            cin >> intentoJ1;
            cout << "Jugador 2, ingrese su intento (1-100): ";
            cin >> intentoJ2;

            // Calcular diferencias
            int diferenciaJ1 = abs(numeroSecreto - intentoJ1);
            int diferenciaJ2 = abs(numeroSecreto - intentoJ2);

            // Mostrar resultado
            cout << "El número secreto era: " << numeroSecreto << "\n";

            if (diferenciaJ1 < diferenciaJ2) {
                cout << "¡Jugador 1 gana esta ronda!\n";
                partidasGanadasJ1++;
            } else if (diferenciaJ2 < diferenciaJ1) {
                cout << "¡Jugador 2 gana esta ronda!\n";
                partidasGanadasJ2++;
            } else {
                cout << "¡Empate!\n";
            }

            partidasJugadas++;
        }
        else if (opcion == 2) {
            // Funcionalidad de Estadísticas
            cout << "\n--- ESTADÍSTICAS ---\n";
            cout << "Partidas jugadas: " << partidasJugadas << "\n";
            cout << "Partidas ganadas por Jugador 1: " << partidasGanadasJ1 << "\n";
            cout << "Partidas ganadas por Jugador 2: " << partidasGanadasJ2 << "\n";
        }
        else if (opcion == 3) {
            // Funcionalidad de Créditos
            cout << "\n--- CRÉDITOS ---\n";
            cout << "Integrantes del equipo:\n";
            cout << "- Nombre Apellido - Legajo\n";
            cout << "- Nombre Apellido - Legajo\n";
            cout << "Nombre del juego: Enfrendados\n";
        }
        else if (opcion == 0) {
            // Confirmación de salida
            char confirmar;
            cout << "\n¿Seguro que desea salir? (s/n): ";
            cin >> confirmar;

            if (confirmar == 's' || confirmar == 'S') {
                cout << "Saliendo del juego...\n";
                break; // Salir del bucle
            } else {
                cout << "Volviendo al menú...\n";
                opcion = -1; // Para que el bucle continue
            }
        }
        else {
            // Opción inválida
            cout << "Opción inválida.\n";
        }

    } while (opcion != 0);

    return 0;
}
