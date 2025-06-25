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
    return (jugador == 0) ? (puntos += 10000, true) : false;
}

string definirCampeon(int puntos1, int puntos2, int rondas, string jugador1, string jugador2)
{
    return (rondas != 3) ? "" :
           (puntos1 > puntos2) ? jugador1 :
           (puntos2 > puntos1) ? jugador2 :
           "Empate";
}

void mostrarEstadisticas(string mejorJugador, int mayorPuntaje) {
    cout << "\nEstadísticas del juego:\n"; 
    if (mayorPuntaje > 0) {
        cout << "Mejor jugador: " << mejorJugador << "\n";
        cout << "Mayor puntaje: " << mayorPuntaje << "\n";
    } else {
        cout << "No hay estadísticas disponibles.\n";
    }
    
}