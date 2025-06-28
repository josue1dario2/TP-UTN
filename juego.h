#pragma once

#include "dados.h"
#include "interfaz.h"
#include "puntos.h"
#include "stocks.h"
#include "turnos.h"

#include <string>
using namespace std;

void jugar(string &maxNombre, int &maxPuntaje);
bool jugarTurno(string nombre, int &stock, int &puntos, int &stockOponente, int objetivo);