#include <iostream>
using namespace std;
#include "funciones.h"

int main()
{
    srand(time(0));

    int opcion = seleccionarOpcion();
    cout << "La opcion seleccionada es " << opcion << endl;
    return 0;
}