#include "funciones.h"
#include <iostream>
using namespace std;

int seleccionarOpcion()
{
    int opcion;
    do
    {
        cout << "Menu principal: " << endl;
        cout << "1.Jugar" << endl;
        cout << "2.Estadísticas" << endl;
        cout << "3.Créditos" << endl;
        cout << "0.Salir" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 0:
            return 0;
            break;
        }
    } while (opcion != 0);
    return opcion;
}

void mostrarCreditos()
{
    limpiarPantalla();
    cout << "Créditos\n";
    cout << "Juego: Enfrendados\n";
    cout << "Creado por: [Nombre del Equipo]\n";
    cout << "Integrantes:\n";
    cout << "- [Apellido], [Nombre], [Legajo]\n";
    cout << "- [Apellido], [Nombre], [Legajo]\n";
    cout << "Íconos por Freepik, Logo por Logo Maker\n";
    cout << "Diseño del juego por Angel Simon\n";
}