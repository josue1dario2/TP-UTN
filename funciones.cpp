#include "funciones.h"
#include <iostream>
using namespace std;

int seleccionarOpcion()
{
    int opcion;
    do
    {
        cout << "Menu principal: " << endl;
        cout << "1.Jugar" << endl;
        cout << "2.Estadísticas" << endl;
        cout << "3.Créditos" << endl;
        cout << "0.Salir" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 0:
            return 0;
            break;
        }
    } while (opcion != 0);
    return opcion;
}