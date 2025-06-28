#include "puntos.h"
#include "rlutil.h"
#include <iostream>
using namespace std;

int computarPuntaje(int suma, int dadosElegidos[], int tamano, int objetivo)
{
    return suma == objetivo ? suma * tamano : 0;
}

bool chequearTriunfo(int stock, int &puntos)
{
    if (stock == 0)
    {
        puntos += PUNTOS_TRIUNFO;
        return true;
    }
    return false;
}

string definirCampeon(int puntos1, int puntos2, int rondas, string jugador1, string jugador2)
{
    if (rondas != 3)
    {
        return "";
    }
    if (puntos1 > puntos2)
    {
        return jugador1;
    }
    else if (puntos2 > puntos1)
    {
        return jugador2;
    }
    else
    {
        return "Empate";
    }
}

void mostrarEstadisticas(string mejorJugador, int mayorPuntaje)
{
    cout << "\nEstadísticas del juego:\n";
    if (mayorPuntaje > 0)
    {
        cout << "Mejor jugador: " << mejorJugador << "\n";
        cout << "Mayor puntaje: " << mayorPuntaje << "\n";
    }
    else
    {
        cout << "No hay estadísticas disponibles.\n";
    }
}