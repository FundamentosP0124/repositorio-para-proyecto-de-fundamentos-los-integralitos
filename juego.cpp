#include <iostream>
#include <conio.h>
#include <string>
#include <time.h>
using namespace std;

int numrand(); //Declaracion de funcion de numero aleatorio

int main(){

cout << "Pulsa cualquier letra para comenzar..." << endl << endl;
    _getch();

int resp;  /*Variable para volver al menu principal*/ 
string jugador1, jugador2; /*variables para almacenar los nombres de los jugadores*/
do /*Este do se conecta con el while de resp y sirve para volver al menu principal*/
{
int opcion;
    cout << "**Menu principal**" <<endl << endl;
    cout << " 1..... Iniciar juego " <<endl;
    cout << " 2......Historia " <<endl;
    cout << " 3......Como jugar " <<endl;
    cout << " 4......Salir " <<endl;
  do{
    cout << "Digita tu opcion: ";
    cin >> opcion;
    cout << endl << endl;
    /*Esto lo hice para que el usuario este obligado a dogitar un numero valido*/
     if(opcion > 4||opcion<1){
        cout<<"Favor ingrese un valor valido\n";
     }
 } while (opcion > 4||opcion<1);

    switch (opcion)
    {
    case 1:

    cout << "Por favor, ingresa el nombre del jugador 1: ";
    cin >> jugador1;
    cout << "Ahora ingresa el nombre del jugador 2: ";
    cin >> jugador2;
    

        /*Agregar codigo aca papuh*/
        break;
    case 2:
        cout << "Historia del juego" << endl;
        cout << "Dos amigos inseparables desarrollan un algoritmo revolucionario que les promete millones y fama mundial." << endl;
        cout << "En camino a una reunion crucial en Londres, su jet privado se estrella en una isla remota." << endl;
        cout << "Con pocos recursos, luchan por sobrevivir, construyendo refugios y buscando alimentos." << endl;
        cout << "La situacion se vuelve desesperada con el paso de los dias, y ambos se debilitan por la falta de comida y agua" << endl;
        cout << "La tension crece mientras enfrentan la posibilidad de no ser rescatados, poniendo su amistad y sus vidas en riesgo" << endl;
        cout << endl;
    do
    { cout << "Presiona 1 para volver al menu principal:";
      cin >> resp;  } while (resp != 1);
        break;
    case 3:
        cout << "Este juego se basa en la toma de decisiones criticas que determinaran" << endl;
        cout << "el final de la historia. Lee cuidadosamente la historia y las situaciones presentadas." << endl;
        cout << "Se te presentaran opciones en momentos clave." << endl;
        cout << "Usa el teclado para seleccionar la opcion que desees" << endl;
        cout << "Cada decision afectara el desarrollo de la historia y el destino de los personajes." << endl;
        cout << "Hay multiples finales posibles basados en tus decisiones." << endl;
        cout << "Buena suerte y elige sabiamente!" << endl;
        cout << endl;
         do
    { cout << "Presiona 1 para volver al menu principal:";
      cin >> resp;  } while (resp != 1);

        break;
    case 4:
        cout << "Gracias por jugar a nuestro juego" << endl;
        cout  << endl;
        return 0;
        break;

     }

}while (resp == 1);
    return 0;
}

int numrand(){  //Funcion para numero aleatorio
int dato;
srand(time(NULL));
dato = 1 + rand()%(100);
return dato;
}
