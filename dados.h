#pragma once
#include <string>
using namespace std;

int tirarDado(int caras);
int lanzarDadosObjetivo();
void elegirCombinacion(int objetivo, int dados[], int tamano, int seleccionados[], int &tamanoSeleccionados, string nombre, int stock, int puntos);
void tirarDadosJugador(int cantidad, int dados[]);