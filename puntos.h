#pragma once
#include <string>
using namespace std;

int computarPuntaje(int suma, int dadosElegidos[], int tamano, int objetivo);
bool chequearTriunfo(int jugador, int &puntos);
string definirCampeon(int puntos1, int puntos2, int rondas, string jugador1, string jugador2);
