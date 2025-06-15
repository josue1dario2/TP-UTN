#pragma once
#include <string>
using namespace std;

struct Estadisticas {
    string mejorJugador;
    int mayorPuntaje = 0; 
};

void mostrarEstadisticas(const Estadisticas& stats);
void actualizarEstadisticas(Estadisticas& stats, const string& jugador, int puntaje);
int seleccionarOpcion();
void limpiarPantalla();
void mostrarCreditos();
int tirarDado(int caras);
int quienEmpieza(string nombre1, string nombre2);
void mostrarMenu();
int lanzarDadosObjetivo();
void tirarDadosJugador(int cantidad, int dados[]);
int computarPuntaje(int suma, int dadosElegidos[], int tamano, int objetivo);
void elegirCombinacion(int objetivo, int dados[], int tamano, int seleccionados[], int &tamanoSeleccionados);
void modificarDados(int &jugador, int tamanoSeleccionados, int &rival);

string definirCampeon(int puntos1, int puntos2, int rondas, string jugador1, string jugador2);
