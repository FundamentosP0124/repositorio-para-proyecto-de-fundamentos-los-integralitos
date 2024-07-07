#include <iostream>
#include <conio.h>
#include <string>
#include <time.h>
#include <cstdio>
#include <unistd.h> 

using namespace std;

//Declaracion de funciones DIA 2
void Evento1Dia2();
void Dia2();

//Declaracion de funciones DIA 3
void explorarRecursos();
void BuscarComida();
void Pantano();
void Cueva();
void Capitulo3();

/*Declaracion de funciones dia 4*/
void Dia4j1();
void Dia4j2();


bool tieneCuchillo=false;
bool AyudarZorro=false;
char decision;
int Arena;
bool Radio=false;

int numrand(int); // Declaracion de funcion de numero aleatorio
void mostrarBarraDeCarga(int progreso, int total) {
    float percent = (float)progreso / total;
    int barWidth = 70;

    cout << "[";
    int pos = barWidth * percent;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) cout << "-";
        else if (i == pos) cout << ">";
        else cout << " ";
    }
    cout << "] " << int(percent * 100.0) << " %\r";
    cout.flush();
}
int main()
{
 int total = 100;
    
    for (int i = 0; i <= total; ++i) {
        mostrarBarraDeCarga(i, total);
       
        usleep(100000); 
    }
    cout << endl;
  
  
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

  
  string inventarioJugador1[10];  //inventario para el jugdaor 1
  string inventarioJugador2[10];  //inventario para el jugdaor 2
  int objetosRecolectados1 = 0;
  int objetosRecolectados2 = 0;


  // Estado fisico de los jugadores
  bool j1esguince = false, j2esguince = false, j1fractura = false, j2fractura = false, j1cortada = false, j2cortada = false;

  do /*Este do se conecta con el while de resp y sirve para volver al menu principal*/
  {
    int opcion;
cout << "\033[95m  <Menu principal/>\033[0m" << endl << endl;
cout << "\033[96m > 1.....Iniciar juego \033[0m\n" << endl;
cout << "\033[93m > 2.....Historia      \033[0m\n" << endl;
cout << "\033[90m > 3.....Como jugar    \033[0m\n" << endl;
cout << "\033[94m > 4.....Creditos      \033[0m\n" << endl;
cout << "\033[91m > 5.....Salir         \033[0m\n" << endl;



    do
    {
      cout << "Digita tu opcion: ";
      cin >> opcion;
      cout << endl;
         
      if (opcion > 5 || opcion < 1)
      {
        cout << "Favor ingrese un valor valido\n";
      }
    } while (opcion > 5 || opcion < 1);

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
      /*Fin de los primeros dialogos entre los jugadores*/

      do
      {
        if (contadordia == 1)
        { // Contador de dias
         cout << "\033[1;35m" << "\t===============\n" << "\033[0m";
         cout << "\033[1;32m\t     Dia 1\033[0m\n";
         cout << "\033[1;35m" << "\t===============\n" << "\033[0m";
          contadordia++;
          
        }
        else if (turno == true)
        {
          cout << endl << endl;
          cout << "\033[1;35m" << "\t===============\n" << "\033[0m";
          cout << "\033[1;32m" << "\t     Dia " << contadordia << "\033[0m" << "\n";
          cout << "\033[1;35m" << "\t===============\n" << "\033[0m";
          cout << endl << endl;

          contadordia++;
      
        }
        switch (turno)
        {
        case true:
        cout << "\033[34m\n\nTurno de " << jugador1 << "\033[0m" << endl;

          switch (contadorswitch)
          {
          case 1:
            cout << "Luego de la caida del avion tu " << jugador1 << " apesar de algunos golpes y heridas te encuentras bien\n";
            cout << "Ves humo a lo lejos viniendo de dos direcciones distantes a donde deberias ir ahora, al humo que se ve al norte o adentrarse en el bosque al este?\n";
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
                     inventarioJugador1[objetosRecolectados1++] = "comida";
                     inventarioJugador1[objetosRecolectados1++] = "agua";


                /*en el inventario ya se agrega agua y comida*/
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
                     inventarioJugador1[objetosRecolectados1++] = "radio";
                    break;
                  case 2:
                    cout << "Encontraste un cuchillo\n";
                     inventarioJugador1[objetosRecolectados1++] = "cuchillo";
                    break;
                  case 3:
                    cout << "Encontrastes un bate\n";
                     inventarioJugador1[objetosRecolectados1++] = "bate";

                    break;
                    /*Agregar al inventario lo que el switch elija*/
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
                    cout << "Encontrastes un fosforos\n";
                     inventarioJugador1[objetosRecolectados1++] = "fosforos";
                    break;
                  case 2:
                    cout << "Encontrastes ropa calida\n";
                     inventarioJugador1[objetosRecolectados1++] = "ropa calida";
                  case 3:
                    cout << "Al abrir la caja una rata salto y salio hullendo, por suerte no te mordio, pero el susto nadie te lo quita\n";
                  }
                    /*Agregar al inventario lo que el switch elija*/

                }
                cout << "Sales de la escotilla\n";
              }
              else
              {
                cout << "Quitas tu atencion de la escotilla y vuelves a mirar a lo que parecia una rata muerta, pero ya no esta\n";
                cout << "Eso te parece estrano pero no le distes importancia\n";
              }
              cout << "Ves la sucia cama de la cabana pero decides acostarte y pasar la noche en el lugar\n";

            
             //fin del dia   
            }
            }else{
            cout<<"Te dirijes al este y te adentras en el bosque, a los minutos de caminata te topas con las ruinas de un castillo\n";
            do{
            cout<<"Quieres entrar a explorar?\n";
            cout<<"\n1. Claro por que si\n"<<"2. Mejor sigo avanzando\n";
            cin>>desicion;
            if (desicion != 1 && desicion != 2)
              {
                cout << "Favor elija una de las opciones disponibles\n";
              }
            }while(desicion !=1 && desicion != 2);
            if(desicion==1){
              cout<<"Ingresas al castillo y estando ahi ves una puerta entre abierta, te asomas y ves una bodega polvosa\n";
              cout<<"Quieres entrar a revisar?\n";
              do{
                cout<<"1. Podria haber algo util en esa bodega\n"<<"2. Se ve viejo y polvoso, no parece haber nada util\n";
                cin>>desicion;
                if (desicionp != 1 && desicionp != 2)
              {
                cout << "Favor elija una de las opciones disponibles\n";
              }
              }while(desicion != 1 && desicion != 2);
              if(desicion==1){
                cout<<"Ingresas en la bodega oscura, no puedes ver nada pero sientes un olor a viejo y polvo\n";
                cout<<"Logras agarrar algo en medio de la obscuridad, no sabes muy bien lo que es\n";
              limitealeatorio = 3;
                numale = numrand(limitealeatorio);
                switch (numale)
                {
                  case 1: 
                  cout<<"Sacas un cuchillo\n";
                  break;
                  case 2:
                  cout<<"Sacas ropa\n";
                  break;
                  case 3:
                  cout<<"Sacas una mota de polvo enorme\n";
                }
              }else{
                cout<<"Ignoras la bodega y sigues con tu camino\n";
              }
              cout<<"Te das cuenta que ese castillo puede servir de refugio para pasar la noche, asi que decides quedarte ahi\n";
            }else{
              cout<<"Sigues avanzando hasta llegar a un lago\n";
              cout<<"Cerca del lago se ve una casa de madera con muelle al lago\n";
              cout<<"Quieres explorar la casa\n";
              do{
                cout<<"1. Veamos que hay adentro\n"<<"2. Mejor veo el lago\n";
                cin>> desicion;
                if (desicion != 1 && desicion != 2)
              {
                cout << "Favor elija una de las opciones disponibles\n";
              }
              }while(desicion!=1&&desicion!=2);
              if(desicion==1){
                cout<<"Ingresas en la casa y ves que esta abandonada, (Lo concluyes por el estado deplorable del lugar)\n";
                cout<<"Ves en la pered una hacha, esta puede ser util para despues\n";
                cout<<"Deseas llevarte el hacha?\n";
                do{
                cout<<"1. Parece una buena idea\n"<<"2. Solo me va a estorbar\n";
                cin>>desicion;
                if (desicion != 1 && desicion != 2)
              {
                cout << "Favor elija una de las opciones disponibles\n";
              }
                }while(desicion!=1&&desicion!=2);
                if(desicion==1){
                  cout<<"Agarras el hachas\n"; //Aqui agarra un hacha
                }else{
                  cout<<"Solo pasas de largo\n";
                }
               cout<<"Por el cansancio de la caminata te sientas a esperar en el muelle viendo el lago hasta que anochece\n";
              }else{
                cout<<"Te quedas viendo el lago....\n";
                cout<<"Hasta que anochece y te metes en la casa, ya que no tienes otro lugar donde ir\n";
              }
            } cout<<"En la casa te acuestas en la cama a pesar de estar sucia y esperas hasta dormir\n";
            }

            cout << endl;
            char invt;
            do
            {
            cout << "Quieres ver tu inventario? (y/n): ";
            cin >> invt;
           } while (invt != 'y' && invt != 'n');

               if (invt == 'y') {
        if (objetosRecolectados1 == 0) {
            cout << "El inventario esta vacio." << endl;
        } else {
            cout << "Inventario de " << jugador1 << ": ";
            for (int i = 0; i < objetosRecolectados1; i++) {
                cout << inventarioJugador1[i] << (i < objetosRecolectados1 - 1 ? ", " : "");
            }
            cout << endl;
        }
    }
          
            break;
          case 2:
            Dia2();
            break;
          case 3:
            Capitulo3();
            break;
          case 4:
            Dia4j1();
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
       cout << "\033[35m\n\nTurno de " << jugador2 << "\033[0m" << endl;
          switch (contadorswitch)
          {
          case 1:
            cout << "Luego de la estrepitosa caida desde el avion tu, "<<jugador2<<" te levantas con dolor y con algunas heridas, pero nada grave\n";
            cout << "Luego de un rato ves a lo lejos en direccion al sur una columna de humno\n";
            cout<< "A donde quieres ir? Al Sur a ver la columna de humo, o dirigirse a la playa\n";
            do{
            cout<< "1. Al sur \n"<<"2. A la playa\n";
            cin>>desicionp;
            if (desicionp != 1 && desicionp != 2)
                {
                  cout << "Favor elija una de las opciones disponibles\n";
                }
            }while(desicionp != 1 && desicionp != 2);
            if(desicionp==1){
              cout<<"Te dirijes al sur y encuentras la cola del avion, parce haber cosas utiles dentro\n";
              cout<<"Deceas entrar a la cola del avion o prefieres adentrarte en el bosque\n";
              do{
                cout<<"1. Veamos que hay adentro\n"<<"2. Mejor no, adentremonos en el bosque\n";
                cin>>desicion;
                if (desicion != 1 && desicion != 2)
                {
                  cout << "Favor elija una de las opciones disponibles\n";
                }
              }while(desicion != 1 && desicion != 2);
              if(desicion==1){
               cout<<"Te adentras en la cola del avion\n";
               cout<<"Encuentras un poco de comida y agua, ademas de los cuerpos de los pasajeros del avion\n";
                     inventarioJugador2[objetosRecolectados2++] = "comida";
                     inventarioJugador2[objetosRecolectados2++] = "agua";
               cout<<"Al fondo encuentras una caja parece tener buenas cosas dentros\n";
               cout<<"Deseas abrirla?\n";
               do{
                 cout<<"1.Claro que si\n"<<"2. Nah\n";
                 cin>>desicion;
                 if (desicion != 1 && desicion != 2)
                {
                  cout << "Favor elija una de las opciones disponibles\n";
                }
               }while(desicion != 1 && desicion != 2);
               if(desicion==1){
                limitealeatorio=3;
                numale=numrand(limitealeatorio);
                switch(numale){
                  case 1: 
                  cout<<"Encontrastes un botiquin\n";
                     inventarioJugador2[objetosRecolectados2++] = "botiquin";
                  break;
                  case 2:
                  cout<<"Encontrastes un cuchillo\n";
                     inventarioJugador2[objetosRecolectados2++] = "cuchillo";
                  break;
                  case 3:
                  cout<<"Encontrastes una radio\n";
                     inventarioJugador2[objetosRecolectados2++] = "radio";
                  break;
                }
               }else{
                cout<<"Sigues con tu camino\n";
               }
               cout<<"Sales del avion y ves que esta anocheciendo, asi que te quedas en el avion para pasar la noche\n";
              }else{
                cout<<"Te adentras en el bosque y caminas por unos minutos\n";
                cout<<"A los lejos te encuentras una aldea con unas cuantas chozas, entras para ver si hay algo util\n";
                cout<<"Al entrar vez una choza mas grande bajando una colina\n"<<"Quieres ver que hay en la choza grandre bajando la colina o ver las chozas a tus alrededores\n";
                do{
                  cout<<"1. Veamos que hay en la choza grande\n"<<"2. Parece inseguro bajar, mejor veamos las chozas a mi alrededor\n";
                  cin>>desicion;
                  if (desicion != 1 && desicion != 2)
                {
                  cout << "Favor elija una de las opciones disponibles\n";
                }
                }while(desicion != 1 && desicion != 2);
                if(desicion==1){
                  cout<<"Bajas para ver la choza, en su interior ves una cama y unas cuantas cajas que parecen haber sido abandonada hace tiempo\n";
                  cout<<"Al fondo ves una caja que parece estar bloqueada por un tozo de madera caido\n";
                  cout<<"Parece algo pesado el levantar el tozo de madera, deseas levantarlo\n";
                  do{
                    cout<<"1. Quiero ver que hay dentro, lo levantare\n"<<"2 .Mejor no podria lastimarme\n";
                    cin>>desicion;
                    if (desicion != 1 && desicion != 2)
                {
                  cout << "Favor elija una de las opciones disponibles\n";
                }
                  }while(desicion != 1 && desicion != 2);
                  if(desicion==1){
                    limitealeatorio = 2;
                    numale = numrand(limitealeatorio);
                    switch(numale){
                      case 1:
                      cout<<"Logras levantas la madera y ves lo que hay adentro\n";
                      limitealeatorio = 2;
                      numale = numrand(limitealeatorio);
                      switch(numale){
                        case 1:
                        cout<<"Encontrastes una cuerda\n";
                     inventarioJugador2[objetosRecolectados2++] = "cuerda";

                        break;
                        case 2:
                        cout<<"Encontrastes un bate\n";
                     inventarioJugador2[objetosRecolectados2++] = "comida";

                        break;
                      }
                      break;
                      case 2:
                      cout<<"Intentas levantar la madera, pero no la logras levantar y te caes\n";
                      cout<<"Te lastimas el tobillo, no es grave pero te impedira moverte agilmente\n";
                      j2esguince = true;
                    }
                  }else{
                    cout<<"Ignoras la caja y sigues explorando\n";
                  }
                  cout<<"Luego exploras pero no encuentras nada util\n";
                  cout<<"Como empieza a anochecer decides pasar la noche en la choza\n";
                }else{
                  cout<<"Investigas las chozas que hay alrededor\n";
                  cout<<"Al ingresar a varias chozas encuentras pocas cosas utiles, solo un poco de comida y agua\n";
                     inventarioJugador2[objetosRecolectados2++] = "comida";
                     inventarioJugador2[objetosRecolectados2++] = "agua";
                  
                  cout<<"Ves una choza que parece estar bloqueada en la entrada\n";
                  cout<<"Parece que puedes entrar por una ventana pero tienes que romper una ventana\n";
                  cout<<"Quieres intentar entrar?\n";
                  do{
                   cout<<"1. Con un golpe se puede romper la ventana para entrar\n"<<"2. Me podria lastimar\n";
                   cin>>desicion;
                   if (desicion != 1 && desicion != 2)
                {
                  cout << "Favor elija una de las opciones disponibles\n";
                }
                  }while(desicion != 1 && desicion != 2);
                  if(desicion==1){
                    limitealeatorio = 2;
                    numale = numrand(limitealeatorio);
                    switch(numale){
                      case 1:
                      cout<<"Golpeas la ventana y te cortas la mano\n";
                      j2cortada = true;
                      break;
                      case 2:
                      cout<<"Golpeas la ventana y milagrosamente no te pasa nada\n";
                      break;
                    
                    }
                  }else{
                    cout<<"Continuas explorando y encuentras una choza mas o menos en buen estado y decides pasar la noche ahi\n";
                  }
                }
              }
            }else{
              cout<<"Te dirijes a la playa\n";
              cout<<"En la playa te encuentras unos cuantos cocos para comer\n";
              cout<<"Caminando un rato en la orilla de la playa ves un yate naufragueado\n";
              cout<<"Quieres ver el barco o mejor sigues caminando por la playa\n";
              do{
               cout<<"1. Veamos que hay adentro\n"<<"2. Mejor no, sigamos avanzando\n";
               cin>>desicion;
               if(desicion != 1 && desicion != 2){
                cout << "Favor elija una de las opciones disponibles\n";
               }
              }while(desicion != 1 && desicion != 2);
              if(desicion==1){
                cout<<"Entras a la cabina del yate donde encuentras algunas prendas y agua\n";
                     inventarioJugador2[objetosRecolectados2++] = "ropa";
                     inventarioJugador2[objetosRecolectados2++] = "agua";


                cout<<"Intentas encender el yate pero este parece estar descompuesto\n";
                cout<<"Exploras al rededor del yate y encuentras el equipaje de los que iban en el yate\n";
                cout<<"No obstante este parece haber caido en una zona con muchas rocas, podria ser peligroso intentar llegar a ellas\n";
                cout<<"Deceas intentar agarrarlas?\n";
                do{
                  cout<<"1. Intentare llegar ahi\n"<<"2. Mejor no, podria lastimarme\n";
                  cin>>desicion;
                  if (desicion != 1 && desicion != 2)
                {
                  cout << "Favor elija una de las opciones disponibles\n";
                }
                }while(desicion != 1 && desicion != 2);
                if(desicion==1){
                  limitealeatorio=2;
                  numale = numrand(limitealeatorio);
                  switch(numale){
                    case 1:
                    cout<<"Alcanzas llegar a el equipaje sin complicaciones\n";
                    break;
                    case 2:
                    cout<<"Intentas llegar pero justo cuando esabas por alcanzar el equipaje te doblas el tobillo\n";
                    j2esguince = true;
                    break;
                  }
                  cout<<"Al abrir la caja\n";
                  limitealeatorio = 3;
                  numale = numrand(limitealeatorio);
                  switch(numale){
                     case 1:
                     cout<<"Encontrastes un hacha\n";
                     inventarioJugador2[objetosRecolectados2++] = "hacha";
                     break;
                     case 2:
                     cout<<"Encontrastes una soga\n";
                     inventarioJugador2[objetosRecolectados2++] = "soga";
                     break;
                     case 3:
                     cout<<"No encontrastes nada\n";
                     break;
                  }
                }else{
                  cout<<"Sigues tu camino\n";
                }
                cout<<"Despues de un rato explorando entras en el yate al ver que esta anocheciendo, y decides pasar la noche ahi\n";
              }else{
                cout<<"Sigues avanzando un rato y llegas a un lugar de la playa donde parece haber sido donde cayo una parte del equipaje del avion\n";
                cout<<"Revisas los equipajes pero mas alla de algo de comida y agua no encuentras nada util\n";
                cout<<"Luego de un rato revisado maletas ves un maletin que tiene un candado, Deseas intentar abrirlo con fuerza bruta y una piedra?\n";
                do{
                cout<<"1. Intentemos aver que pasa\n"<<"2. Mejor no, me podria lastimas las manos\n";
                cin>>desicion;
                if (desicion != 1 && desicion != 2)
                {
                  cout << "Favor elija una de las opciones disponibles\n";
                }
                }while(desicion != 1 && desicion != 2);
                if(desicion==1){
                 limitealeatorio = 2;
                 numale = numrand(limitealeatorio);
                 switch(numale){
                  case 1:
                  cout<<"Al intentar abrir el maletin con la piedra, terminas hacindote una cortada, parce que la piedra tenia un lado contante\n";
                  j2cortada = true;
                  break;
                  case 2:
                  cout<<"Golpeas el candado con la piedra y logras romperlo\n";
                   limitealeatorio = 3;
                   numale = numrand(limitealeatorio);
                   switch(numale){
                      case 1:
                      cout<<"Encontraste una bate\n";
                     inventarioJugador2[objetosRecolectados2++] = "bate";
                      break;
                      case 2:
                      cout<<"Encontrastes un sombrero\n";
                     inventarioJugador2[objetosRecolectados2++] = "sombrero";
                      break;
                      case 3:
                      cout<<"Encontrastes mucho dinero, no creo que te sea muy util en una isla desavitada\n";
                     inventarioJugador2[objetosRecolectados2++] = "100k";
                      break;
                   }
                 }
                }else{
                 cout<<"Dejas la maleta y prestas tu atencion en un cangrejo que andaba por ahi\n";
                }
                cout<<"Continuas caminando hasta que encuentras una cueva, aunque parece humeda decides quedarte a pasar la noche ahi\n";
              }
            }
                
            cout << endl;
            char invt;
            do
            {
            cout << "Quieres ver tu inventario? (y/n): ";
            cin >> invt;
           } while (invt != 'y' && invt != 'n');

               if (invt == 'y') {
        if (objetosRecolectados2 == 0) {
            cout << "El inventario esta vacio." << endl;
        } else {
            cout << "Inventario de " << jugador2 << ": ";
            for (int i = 0; i < objetosRecolectados2; i++) {
                cout << inventarioJugador2[i] << (i < objetosRecolectados2 - 1 ? ", " : "");
            }
            cout << endl;
        }
    }


            break;
          case 2:
            Dia2();
            break;
          case 3:
            Capitulo3();
            break;
          case 4:
            Dia4j2();
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
     cout << "\033[90m <Como jugar/>    \033[0m\n" << endl;
     cout << "\033[90m Este juego se basa en la toma de decisiones criticas que determinaran    \033[0m\n";
     cout << "\033[90m el final de la historia. Lee cuidadosamente la historia y las situaciones presentadas.    \033[0m\n";
     cout << "\033[90m Se te presentaran opciones en momentos clave.    \033[0m\n";
     cout << "\033[90m Usa el teclado para seleccionar la opcion que desees   \033[0m\n";
     cout << "\033[90m Cada decision afectara el desarrollo de la historia y el destino de los personajes.    \033[0m\n";
     cout << "\033[90m Hay multiples finales posibles basados en tus decisiones.   \033[0m\n";
     cout << "\033[90m Buena suerte y elige sabiamente!    \033[0m\n";
      cout << endl;
      do
      {
        cout << "Presiona 1 para volver al menu principal:";
        cin >> resp;
        cout << endl;
      } while (resp != 1);

      break;
    case 4:
     cout << "\033[94m <Creditos/>    \033[0m\n" << endl;
     cout << "\033[94m Daniel Alexander Ayala Escobar   00045824    \033[0m\n" << endl;
     cout << "\033[94m David Alessandro Ventura Montoya 00089724    \033[0m\n" << endl;
     cout << "\033[94m Adrian Alexi Alvarado Melgar     00112624     \033[0m\n" << endl;
    cout << endl << endl;
     do
      {
        cout << "Presiona 1 para volver al menu principal:";
        cin >> resp;
        cout << endl;
      } while (resp != 1);
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

//Aqui van las funciones del CAP 2

void Evento1Dia2(){
int DecisionEvento1Dia2;

    cout<<"Ves a lo lejos el mar y decides ir.\n";
    cout<<"Ves que hay una variedad de especies de flora y fauna que nunca antes habias visto y ya que estas hambriento piensas que puede ser buena idea agarrar de una fruta misteriosa al lado tuyo.\n";
    cout<<"1. Comer de la fruta misteriosa\n";
    cout<<"2. Puede ser venenoso! Mejor no arriesgarme.\n";
    cin>>DecisionEvento1Dia2;

      switch (DecisionEvento1Dia2)
        {
        case 1:
            cout<<"Oh no! La fruta misteriosa resulto ser venenosa! Has muerto.\n";
            break;

        case 2:
            cout<<"Decides caminar un poco y ves cangrejos que podrias usar para comer, asi que decides comerlos para poder sobrevivir mas tiempo";
            cout<<"Ahora ha oscurecido y estas saciado, sin embargo, no tienes donde estar refugiado, por lo que decides volver al lugar del que partiste ya que parecia seguro.\n";
            cout<<"Decides hacer un mini refugio, ahora podras estar a salvo por el resto de la noche.";
            break;

        default: 
            cout<<"Opcion no valida, intenta nuevamente.";
            break;
        }
}

void Dia2(){
int DecisionDia2;

    cout<<"Despiertas al dia siguiente y decides salir del lugar, en busca de poder sobrevivir\n";
    cout<<"Tienes dos opciones, gastar la mayor parte del dia buscando materiales para poder construir un refugio o ir a explorar en medio de la nada.\n";
    cout<<"1. Construir refugio\n";
    cout<<"2. Explorar en medio de la nada\n";
    cin>>DecisionDia2;
    
     switch (DecisionDia2)
        {
        case 1:
            cout<<"A pesar que gastaste toda la parte del dia, has logrado construir un refugio el cual te servira para poder pasar la siguiente noche a salvo, pero has gastado mucha energia.\n";
            cout<<"Debes dormir en tu nuevo refugio para tener energias para el dia siguiente.";
            break;
        case 2:
            Evento1Dia2();
            break;
        default: 
            cout<<"Opcion no valida, intenta nuevamente.";
            break;
        }
}

//Aqui van las funciones del CAP 3
void Capitulo3(){
  
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


    /*Aqui voy a agregar las funciones del dia 4*/
void Dia4j1(){

  cout << "hola" << endl;
}

void Dia4j2(){

  cout << "prueba" << endl;

}
    /*Aqui voy a agregar las funciones del dia 4*/
