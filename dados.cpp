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
        dados[i] = tirarDado(6);
    }
}

void elegirCombinacion(int objetivo, int dados[], int tamano, int seleccionados[], int &tamanoSeleccionados)
{
    tamanoSeleccionados = 0;
    int sumaActual = 0;
    bool usados[tamano];
    for (int i = 0; i < tamano; i++)
    {
        usados[i] = false;
    }

    while (sumaActual < objetivo)
    {
        cout << "Dados disponibles (Objetivo: " << objetivo << "):\n";
        for (int i = 0; i < tamano; i++)
        {
            if (!usados[i])
            {
                cout << "  [" << i + 1 << "] " << dados[i];
            }
        }
        cout << "\n\nSelecciona los dados por su número (0 para terminar): ";
        int indiceDado;
        if (!(cin >> indiceDado))
        {
            rlutil::setColor(rlutil::RED);
            cout << "Entrada inválida. Intenta de nuevo: ";
            rlutil::resetColor();
            continue;
        }
        if (indiceDado == 0)
        {
            tamanoSeleccionados = 0;
            return;
        }
        if (indiceDado < 1 || indiceDado > tamano)
        {
            rlutil::setColor(rlutil::RED);
            cout << "Número inválido. Intenta de nuevo: ";
            rlutil::resetColor();
            continue;
        }
        if (usados[indiceDado - 1])
        {
            rlutil::setColor(rlutil::RED);
            cout << "Ese dado ya está tomado. Intenta de nuevo: ";
            rlutil::resetColor();
            continue;
        }
        seleccionados[tamanoSeleccionados++] = dados[indiceDado - 1];
        usados[indiceDado - 1] = true;
        sumaActual += dados[indiceDado - 1];
        cout << "Suma actual: " << sumaActual << "\n";
        if (sumaActual == objetivo)
            return;
        if (sumaActual > objetivo)
        {
            tamanoSeleccionados = 0;
            return;
        }
    }
}