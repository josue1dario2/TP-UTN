#include "funciones.h"
#include "rlutil.h"
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
    cout << "Creditos\n";
    cout << "Juego: Enfrendados\n";
    cout << "Creado por: Equipo 15\n";
    cout << "Integrantes:\n";
    cout << "- Maffey, Lucia, 31862\n";
    cout << "- Rivero, Camila, 32508\n";
    cout << "- Solis, Josue, 32522\n";
    cout << "- Totilo, Ivan, 29192\n";
    cout << "Íconos por Freepik, Logo por Logo Maker\n";
    cout << "Diseño del juego por Angel Simon\n";
}

void limpiarPantalla()
{
    rlutil::cls();
}