#include <iostream>
#include <conio.h>
#include <string>
#include <time.h>
#include <cstdio>
using namespace std;



int numrand(int); // Declaracion de funcion de numero aleatorio
int main()
{
  
  cout << "Pulsa cualquier letra para comenzar..." << endl
       << endl;
  _getch();
  int limitealeatorio = 0;
  int numale = 0;                                                   // Numero aleatorio
  int resp;                                                         /*Variable para volver al menu principal*/
  int j1vida = 100, j2vida = 100, limitedias = 7, contadordia = 1, contadorswitch=1; // La vida de los jugadores, limite de dias y contador de dias
  bool turno = true;                                                // Son los turnos de cada jugador
  string jugador1, jugador2;                                        /*variables para almacenar los nombres de los jugadores*/
  int desicion = 0, desicionp = 0;                                               // Para tomar deciciones dentro del juego

  // Estado fisico de los jugadores
  bool j1esguince = false, j2esguince = false, j1fractura = false, j2fractura = false, j1cortada = false, j2cortada = false;

  do /*Este do se conecta con el while de resp y sirve para volver al menu principal*/
  {
    int opcion;
   
    cout << "\033[105;97m<Menu principal/>      \033[0m" << endl << endl;
    cout << "\033[106;97m > 1.....Iniciar juego \033[0m\n" << endl;
    cout << "\033[103;97m > 2.....Historia      \033[0m\n" << endl;
    cout << "\033[104;97m > 3.....Como jugar    \033[0m\n" << endl;
    cout << "\033[104;97m > 4.....Creditos      \033[0m\n" <<endl;
    cout << "\033[101;97m > 5.....Salir         \033[0m\n" << endl;
    do
    {
      cout << "Digita tu opcion: ";
      cin >> opcion;
      cout << endl;
         
      if (opcion > 4 || opcion < 1)
      {
        cout << "Favor ingrese un valor valido\n";
      }
    } while (opcion > 4 || opcion < 1);

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
      cout << jugador2 << ": " << "Si, despues de todo el trabajo duro, esto es irreal" << endl;
      cout << jugador1 << ": " << "Nuestro algoritmo va a cambiar el mundo, estoy seguro de eso" << endl;
      cout << jugador2 << ": " << "Y no solo eso, los millones y la fama mundial no estaran nada mal!" << endl;
      cout << jugador1 << ": " << "Tienes razon. Este es solo el comienzo de algo grande" << endl;
      cout << jugador2 << ": " << "Mira, estamos a punto de despegar. Preparate!" << endl;
      cout << endl
           << "Unas horas mas tarde, en medio del vuelo, el avion sufre un desperfecto..." << endl
            << endl;
      cout << "Piloto: "
              "Atencion pasajeros, estamos experimentando un problema tecnico grave! Preparense para un aterrizaje de emergencia"
           << endl
           << endl;
      cout << jugador1 << ": " << "Oh no! Que vamos a hacer?" << endl;
      cout << jugador2 << ": " << "Manten la calma, tenemos que seguir las instrucciones del piloto y esperar lo mejor" << endl;
      cout << endl
           << "El avion se estrella en una isla remota en medio del oceano..." << endl
           << endl;
      cout << jugador1 << ": " << "Estas bien?" << endl;
      cout << jugador2 << ": " << "Si, creo que si. Donde estamos?" << endl;
      cout << jugador1 << ": " << "Parece que estamos varados en una isla desierta..." << endl;
      cout << jugador2 << ": " << "Tenemos que buscar refugio y agua. No podemos quedarnos aqui esperando" << endl;
      cout << jugador1 << ": " << "Tienes razon. Vamos, no podemos rendirnos ahora." << endl
           << endl;
      /*Fin de los primeros dialogos entre los jugadores :3*/

      do
      {
        if (contadordia == 1)
        { // Contador de dias
          cout << "\t===============" << endl;
          cout << "\t    Dia 1\n";
          cout << "\t===============" << endl;
          contadordia++;
          
        }
        else if (turno == true)
        {
          cout << "\t===============\n";
          cout << "\tDia " << contadordia << "\n";
          cout << "\t===============\n";
          contadordia++;
      
        }
        switch (turno)
        {
        case true:

          switch (contadorswitch)
          {
          case 1:
            cout << "Luego de la caida del avion tu " << jugador1 << " apesar de algunos golpes y heridas te encuentras bien\n";
            cout << "Ves humo a lo lejos viniendo de dos direcciones distantes a donde deberias ir ahora al humo que se ve al norte o el humo que se ve al este?\n";
            do
            {
              cout << "1. Al norte\n"
                   << "2. Al este\n";
              cin >> desicionp;
              if (desicionp != 1 && desicionp != 2)
              {
                cout << "Favor elija una de las opciones disponibles\n";
              }
            } while (desicionp != 1 && desicionp != 2);

            if (desicionp == 1)
            {
              cout << "Al atravezar un poco de bosque encuentras los restos de la cabina del avion\n";
              cout << "Aunque pueda tener en su interior cosas para ayudarte a sobrevivir se ve un poco inseguro\n";
              cout << "Deseas entrar a la cabina o investigar los alrededores?\n";
              do
              {

                cout << "1. Investigare la cabina del avion\n"
                     << "2. Mejor vere que hay en sus alrededores\n";
                cin >> desicion;
                if (desicion != 1 && desicion != 2)
                {
                  cout << "Favor elija una de las opciones disponibles\n";
                }
                
              } while (desicion != 1 && desicion != 2);

              if (desicion == 1)
              {
                cout << "Ingresas a la cabina del avion y enuentras un poco de comida y agua\n";
                cout << "Ademas de una caja de madera ¿Deseas abrirla?\n";
                do
                {

                  cout << "1. Si, puede tener algo util\n"
                       << "2. No gracias\n";
                  cin>>desicion;
                  if (desicion != 1 && desicion != 2)
                  {
                    cout << "Favor elija una de las opciones disponibles\n";
                  }
                } while (desicion != 1 && desicion != 2);
                if (desicion == 1)
                {
                  limitealeatorio = 3;
                  numale = numrand(limitealeatorio);
                  switch (numale)
                  {
                  case 1:
                    cout << "Encotrastes una radio\n";
                    break;
                  case 2:
                    cout << "Encontraste un cuchillo\n";
                    break;
                  case 3:
                    cout << "Encontrastes un bate\n";
                    break;
                  }
                }
                else
                {
                  cout << "Sales del avion y sigues tu camino\n";
                }
                cout << "Al salir del avion observas que se la noche comienza a parecer ser mejor buscar un lugar para descansar y quizas dormir\n";
                cout << "Afortunadamente encuentras una cueva cerca de el avion asi que decides descansar ahi\n";
              }
              else
            {
              cout << "Te adentras en el bosque y te topas con una cabana, decides entrar pues parece estar abandonada\n";
              cout << "Adentro encuentras un lugar sucio pero sigue siendo mejor que dormir en la tierra humeda del bosque\n";
              cout << "Mientras miras con desden y melancolia una esquina donde parece haber una rata muerta, logras diferenciar una escotilla en el suelo\n";
              cout << "Parece un sotano, ¿quieres investigar?\n";
              do
              {

                cout << "1. Claro puede haber algo util\n"<< "2. Mejor no, podria ser peligroso\n";
                cin >> desicion;
                if (desicion != 1 && desicion != 2)
                {
                  cout << "Favor elija una de las opciones disponibles\n";
                }
              } while (desicion != 1 && desicion != 2);
              if (desicion == 1)
              {
                cout << "Bajas con cuidado las escaleras, sin embargo, la suerte no parece estar de tu lado y uno de los escalones se rompe y caes por las escaleras\n";
                limitealeatorio = 3;
                numale = numrand(limitealeatorio);
                switch (numale)
                {
                case 1:
                  cout << "Caes pero no te ha pasado nada grave y solo fue un susto\n";
                  break;
                case 2:
                  cout << "Caes y la suerte no estaba de tu lado pues de lastimas el tobillo, no es grabe pero no podras moverte tan agilmente\n";
                  j1esguince = true;
                  break;
                case 3:
                  cout << "Caes y se te viene a la mente ese amargo recuerdo cuando en la oficina te caistes de la silla y todos se rieron\n";
                  cout << "Fisicamente te encuentras bien, pero tu ego no lo esta\n";
                  break;
                }
                cout << "Luego de la caida vez una caja, Quieres abrirla?\n";
                do
                {

                  cout << "1. Veamos si hay algo interesante\n"<< "2. Podria haber una rata ahi, mejor no\n";
                  cin >> desicion;
                  if (desicion != 1 && desicion != 2)
                  {
                    cout << "Favor elija una de las opciones disponibles\n";
                  }
                } while (desicion != 1 && desicion != 2);
                if (desicion == 1)
                {
                  limitealeatorio = 3;
                  numale = numrand(limitealeatorio);
                  switch (numale)
                  {
                  case 1:
                    cout << "Encontrastes un cuchillo\n";
                    break;
                  case 2:
                    cout << "Encontrastes ropa calida\n";
                  case 3:
                    cout << "Al abrir la caja una rata salto y salio hullendo, por suerte no te mordio, pero el susto nadie te lo quita\n";
                  }
                }
                cout << "Sales de la escotilla\n";
              }
              else
              {
                cout << "Quitas tu atencion de la escotilla y vuelves a mirar a lo que parecia una rata muerta, pero ya no esta\n";
                cout << "Eso te parece estrano pero no le distes importancia\n";
              }
              cout << "Ves la sucia cama de la cabana pero decides acostarte y pasar la noche en el lugar\n";
            }

            cout <<"Quieres ver tu inventario?  y/n" << endl;
            
             //fin del dia 1
              
            }
            
            break;
          case 2:
            cout << "b\n";
            break;
          case 3:
            cout << "C\n";
            break;
          case 4:
            cout << "D\n";
            break;
          case 5:
            cout << "E\n";
            break;
          case 6:
            cout << "F\n";
            break;
          }
          _getch();
          numale = 0;
          break;
          // Aqui va todo el codigo del juador 1, el cout es namas para ver si funcionaba lo de los turnes jeje
        case false:
          switch (contadorswitch)
          {
          case 1:
            cout << "A\n";
            break;
          case 2:
            cout << "b\n";
            break;
          case 3:
            cout << "C\n";
            break;
          case 4:
            cout << "D\n";
            break;
          case 5:
            cout << "E\n";
            break;
          case 6:
            cout << "F\n";
            break;
          }
          _getch();
          numale = 0; // Aqui va todo el codigo del jugador 2
          break;
        }
        if (turno == true)
        {
          turno = false;
        }
        else
        {
          turno = true;
        }
        if (turno == true)
        { // Para los turnos como un turno se gasta cuando pasan los dos jugadores entonces deben de jugar los dos para poder pasar un turno
          limitedias--;
          contadorswitch++;
        }

      } while (j1vida != 0 && j2vida != 0 && limitedias != 0);
      /*Agregar codigo aca papuh*/
      break;
    case 2:
         cout << "\033[93m <Historia del juego/>  \033[0m\n" << endl;
         cout << "\033[93m Dos amigos inseparables desarrollan un algoritmo revolucionario que les promete millones y fama mundial.  \033[0m\n";
         cout << "\033[93m En camino a una reunion crucial en Londres, su jet privado se estrella en una isla remota  \033[0m\n";
         cout << "\033[93m Con pocos recursos, luchan por sobrevivir, construyendo refugios y buscando alimentos  \033[0m\n";
         cout << "\033[93m La situacion se vuelve desesperada con el paso de los dias, y ambos se debilitan por la falta de comida y agua  \033[0m\n";
         cout << "\033[93m La tension crece mientras enfrentan la posibilidad de no ser rescatados, poniendo su amistad y sus vidas en riesgo  \033[0m\n" << endl;
         
      do
      {
        cout << "Presiona 1 para volver al menu principal:";
        cin >> resp;
        cout << endl;

      } while (resp != 1);
      break;
    case 3:
     cout << "\033[94m <Como jugar/>    \033[0m\n" << endl;
     cout << "\033[94m Este juego se basa en la toma de decisiones criticas que determinaran    \033[0m\n";
     cout << "\033[94m el final de la historia. Lee cuidadosamente la historia y las situaciones presentadas.    \033[0m\n";
     cout << "\033[94m Se te presentaran opciones en momentos clave.    \033[0m\n";
     cout << "\033[94m Usa el teclado para seleccionar la opcion que desees   \033[0m\n";
     cout << "\033[94m Cada decision afectara el desarrollo de la historia y el destino de los personajes.    \033[0m\n";
     cout << "\033[94m Hay multiples finales posibles basados en tus decisiones.   \033[0m\n";
     cout << "\033[94m Buena suerte y elige sabiamente!    \033[0m\n";
      cout << endl;
      do
      {
        cout << "Presiona 1 para volver al menu principal:";
        cin >> resp;
        cout << endl;
      } while (resp != 1);

      break;
    case 4:
    cout<<"Creditos\n";
    cout<<"Daniel Alexander Ayala Escobar 00045824\n";  
    break;
    case 5:

    cout << "\033[91mGracias por jugar a nuestro juego\033[0m\n" << endl;
      cout << "" << endl;
      cout << endl;
      return 0;
      break;
    }

  } while (resp == 1);
  return 0;
}

int numrand(int limitealatorio)
{ // Funcion para numero aleatorio
  int dato = 0;
  srand(time(NULL));
  dato = 1 + rand() % (limitealatorio);
  return dato;
}
