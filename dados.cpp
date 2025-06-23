#include "dados.h"
#include "rlutil.h"
#include <ctime>
#include <iostream>
using namespace std;

int tirarDado(int caras)
{
    return (rand() % caras) + 1;
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

void elegirCombinacion(int objetivo, int dados[], int tamano, int seleccionados[], int &tamanoSeleccionados)
{
    tamanoSeleccionados = 0;
    int sumaActual = 0;
    cout << "Dados disponibles:\n";
    for (int i = 0; i < tamano; i++)
    {
        cout << "  [" << i + 1 << "] " << dados[i];
    }
    cout << "\n\nSelecciona los dados por su número (0 para terminar): ";
    while (sumaActual < objetivo)
    {
        int indiceDado;
        cin >> indiceDado;
        if (indiceDado == 0)
        {
            tamanoSeleccionados = 0;
            return;
        }
        if (indiceDado < 1 || indiceDado > tamano)
        {
            cout << "Número inválido. Intenta de nuevo: ";
            continue;
        }
        seleccionados[tamanoSeleccionados++] = dados[indiceDado - 1];
        sumaActual += dados[indiceDado - 1];
        cout << "Suma actual: " << sumaActual << "\n";
        if (sumaActual == objetivo)
            return;
        if (sumaActual > objetivo)
        {
            tamanoSeleccionados = 0;
            return;
        }
        cout << "Siguiente dado (0 para terminar): ";
    }
}