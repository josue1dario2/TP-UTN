#include "juego.h"
#include <ctime>
#include <iostream>

using namespace std;

void jugar(string &maxNombre, int &maxPuntaje)
{
    string jugador1, jugador2;
    cout << "\n--- Iniciar Juego ---\n";
    cout << "Nombre Jugador 1: ";
    cin >> jugador1;
    cout << "Nombre Jugador 2: ";
    cin >> jugador2;
    cout << "\n";

    int stock1 = 6, stock2 = 6, puntos1 = 0, puntos2 = 0, rondas = 0, turno;
    turno = quienEmpieza(jugador1, jugador2);
    cout << "\n"
         << (turno == 1 ? jugador1 : jugador2) << " comienza la partida.\n";

    while (rondas < 3)
    {
        rondas++;
        cout << "\n========================================\n";
        cout << "Ronda " << rondas << "\n";
        cout << "========================================\n";

        // Turno Jugador 1
        if (turno == 1)
        {
            cout << "\nTurno de " << jugador1 << "\n";
            cout << "Stock: " << stock1 << " dados | Puntos: " << puntos1 << "\n";
            int objetivo = lanzarDadosObjetivo();
            cout << "Dados objetivo: " << objetivo << "\n\n";
            int dados[stock1];
            tirarDadosJugador(stock1, dados);
            int seleccionados[stock1], tamanoSeleccionados;
            elegirCombinacion(objetivo, dados, stock1, seleccionados, tamanoSeleccionados);
            int suma = 0;
            for (int i = 0; i < tamanoSeleccionados; i++)
                suma += seleccionados[i];
            int puntosRonda = computarPuntaje(suma, seleccionados, tamanoSeleccionados, objetivo);
            puntos1 += puntosRonda;
            if (puntosRonda > 0)
            {
                cout << "\n--- Tirada Exitosa! ---\n";
                cout << "Suma objetivo: " << objetivo << "\nDados elegidos: ";
                for (int i = 0; i < tamanoSeleccionados; i++)
                    cout << seleccionados[i] << " ";
                cout << "\nPuntos ganados: " << puntosRonda << "\nDados enviados: " << tamanoSeleccionados << "\n";
                modificarDados(stock1, tamanoSeleccionados, stock2);
                if (chequearTriunfo(stock1, puntos1))
                {
                    cout << "\n========================================\n";
                    cout << jugador1 << " gana la partida!\n";
                    cout << "========================================\n";
                    break;
                }
            }
            else
            {
                cout << "\n--- Tirada No Exitosa ---\n";
                int dadosAntes = stock1;
                castigarFallo(stock1, stock2);
                cout << "Dados recibidos: " << stock1 - dadosAntes << "\n";
            }
        }

        // Turno Jugador 2
        if (turno == 2 || (turno == 1 && rondas <= 3))
        {
            cout << "\nTurno de " << jugador2 << "\n";
            cout << "Stock: " << stock2 << " dados | Puntos: " << puntos2 << "\n";
            int objetivo = lanzarDadosObjetivo();
            cout << "Dados objetivo: " << objetivo << "\n\n";
            int dados[stock2];
            tirarDadosJugador(stock2, dados);
            int seleccionados[stock2], tamanoSeleccionados;
            elegirCombinacion(objetivo, dados, stock2, seleccionados, tamanoSeleccionados);
            int suma = 0;
            for (int i = 0; i < tamanoSeleccionados; i++)
                suma += seleccionados[i];
            int puntosRonda = computarPuntaje(suma, seleccionados, tamanoSeleccionados, objetivo);
            puntos2 += puntosRonda;
            if (puntosRonda > 0)
            {
                cout << "\n--- Tirada Exitosa! ---\n";
                cout << "Suma objetivo: " << objetivo << "\nDados elegidos: ";
                for (int i = 0; i < tamanoSeleccionados; i++)
                    cout << seleccionados[i] << " ";
                cout << "\nPuntos ganados: " << puntosRonda << "\nDados enviados: " << tamanoSeleccionados << "\n";
                modificarDados(stock2, tamanoSeleccionados, stock1);
                if (chequearTriunfo(stock2, puntos2))
                {
                    cout << "\n========================================\n";
                    cout << jugador2 << " gana la partida!\n";
                    cout << "========================================\n";
                    break;
                }
            }
            else
            {
                cout << "\n--- Tirada No Exitosa ---\n";
                int dadosAntes = stock2;
                castigarFallo(stock2, stock1);
                cout << "Dados recibidos: " << stock2 - dadosAntes << "\n";
            }
        }

        cambiarTurno(puntos1, puntos2, stock1, stock2, turno);
    }

    cout << "\n========================================\n";
    cout << "Resultados Finales\n";
    cout << "========================================\n";
    cout << jugador1 << ": " << puntos1 << " puntos | " << stock1 << " dados\n";
    cout << jugador2 << ": " << puntos2 << " puntos | " << stock2 << " dados\n";
    string campeon = definirCampeon(puntos1, puntos2, rondas, jugador1, jugador2);
    cout << "Ganador: " << campeon << " 🏆🎉\n";
    cout << "========================================\n";

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