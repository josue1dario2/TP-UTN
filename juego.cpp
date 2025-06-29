#include "main.h"
#include "constantes.h"
#include <ctime>
#include <iostream>

using namespace std;

bool jugarTurno(string nombre, int &stock, int &puntos, int &stockOponente, int objetivo)
{
    rlutil::setColor(rlutil::CYAN);
    cout << "\n🎲 Turno de " << nombre << " 🎲\n";
    rlutil::resetColor();
    cout << "Stock: " << stock << " dados | Puntos: " << puntos << "\n";
    cout << "Dados objetivo: " << objetivo << "\n\n";
    int dados[stock];
    tirarDadosJugador(stock, dados);
    int seleccionados[stock], tamanoSeleccionados;
    elegirCombinacion(objetivo, dados, stock, seleccionados, tamanoSeleccionados);
    int suma = 0;
    for (int i = 0; i < tamanoSeleccionados; i++)
        suma += seleccionados[i];
    int puntosRonda = computarPuntaje(suma, seleccionados, tamanoSeleccionados, objetivo);
    puntos += puntosRonda;
    if (puntosRonda > 0)
    {
        rlutil::setColor(rlutil::GREEN);
        cout << "\n--- 🎉 Tirada Exitosa! 🎉 ---\n";
        rlutil::resetColor();
        cout << "Suma objetivo: " << objetivo << "\nDados elegidos: ";
        for (int i = 0; i < tamanoSeleccionados; i++)
            cout << seleccionados[i] << " ";
        cout << "\nPuntos ganados: " << puntosRonda << "\nDados enviados: " << tamanoSeleccionados << "\n";
        modificarDados(stock, tamanoSeleccionados, stockOponente);
        if (chequearTriunfo(stock, puntos))
        {
            rlutil::setColor(rlutil::YELLOW);
            cout << "\n========================================\n";
            cout << "🏆 " << nombre << " gana la partida! 🏆\n";
            cout << "========================================\n";
            rlutil::resetColor();
            return true;
        }
    }
    else
    {
        rlutil::setColor(rlutil::RED);
        cout << "\n--- 😔 Tirada No Exitosa 😔 ---\n";
        rlutil::resetColor();
        int dadosAntes = stock;
        castigarFallo(stock, stockOponente);
        cout << "Dados recibidos: " << stock - dadosAntes << "\n";
    }
    return false;
}

void jugar(string &maxNombre, int &maxPuntaje)
{
    string jugador1, jugador2;
    cout << "\n--- 🎮 Iniciar Juego 🎮 ---\n";
    cout << "Nombre Jugador 1: ";
    cin >> jugador1;
    cout << "Nombre Jugador 2: ";
    cin >> jugador2;
    cout << "\n";

    int stock1 = STOCK_INICIAL, stock2 = STOCK_INICIAL, puntos1 = PUNTOS_INICIAL, puntos2 = PUNTOS_INICIAL, rondas = 0, turno;
    turno = quienEmpieza(jugador1, jugador2);
    rlutil::setColor(rlutil::YELLOW);
    cout << "\n🎲 " << (turno == 1 ? jugador1 : jugador2) << " comienza la partida! 🎲\n";
    rlutil::resetColor();

    bool juegoTerminado = false;
    while (rondas < 3 && !juegoTerminado)
    {
        rondas++;
        rlutil::setColor(rlutil::YELLOW);
        cout << "\n========================================\n";
        cout << "                Ronda " << rondas << "\n";
        cout << "========================================\n";
        rlutil::resetColor();

        int objetivo = lanzarDadosObjetivo();
        if (turno == 1)
        {
            juegoTerminado = jugarTurno(jugador1, stock1, puntos1, stock2, objetivo);
            if (!juegoTerminado)
            {
                cambiarTurno(puntos1, puntos2, stock1, stock2, turno);
            }
        }
        if (!juegoTerminado && turno == 2)
        {
            juegoTerminado = jugarTurno(jugador2, stock2, puntos2, stock1, objetivo);
            if (!juegoTerminado)
            {
                cambiarTurno(puntos1, puntos2, stock1, stock2, turno);
            }
        }
    }
    rlutil::setColor(rlutil::YELLOW);
    cout << "\n========================================\n";
    cout << "           Resultados Finales\n";
    cout << "========================================\n";
    cout << jugador1 << ": " << puntos1 << " puntos | " << stock1 << " dados\n";
    cout << jugador2 << ": " << puntos2 << " puntos | " << stock2 << " dados\n";
    string campeon = definirCampeon(puntos1, puntos2, stock1, stock2, rondas, jugador1, jugador2);
    cout << "Ganador: " << campeon << " 🏆🎉\n";
    cout << "========================================\n";
    rlutil::resetColor();

    if (puntos1 > maxPuntaje)
    {
        maxPuntaje = puntos1;
        maxNombre = jugador1;
    }
    if (puntos2 > maxPuntaje)
    {
        maxPuntaje = puntos2;
        maxNombre = jugador2;
    }
}