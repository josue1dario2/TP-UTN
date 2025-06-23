
#include "interfaz.h"
#include "rlutil.h"
#include <ctime>
#include <iostream>
using namespace std;

void limpiarPantalla()
{
    rlutil::cls();
}

void mostrarMenu()
{
    cout << "    _______   ____________  _______  ______  ___    ____  ____  _____\n";
    cout << "   / ____/ | / / ____/ __ \\/ ___/ | / / __ \\/   |  / __ \\/ __ \\/ ___/\n";
    cout << "  / __/ /  |/ / /_  / /_/ / __//  |/ / / / / /| | / / / / / / /\\__ \\\n";
    cout << " / /___/ /|  / __/ / _  _/ /__/ /|  / /_/ / ___ |/ /_/ / /_/ /___/ /\n";
    cout << "/_____/_/ |_/_/   /_/ |_/____/_/  _/_____/_/  |_/_____/\\____/_____/\n";
    cout << "\n1 - JUGAR\n2 - ESTADISTICAS\n3 - CREDITOS\n---------------------\n0 - SALIR\n";
    cout << "Opción: ";
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