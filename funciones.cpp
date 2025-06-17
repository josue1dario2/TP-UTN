#include "funciones.h"
#include "rlutil.h"
#include <ctime>
#include <iostream>

using namespace std;

int tirarDado(int caras)
{
    return (rand() % caras) + 1;
}

void mostrarCreditos()
{
    limpiarPantalla();
    cout << "Creditos\n";
    cout << "Juego: Enfrendados\n";
    cout << "Creado por: Equipo 15\n";
    cout << "Integrantes:\n";
    cout << "- Maffey, Lucia, 31862\n";
    cout << "- Rivero, Camila, 32508\n";
    cout << "- Solis, Josue, 32522\n";
    cout << "- Totilo, Ivan, 29192\n";
    cout << "Íconos por Freepik, Logo por Logo Maker\n";
    cout << "Diseño del juego por Angel Simon\n";
}

void limpiarPantalla()
{
    rlutil::cls();
}

int quienEmpieza(string jugador1, string jugador2)
{
    int dado1, dado2;
    srand(time(0)); // Inicializa el generador de números aleatorios con la hora actual

    do
    {
        dado1 = tirarDado(6);
        dado2 = tirarDado(6);
        cout << jugador1 << " tira: " << dado1 << endl;
        cout << jugador2 << " tira: " << dado2 << endl;

        if (dado1 == dado2)
        {
            cout << "¡Empate! Tirando de nuevo..." << endl;
        }
    } while (dado1 == dado2);

    if (dado1 > dado2)
    {
        cout << jugador1 << " gana la tirada inicial!" << endl;
        return 1;
    }
    else
    {
        cout << jugador2 << " gana la tirada inicial!" << endl;
        return 2;
    }
}

void mostrarMenu()
{
    cout << "    _______   ____________  _______  ______  ___    ____  ____  _____\n";
    cout << "   / ____/ | / / ____/ __ \\/ ___/ | / / __ \\/   |  / __ \\/ __ \\/ ___/\n";
    cout << "  / __/ /  |/ / /_  / /_/ / __//  |/ / / / / /| | / / / / / / /\\__ \\\n";
    cout << " / /___/ /|  / __/ / _  _/ /__/ /|  / /_/ / ___ |/ /_/ / /_/ /___/ /\n";
    cout << "/_____/_/ |_/_/   /_/ |_/____/_/  _/_____/_/  |_/_____/\\____/_____/\n";
    cout << "\n1 - JUGAR\n2 - ESTADISTICAS\n3 - CREDITOS\n---------------------\n0 - SALIR\n";
    cout << "Opción: ";
}
int lanzarDadosObjetivo()
{
    return tirarDado(12) + tirarDado(12);
}

string definirCampeon(int puntos1, int puntos2, int rondas, string jugador1, string jugador2)
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
        return "Empate";
    }
}

void tirarDadosJugador(int cantidad, int dados[])
{

    for (int i = 0; i < cantidad; i++)
    {
        dados[i] = tirarDado(cantidad);
    }
}

int computarPuntaje(int suma, int dadosElegidos[], int tamano, int objetivo)
{
    if (suma == objetivo)
    {
        return suma * tamano;
    }
    else
    {
        return 0;
    }
}

void elegirCombinacion(int objetivo, int dados[], int tamano, int seleccionados[], int &tamanoSeleccionados)
{
    tamanoSeleccionados = 0;
    int sumaActual = 0;
    cout << "Dados disponibles:\n";
    for (int i = 0; i < tamano; i++)
    {
        cout << "  [" << i + 1 << "] " << dados[i];
    }
    cout << "\n\nSelecciona los dados por su número (0 para terminar): ";
    while (sumaActual < objetivo)
    {
        int indiceDado;
        cin >> indiceDado;
        if (indiceDado == 0)
        {
            tamanoSeleccionados = 0;
            return;
        }
        if (indiceDado < 1 || indiceDado > tamano)
        {
            cout << "Número inválido. Intenta de nuevo: ";
            continue;
        }
        seleccionados[tamanoSeleccionados++] = dados[indiceDado - 1];
        sumaActual += dados[indiceDado - 1];
        cout << "Suma actual: " << sumaActual << "\n";
        if (sumaActual == objetivo)
            return;
        if (sumaActual > objetivo)
        {
            tamanoSeleccionados = 0;
            return;
        }
        cout << "Siguiente dado (0 para terminar): ";
    }
}

void modificarDados(int &jugador, int tamanoSeleccionados, int &rival)
{
    jugador -= tamanoSeleccionados;
    rival += tamanoSeleccionados;
}

void castigarFallo(int &jugador, int &rival)
{
    if (rival > 1)
    {
        rival--;
        jugador++;
    }
}

void cambiarTurno(int &puntos1, int &puntos2, int &stock1, int &stock2, int &turno)
{
    if (turno == 1)
        turno = 2;
    else
        turno = 1;
}

bool chequearTriunfo(int jugador, int &puntos)
{
    if (jugador == 0)
    {
        puntos += 10000;
        return true;
    }
    else
    {
        return false;
    }
}
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