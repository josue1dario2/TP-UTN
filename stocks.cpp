#include "stocks.h"

void modificarDados(int &jugador, int tamanoSeleccionados, int &rival)
{
    jugador -= tamanoSeleccionados;
    rival += tamanoSeleccionados;
}

void castigarFallo(int &jugador, int &rival)
{
    if (rival > 1)
    {
        rival--;
        jugador++;
    }
}