#include <iostream>

using namespace std;

int seleccionarOpcion();

int main()
{
    int opcion = seleccionarOpcion();
    cout << "La opcion seleccionada es " << opcion << endl;

    return 0;
}

int seleccionarOpcion()
{
    int opcion;
    cout << "Seleccione una opción: " << endl;
    cout << "1.Jugar" << endl;
    cout << "2.Estadísticas" << endl;
    cout << "3.Créditos" << endl;
    cout << "4.Salir" << endl;
    cin >> opcion;
    return opcion;
}