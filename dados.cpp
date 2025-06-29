#include "dados.h"
#include "rlutil.h"
#include "constantes.h"
#include <ctime>
#include <iostream>
using namespace std;

int tirarDado(int caras)
{
    return (rand() % caras) + 1;
}

int lanzarDadosObjetivo()
{
    return tirarDado(DADOS_OBJETIVO) + tirarDado(DADOS_OBJETIVO);
}

void tirarDadosJugador(int cantidad, int dados[])
{

    for (int i = 0; i < cantidad; i++)
    {
        dados[i] = tirarDado(DADOS_JUGADOR);
    }
}

void elegirCombinacion(int objetivo, int dados[], int tamano, int seleccionados[], int &tamanoSeleccionados, std::string nombre, int stock, int puntos)
{
    tamanoSeleccionados = 0;
    int sumaActual = 0;
    bool usados[tamano];
    for (int i = 0; i < tamano; i++)
    {
        usados[i] = false;
    }

    bool primeraIteracion = true;
    while (sumaActual < objetivo)
    {
        rlutil::setColor(rlutil::CYAN);
        cout << "\n🎲 Turno de " << nombre << " 🎲\n";
        rlutil::resetColor();
        cout << "Stock: " << stock << " dados | Puntos: " << puntos << "\n";
        cout << "Dados objetivo: " << objetivo << "\n\n";

        rlutil::setColor(rlutil::GREEN);
        cout << "Dados disponibles (" << (primeraIteracion ? "Objetivo: " : "Suma actual: ") << (primeraIteracion ? objetivo : sumaActual) << "):\n";
        rlutil::resetColor();
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
            cout << "\n¡Error! Entrada inválida. Intenta de nuevo.\n";
            rlutil::resetColor();
            cout << "Presiona Enter para continuar...";
            cin.get();
            rlutil::cls();
            continue;
        }
        if (indiceDado == 0)
        {
            tamanoSeleccionados = 0;
            return;
        }
        if (indiceDado < 1 || indiceDado > tamano || usados[indiceDado - 1])
        {
            rlutil::setColor(rlutil::RED);
            cout << "\n¡Error! Dado no disponible o ya seleccionado. Intenta de nuevo.\n";
            rlutil::resetColor();
            rlutil::anykey("Presiona cualquier tecla para continuar...");
            rlutil::cls();
            continue;
        }
        seleccionados[tamanoSeleccionados++] = dados[indiceDado - 1];
        usados[indiceDado - 1] = true;
        sumaActual += dados[indiceDado - 1];
        primeraIteracion = false;
        rlutil::cls();
        if (sumaActual == objetivo)
            return;
        if (sumaActual > objetivo)
        {
            tamanoSeleccionados = 0;
            return;
        }
    }
}