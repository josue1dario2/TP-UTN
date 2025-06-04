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
        cout << "2.Estadisticas" << endl;
        cout << "3.Creditos" << endl;
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

int tirarDado(int caras)
{
    return (rand() % caras) + 1;
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

int quienEmpieza(string jugador1, string jugador2)
{
    int dado1, dado2;
    srand(time(0)); // Inicializa el generador de números aleatorios con la hora actual

    do
    {
        dado1 = tirarDado(6);
        dado2 = tirarDado(6);
        cout << jugador1 << " tira: " << dado1 << endl;
        cout << jugador2 << " tira: " << dado2 << endl;

        if (dado1 == dado2)
        {
            cout << "¡Empate! Tirando de nuevo..." << endl;
        }
    } while (dado1 == dado2);

    if (dado1 > dado2)
    {
        cout << jugador1 << " gana la tirada inicial!" << endl;
        return 1;
    }
    else
    {
        cout << jugador2 << " gana la tirada inicial!" << endl;
        return 2;
    }
}
int lanzarDadosObjetivo()
{
    return tirarDado(12) + tirarDado(12);
}
void tirarDadosJugador(int cantidad, int dados[])
{

    for (int i = 0; i < cantidad; i++)
    {
        dados[i] = tirarDado(cantidad);
    }
}

int computarPuntaje(int suma, int dadosElegidos[], int tamano, int objetivo)
{
    if (suma == objetivo)
    {
        return suma * tamano;
    }
    else
    {
        return 0;
    }
}

void modificarDados(int &jugador, int tamanoSeleccionados, int &rival)
{
    jugador -= tamanoSeleccionados;
    rival += tamanoSeleccionados;
}