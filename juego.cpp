#include <iostream>
#include <conio.h>
#include <string>
#include <time.h>
using namespace std;

int numrand(); //Declaracion de funcion de numero aleatorio
int desiciones();
int main(){

cout << "Pulsa cualquier letra para comenzar..." << endl << endl;
    _getch();

int resp;  /*Variable para volver al menu principal*/ 
int j1vida=100,j2vida=100, limitedias=10, contadordia=1;//La vida de los jugadores, limite de dias y contador de dias
bool turno=true; //Son los turnos de cada jugador
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
    cout << endl;
    /*Dialogo de los personajes*/
    cout << "======================" << endl;
    cout << "**Inicia el juego**" << endl;
    cout << "======================" << endl;
    cout << endl;
    cout << jugador1 << ": " << "No puedo creer que finalmente estemos en camino a Londres para presentar nuestro proyecto" << endl;
    cout << jugador2 << ": "<< "Si, despues de todo el trabajo duro, esto es irreal" << endl;
    cout << jugador1 << ": "<< "Nuestro algoritmo va a cambiar el mundo, estoy seguro de eso" << endl;
    cout << jugador2 << ": "<< "Y no solo eso, los millones y la fama mundial no estaran nada mal!" << endl;
    cout << jugador1 << ": "<< "Tienes razon. Este es solo el comienzo de algo grande" << endl;
    cout << jugador2 << ": "<< "Mira, estamos a punto de despegar. Preparate!" << endl;
    cout << endl << "Unas horas mas tarde, en medio del vuelo, el avion sufre un desperfecto..." << endl << endl;
    cout << "Piloto: " "Atencion pasajeros, estamos experimentando un problema tecnico grave! Preparense para un aterrizaje de emergencia" << endl << endl;
    cout << jugador1 << ": "<< "Oh no! Que vamos a hacer?" << endl;
    cout << jugador2 << ": "<< "Manten la calma, tenemos que seguir las instrucciones del piloto y esperar lo mejor" << endl;
    cout << endl << "El avion se estrella en una isla remota en medio del oceano..." << endl << endl;
    cout << jugador1 << ": "<< "Estas bien?" << endl;
    cout << jugador2 << ": "<< "Si, creo que si. Donde estamos?" << endl;
    cout << jugador1 << ": "<< "Parece que estamos varados en una isla desierta..." << endl;
    cout << jugador2 << ": "<< "Tenemos que buscar refugio y agua. No podemos quedarnos aqui esperando" << endl;
    cout << jugador1 << ": "<< "Tienes razon. Vamos, no podemos rendirnos ahora." << endl << endl;
  /*Fin de los primeros dialogos entre los jugadores :3*/


    do{
      if(contadordia==1){   //Contador de dias
        cout << "===============" << endl;
        cout<<"Dia 1\n";
        cout << "===============" << endl;
        contadordia++;
      }else if(turno==true){
       cout<<"Dia "<<contadordia<<"\n";
       contadordia++;
      }

      switch (turno){
    case true:
       cout<<desiciones(); //Aqui va todo el codigo del juador 1, el cout es namas para ver si funcionaba lo de los turnes jeje
       
        break;

    case false:
    cout<<desiciones(); //Aqui va todo el codigo del jugador 2
        break;
    }
    if(turno==true){
        turno = false;
    }else{
        turno = true;
    }
    if(turno==true){ //Para los turnos como un turno se gasta cuando pasan los dos jugadores entonces deben de jugar los dos para poder pasar un turno
      limitedias--;
    }
   
    
    }while(j1vida!=0&&j2vida!=0&&limitedias!=0); 
        /*Agregar codigo aca papuh*/
        break;
    case 2:
        cout << "Historia del juego" << endl << endl;
        cout << "Dos amigos inseparables desarrollan un algoritmo revolucionario que les promete millones y fama mundial." << endl;
        cout << "En camino a una reunion crucial en Londres, su jet privado se estrella en una isla remota" << endl;
        cout << "Con pocos recursos, luchan por sobrevivir, construyendo refugios y buscando alimentos" << endl;
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
dato = 1 + rand()%(6);
return dato;
}

int desiciones(){
int numale = numrand();

switch(numale){
  case 1:
  cout<<"A";
  break;
  case 2:
  cout<<"b";
  break;
  case 3:
  cout<<"C";
  break;
  case 4:
  cout<<"D";
  break;
  case 5:
  cout<<"E";
  break;
  case 6:
  cout<<"F";
  break;
}
return numale;
}