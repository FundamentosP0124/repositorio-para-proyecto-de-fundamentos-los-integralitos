#include <iostream>
#include <time.h>
#include <string>
using namespace std;

int main()
{
    string objetosDisponibles[] = {"cuchillo", "fosforos", "radio", "alimentos", "bebidas", "lupa"};
    string suministros[4];
    char a;
    int objetosRecolectados = 0;
    srand(static_cast<unsigned int>(time(0)));

    while (objetosRecolectados < 4)
    {
        cout << "Quieres recolectar un objeto? (y/n): ";
        cin >> a;

        if (a == 'y')
        {
            int indiceAleatorio;
            bool objetoRepetido;
            do
            {
                objetoRepetido = false;
                indiceAleatorio = rand() % 6;

                for (int i = 0; i < objetosRecolectados; i++)
                {
                    if (suministros[i] == objetosDisponibles[indiceAleatorio])
                    {
                        objetoRepetido = true;
                        break;
                    }
                }
            } while (objetoRepetido);

            suministros[objetosRecolectados++] = objetosDisponibles[indiceAleatorio];
            cout << "Recolectaste: " << suministros[objetosRecolectados - 1] << endl;
        }
        else
        {
            cout << "No has recolectado ningun objeto." << endl;
            break;
        }
    }

    if (objetosRecolectados > 0) {
        cout << "Objetos recolectados: ";
        for (int i = 0; i < objetosRecolectados; i++) {
            cout << suministros[i] << (i < objetosRecolectados - 1 ? ", " : "");
        }
        cout << endl;
    }

    return 0;
}
