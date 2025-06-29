#include "puntos.h"
#include "rlutil.h"
#include "constantes.h"
#include <iostream>
using namespace std;

int computarPuntaje(int suma, int dadosElegidos[], int tamano, int objetivo)
{
    return suma == objetivo ? suma * tamano : 0;
}

bool chequearTriunfo(int stock, int &puntos)
{
    if (stock == 0)
    {
        puntos += PUNTOS_TRIUNFO;
        return true;
    }
    return false;
}

string definirCampeon(int puntos1, int puntos2, int stock1, int stock2, int rondas, string jugador1, string jugador2)
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
        if (stock1 < stock2)
        {
            return jugador1;
        }
        else if (stock2 < stock1)
        {
            return jugador2;
        }
        else
        {
            return "Empate";
        }
    }
}

void mostrarEstadisticas(string mejorJugador, int mayorPuntaje)
{
    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    std::cout << "\n🎮✨ ESTADÍSTICAS DEL JUEGO ✨🎮\n";
    std::cout << "========================================\n";
    rlutil::resetColor();

    if (mayorPuntaje > 0)
    {
        rlutil::setColor(rlutil::GREEN);
        std::cout << "🏆 MEJOR JUGADOR: " << mejorJugador << " 🏆\n";
        rlutil::setColor(rlutil::CYAN);
        std::cout << "🌟 MAYOR PUNTAJE: " << mayorPuntaje << " puntos 🌟\n";
        rlutil::resetColor();
        std::cout << "\n¡Sigue jugando para romper récords! 🚀\n";
    }
    else
    {
        rlutil::setColor(rlutil::RED);
        std::cout << "😔 No hay estadísticas disponibles aún 😔\n";
        rlutil::setColor(rlutil::WHITE);
        std::cout << "¡Juega una partida para brillar! 🎲\n";
        rlutil::resetColor();
    }

    std::cout << "========================================\n";
    rlutil::setColor(rlutil::YELLOW);
    std::cout << "¡Vuelve pronto por más acción! 🎉\n";
    rlutil::resetColor();
    std::cout << "\n";
}