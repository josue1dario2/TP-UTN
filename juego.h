#pragma once

#include <string>
using namespace std;

void jugar(string &maxNombre, int &maxPuntaje);
bool jugarTurno(string nombre, int &stock, int &puntos, int &stockOponente, int objetivo);