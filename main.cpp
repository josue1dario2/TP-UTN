#include <iostream>

using namespace std;


int main() {
  int opcion; 
do
    {
        if (opcion == 1)
        {
		    // TO DO funcionalidad de jugar
        }
        else if (opcion == 2)
        {
         	// TO DO funcionalidad de estadísticas
        }
        else if (opcion == 3)
        {
         	// TO DO funcionalidad de creditos
        }
        else if (opcion == 0)
        {
       		// TO DO funcionalidad de salir de juego preguntar si desea salir 
        }
        else
        {
            cout << "Opción inválida.";
        }
    } while (opcion != 0);
    return 0;
}