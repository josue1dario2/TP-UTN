#include <iostream>
#include <cstdlib>
#include <windows.h> // es para cambiar colores en windows
using namespace std;

void cambiarColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void mostrarMenu() {
    cambiarColor(11); // aqua claro para el titulo 
    cout << "    _______   ____________  _______   ______  ___    ____  ____  _____\n";
    cout << "   / ____/ | / / ____/ __ \\/ ____/ | / / __ \\/   |  / __ \\/ __ \\/ ___/\n";
    cout << "  / __/ /  |/ / /_  / /_/ / __/ /  |/ / / / / /| | / / / / / / /\\__ \\\n";
    cout << " / /___/ /|  / __/ / _, _/ /___/ /|  / /_/ / ___ |/ /_/ / /_/ /___/ /\n";
    cout << "/_____/_/ |_/_/   /_/ |_/_____/_/ |_/_____/_/  |_/_____/\\____//____/\n";

    cambiarColor(14); // amarillo claro para las opciones
    cout << "\n";
    cout << "1 - JUGAR\n";
    cout << "2 - ESTADÍSTICAS\n";
    cout << "3 - CRÉDITOS\n";
    cout << "---------------------------\n";
    cout << "0 - SALIR\n";

    cambiarColor(7); // volver a color neutro
}



void mostrarCreditos() { 
    cambiarColor(13); // purpura claro para los creditos
    cout << "\n--- CRÉDITOS ---\n";
    cout << "Integrantes del equipo:\n";
    cout << "- Apellido, Nombre - Legajo\n";
    cout << "- Apellido, Nombre - Legajo\n";
    cout << "Nombre del equipo: Enfrendados Team\n";
    cout << "Íconos: Freepik | Logo Maker\n";
    cout << "Juego creado por Angel Simon, inspirado levemente en Mafia. \n\n";
    cambiarColor(7); //volver a color neutro

}

int main() {
    int opcion;

   do{
     system("cls"); 
     mostrarMenu();
     cout << "\nSeleccione una opción: ";
     cin >> opcion;

    switch(opcion) {
        case 1:
          cambiarColor(10);
          cout << "\nIniciando juego...\n";
          // aca iria la logica para iniciar el juego
          cambiarColor(7);
          system("pause");
          break;

        case 2: 
           cambiarColor(9); //azul claro
           cout << "\nMostrando estadísticas...\n";
           cambiarColor(7);
           system("pause");
             // aca va la lógica para mostrar estadísticas
            break;

        case 3:
            mostrarCreditos();
            system("pause");
            break;

         case 0:

            cout <<"\n¿Seguro que desea salir? (s/n): "; 
            char salir;
            cin >> salir;
            if (salir == 's'|| salir == 'S') {
                cambiarColor(12); // Rojo claro
                cout << "\nSaliendo del juego...\n";
                cambiarColor(7);
                return 0;
         }

            break;
        }

        default:
            cambiarColor(4); // rojo para error
            cout << "\nOpción no válida. Intente de nuevo.\n";
            cambiarColor(7);
            system("pause");
            break;
        }

    } while (true);
    
    return 0;
}
