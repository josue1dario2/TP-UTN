#pragma once
#include <string>

using namespace std;

int computarPuntaje(int suma, int dadosElegidos[], int tamano, int objetivo);
bool chequearTriunfo(int stock, int &puntos);
string definirCampeon(int puntos1, int puntos2, int stock1, int stock2, int rondas, string jugador1, string jugador2);
void mostrarEstadisticas(string mejorJugador, int mayorPuntaje);