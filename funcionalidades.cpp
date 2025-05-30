#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime> // es para srand y time
using namespace std;

// variable para estadíiticas 
int partidasJugadas = 0;
int partidasGanadasJ1 = 0;
int partidasGanadasJ2 = 0;

// cambia de color la consola
void cambiarColor(int color) { 
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

}

// muestra el menú principal
void mostrarMenu() {
    cambiarColor(11); // aqua claro
    cout << "    _______   ____________  _______   ______  ___    ____  ____  _____\n";
    cout << "   / ____/ | / / ____/ __ \\/ ____/ | / / __ \\/   |  / __ \\/ __ \\/ ___/\n";
    cout << "  / __/ /  |/ / /_  / /_/ / __/ /  |/ / / / / /| | / / / / / / /\\__ \\\n";
    cout << " / /___/ /|  / __/ / _, _/ /___/ /|  / /_/ / ___ |/ /_/ / /_/ /___/ /\n";
    cout << "/_____/_/ |_/_/   /_/ |_/_____/_/ |_/_____/_/  |_/_____/\\____//____/\n";

    cambiarColor(14); //amarillo
    cout << "\n1 - JUGAR\n";
    cout << "2 - ESTADÍSTICAS \n";
    cout << "3 - CRÉDITOS\n";
    cout << "---------------------------\n";
    cout << "0 - SALIR\n";
    cambiarColor(7); // neutro

}

// mostrar creditos
void mostrarCreditos() {
    cambiarColor(13); // purpura claro
    cout << "\n--- CRÉDITOS ---\n";
    cout << "Integrantes del equipo:\n";
    cout << "- Apellido, Nombre - Legajo\n";
    cout << "- Apellido, Nombre - Legajo\n";
    cout << "Nombre de equipo: Enfrendados Team\n";
    cout << "íconos: Freepik | Logo Maker\n";
    cout << "Juego creado por Angel simon, inspirado levemente en Mafia. \n\n";
    cambiarColor(7);
}
    
//logica del juego
void jugar(int &partidaJugadas, int &ganadasJ1, int &ganadasJ2) {
cambiarColor(10);
cout << "\nComienza una nueva partida...\n\n";

int numeroSecreto = rand() % 100+1;
int intentoJ1, intentoJ2;
int diferenciaJ1, diferenciaJ2;

cout << "Jugador 1, ingrese su intento (1-100): ";
cin >> intentoJ1;
cout << "Jugador 2, ingrese su intento (1-100): ";
cin >> intentoJ2;

diferenciaJ1 = abs(numeroSecreto - intentoJ1);
diferenciaJ2 = abs(numeroSecreto - intentoJ2);

cout << "\nEl número secreto era: " << numeroSecreto << "\n";

if (diferenciaJ1 < diferenciaJ2) { 
cout << "¡Jugador 1 gana esta ronda!\n ";
ganadasJ1++;

} else if (diferenciaJ2 < diferenciaJ1) {
  cout << "¡Jugador 2 gana esta ronda!\n";
  ganadasJ2++;
  
} else {
  cout << "¡Empate! Ambos estuvieron igual de cerca.\n";

}

partidasJugadas++;
cambiarColor(7);
system("pause");

}

// Me muestra las estadisticas
void mostrarEstadisticas(int partidas, int ganadasJ1, int ganadasJ2) {
    cambiarColor(9);
    cout << "\n--- ESTADíSTICAS ---\n"; 
    cout << "Partidas Jugadas: " << partidas << "\n";
    cout << "Ganadas por Jugador 1: " << ganadasJ1 << "\n";
    cout << "Ganadas por Jugador 2: " << ganadasJ2 << "\n";
    cambiarColor(7);
    
}
    int main () {
        int opcion;
        srand(time(0)); // aletorio

    do {
        system("cls");
        mostrarMenu();
        cout << "\nSeleccione una opción: ";
        cin >> opcion; 

        switch(opcion) {
            case 1:
                jugar(partidasJugadas, partidasGanadasJ1, partidasGanadasJ2);
                break;
                
            case 2:
                mostrarEstadisticas(partidasJugadas, partidasGanadasJ1, partidasGanadasJ2);
                system("pause");
                break;

            case 3:
                mostrarCreditos();
                system("pause");
                break;

            case 0: {
                cout << "\n¿Seguro que desea salir? (s/n): ";
                char salir;
                cin >> salir;
                if (salir == 's' || salir == 'S') {
                    cambiarColor(12);
                    cout << "\nSaliendo del juego...\n";
                    cambiarColor(7);
                    return 0;
                } else { 
                    cout << "\nVolviendo al menú...\n";
                    system("pause");
                }
                    break;
                }
            default:
                cambiarColor(4);
                
                cout << "\nOpción no válida. Intente de nuevo.\n";
                cambiarColor(7);
                system("pause");
                break;
               }
    } while (true);

    return 0;

}