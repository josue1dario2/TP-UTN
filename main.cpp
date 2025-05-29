#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()

using namespace std;

// ==============================
// DECLARACIÓN DE FUNCIONES
// ==============================
void mostrarMenu();
void jugar();
void mostrarEstadisticas();
void mostrarCreditos();
bool confirmarSalida();

// ==============================
// FUNCIÓN PRINCIPAL
// ==============================
int main() {
    int opcion;
    bool salir = false;

    do {
        mostrarMenu();
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                jugar();
                break;
            case 2:
                mostrarEstadisticas();
                break;
            case 3:
                mostrarCreditos();
                break;
            case 0:
                if (confirmarSalida()) {
                    salir = true;
                }
                break;
            default:
                cout << "❌ Opción inválida. Intente nuevamente.\n";
        }

        cout << "\nPresione Enter para continuar...";
        cin.ignore();
        cin.get(); 
        system("cls"); // En Windows. Si estás en Linux/Mac: usá system("clear");

    } while (!salir);

    cout << "👋 ¡Gracias por jugar Enfrendados!" << endl;
    return 0;
}

// ==============================
// DEFINICIÓN DE FUNCIONES
// ==============================

void mostrarMenu() {
    cout << "\n==============================" << endl;
    cout << "      🎲 JUEGO: ENFRENDADOS      " << endl;
    cout << "==============================" << endl;
    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADÍSTICAS" << endl;
    cout << "3 - CRÉDITOS" << endl;
    cout << "------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "==============================" << endl;
}

void jugar() {
    string jugador1, jugador2;

    cout << "\n🚀 Comenzando nueva partida...\n";

    // Pedir nombres de jugadores
    cout << "Ingrese el nombre del Jugador 1: ";
    cin >> jugador1;
    cout << "Ingrese el nombre del Jugador 2: ";
    cin >> jugador2;

    // Inicializar la semilla de números aleatorios
    srand(time(0));

    int tirada1, tirada2;

    cout << "\n🎲 Tirada inicial para decidir quién comienza...\n";

    do {
        tirada1 = rand() % 6 + 1;
        tirada2 = rand() % 6 + 1;

        cout << jugador1 << " tira: " << tirada1 << endl;
        cout << jugador2 << " tira: " << tirada2 << endl;

        if (tirada1 == tirada2) {
            cout << "⚠️ Empate. Se vuelve a tirar...\n";
        }

    } while (tirada1 == tirada2);

    string jugadorQueEmpieza = (tirada1 > tirada2) ? jugador1 : jugador2;

    cout << "\n✅ " << jugadorQueEmpieza << " comienza la partida." << endl;
    cout << "[INFO] En la próxima etapa vas a implementar las rondas y el juego." << endl;
}

void mostrarEstadisticas() {
    cout << "\n📊 [ESTADÍSTICAS] Mostrando puntajes históricos..." << endl;
}

void mostrarCreditos() {
    cout << "\n🎓 CRÉDITOS" << endl;
    cout << "Integrantes del equipo:" << endl;
    cout << "1. Apellido1, Nombre1 - Legajo1" << endl;
    cout << "2. Apellido2, Nombre2 - Legajo2" << endl;
    cout << "Equipo: EnfrendadosDev" << endl;
}

bool confirmarSalida() {
    char opcion;
    cout << "¿Seguro que desea salir? (s/n): ";
    cin >> opcion;
    return (opcion == 's' || opcion == 'S');
}
