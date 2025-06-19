#include "puntos.h"
#include "rlutil.h"
#include <iostream>
using namespace std;

int computarPuntaje(int suma, int dadosElegidos[], int tamano, int objetivo)
{
    return suma == objetivo ? suma * tamano : 0;
}

bool chequearTriunfo(int jugador, int &puntos)
{
    if (jugador == 0)
    {
        puntos += 10000;
        return true;
    }
    else
    {
        return false;
    }
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