#include <iostream>
using namespace std;

void explorarRecursos();
void BuscarComida();
void Pantano();
void Cueva();

bool tieneCuchillo=false;
bool AyudarZorro=false;
char decision;
int Arena;
bool Radio=false;

int main() {
    int decisionCap3;
    cout << "Has despertado, sin embargo resultas muy hambriento y de escasos recursos para sobrevivir, necesitas buscar algo urgente para comer o de lo contrario moriras de hambre.\n";
    cout << "Elige una opcion: \n";
    cout << "1. Explorar recursos\n";
    cout << "2. Buscar comida\n";

    cin >> decisionCap3;

    switch (decisionCap3) {
        case 1:
            explorarRecursos();
            break;
        case 2:
            BuscarComida();
            break;
        default:
            cout << "Opcion no valida.\n";
            break;
    }

    return 0;
}

//Aqui van a ir las dos primeras opciones del main

//Toda la funcion explorar Recursos

void explorarRecursos() {
    int opcion;

      cout << "Estas escaso de recursos y piensas que podria ayudarte a sobrevivir. A lo lejos ves que hay un pantano y dentro hay una cueva. Decides explorar el pantano o la cueva.\n";

    do {
        cout << "Donde quieres buscar recursos?\n";
        cout << "1. Pantano\n";
        cout << "2. Cueva\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                Pantano();
                break;
            case 2:
                Cueva();
                break;
            default:
                cout << "Opcion no valida. Intentalo de nuevo.\n";
                break;
        }
    } while (opcion != 1 && opcion != 2);
}

//Toda la funcion buscar comida (No le agrego funcion a los casos porque los tres son muy cortos)

void BuscarComida() {
    int opcionComida;

    cout << "Decides explorar el pantano en busca de comida.\n";
    cout << "Encuentras varias opciones para buscar:\n";
    cout << "1. Buscar frutas en los arboles\n";
    cout << "2. Buscar raices comestibles\n";
    cout << "3. Buscar huevos de aves en los arboles\n";
    cout << "Elige una opcion: ";
    cin >> opcionComida;

    switch (opcionComida) {
        case 1:
            cout << "Intentas subir a un arbol para buscar frutas, pero resbalas y te lastimas.\n";
            cout << "Decides regresar a tu refugio para curarte.\n";
            break;
        case 2:
            cout << "Encuentras raices comestibles y las recolectas con cuidado.\n";
            cout << "Decides regresar a tu refugio con las raices.\n";
            break;
        case 3:
            cout << "Alcanzas un nido y encuentras huevos, pero al intentar bajar, caes y te lastimas.\n";
            cout << "Decides regresar a tu refugio para curarte.\n";
            break;
        default:
            cout << "No encuentras nada util y decides regresar a tu refugio.\n";
            break;
    }
}


//Aqui iran las opciones de "Explorar recursos"

    void Pantano(){
         cout << "Te encuentras con un animal... Este es una especie de zorro que nunca habias visto, pero parece agradable\n";
         cout << "Ves que esta atrapado, tienes la opcion de liberarlo o puedes no hacerlo.";
         cout << "Lo ayudaras? (y/n)\n";
         cin >> decision;

                if (decision == 'y') {
                AyudarZorro = true;
                cout << "Has ayudado al zorro, el zorro escapa pero recordara tu cara.\n";
            } else {
                AyudarZorro = false;
                cout << "No has ayudado al zorro, el zorro ha quedado atrapado.\n";
            }
            cout << "Sigues tu camino y ves que hay arena movediza, tiras un objeto hacia ella y ves que todo lo que arrojas es rapidamente absorbida por la arena\n";
            cout << "Quieres cruzar por la arena movediza o prefieres desviarte y seguir buscando materiales en otro lugar? Cruzarla se ve mortal.\n";
            cout << "1. Cruzarla\n";
            cout << "2. Seguir por otro camino\n";
            cin >> Arena;

            switch (Arena)
            {
            case 1:
            cout<<"Has decidido cruzar, has muerto";
                break;
            case 2: 
            cout<<"Sigues el camino y encuentras un material filoso con el que decides armar un cuchillo, el cual te servira para defenderte y poder cortar cosas.";
            tieneCuchillo=true;
            cout<<"Ahora regresas de camino a tu refugio y con el cuchillo cortas de los arboles fruta que sabes que no es mortal para poder comer, con lo cual tienes un poco de energia para poder pasar el resto de la noche.\n";
            break;
            default:
            cout<<"Opcion no valida, intenta de nuevo.";
                break;
            }
    }
    void Cueva(){
                cout << "Has encontrado un esqueleto, parece tener una nota.\n";
                cout << "Nota: Estoy atrapado en este lugar inhospito y frio, sin ropa, sin comida, sin agua, solamente yo y mi capacidad de poder escribir a pesar de haber sobrevivido\n"; // Esta es la nota que contenia un esqueleto en un bote de la cueva
                cout << "todos estos dias en este infierno, quien habria dicho que aquellos habitantes de esta isla tan alejada de todo serian unos completos enfermos.\n";
                cout << "Fin de la nota.\n";
                Radio=true;
                cout << "Has encontrado: Radio\n";
                cout << "Has quedado en shock y comienzas a asustarte con tu alrededor, tienes muchas preguntas, decides ir a tu refugio para protegerte de lo que sea que haya sido eso.";
    }