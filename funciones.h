#pragma once

int seleccionarOpcion();
void limpiarPantalla();
void mostrarCreditos();
int tirarDado(int caras);
int quienEmpieza(string nombre1, string nombre2);
int lanzarDadosObjetivo();
void tirarDadosJugador(int cantidad,int dados[]);
int computarPuntaje(int suma, const int dadosElegidos[], int tamano, int objetivo);
