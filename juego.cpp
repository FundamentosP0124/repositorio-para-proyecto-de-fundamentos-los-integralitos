#include <iostream>
#include <conio.h>
#include <string>
#include <time.h>
#include <cstdio>
#include <unistd.h> 
#include <chrono>
#include <thread>

using namespace std;

// Estado fisico de los jugadores
  bool j1esguince = false, j2esguince = false, j1fractura = false, j2fractura = false, j1cortada = false, j2cortada = false;
  int contadorpuntoj1 = 0, contadorpuntosj2 = 0;



  string inventarioJugador1[10];  //inventario para el jugdaor 1
  string inventarioJugador2[10];  //inventario para el jugdaor 2
  int objetosRecolectados1 = 0;
  int objetosRecolectados2 = 0;
  string jugador1, jugador2;    /*variables para almacenar los nombres de los jugadores*/



//Declaracion de funciones DIA 2
void Evento1Dia2();
void Dia2();
void FrutaMisteriosa();
void RecolectarMateriales();
void ConstruirRefugio();

//DIA 2 J2
void J2Capitulo2();

//DIA 3 J2
void J2Cap3();

bool tieneLinterna = false;
bool tieneMadera = false;
bool tieneHojas = false;
bool tieneCuerda = false;

//Declaracion de funciones DIA 3
void explorarRecursos();
void BuscarComida();
void Pantano();
void Cueva();
void Esqueleto();
void Capitulo3();
void CaminoOso();

void Dia4j1();
void Dia4j2();
void playa();
void bosque();
void volvercamp();
void boom();
void inventario1();
void inventario2();
void buscarAldea();
void misionSecundaria();
bool tieneCuchillo=false;
bool AyudarZorro=false;
char decision;
int Arena;
bool Radio=false;

void dia5j1();
void dia5j2();

int numrand(int); // Declaracion de funcion de numero aleatorio
int numrand(int limitealatorio)
{ // Funcion para numero aleatorio
  int dato = 0;
  srand(time(NULL));
  dato = 1 + rand() % (limitealatorio);
  return dato;
}
  int limitealeatorio = 0;
  int numale = 0;                                                   // Numero aleatorio
  int resp;                                                         /*Variable para volver al menu principal*/
  bool j1vida = true, j2vida = true; 
  int limitedias = 5, contadordia = 1, contadorswitch=1; // La vida de los jugadores, limite de dias y contador de dias
  bool turno = true;                                                // Son los turnos de cada jugador
  int desicion = 0, desicionp = 0;                                               // Para tomar deciciones dentro del juego

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
       
        usleep(1000); 
    }
    cout << endl;
  
  
  cout << "Pulsa cualquier letra para comenzar..." << endl
       << endl;
  _getch();


  



  
  do /*Este do se conecta con el while de resp y sirve para volver al menu principal*/
  {
    int opcion;
cout << "\033[95m  <The Forgotten Island/>\033[0m" << endl << endl;
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
        if(j1vida==true||j2vida==true){
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
        }
        switch (turno)
        {
        case true:
        if(j1vida==true){
        cout << "\033[34m\n\nTurno de " << jugador1 << "\033[0m" << endl;
        }
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
                    cout << "Encontrastes un botiquin\n";
                     inventarioJugador1[objetosRecolectados1++] = "botiquin";

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
                    cout << "Encontrastes ropa calida y agua\n";
                     inventarioJugador1[objetosRecolectados1++] = "ropa calida";
                     inventarioJugador1[objetosRecolectados1++] = "agua";
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
                cout << "descepcionado comienzas a caminar dandole vueltas al cuarto donde caiste y encontraste unas botellas de agua";
                     inventarioJugador1[objetosRecolectados1++] = "agua";
                
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
          if(j1vida==true){
            Dia2();
            contadorpuntoj1 = 2;
          }
            break;
          case 3:
          if(j1vida){
            Capitulo3();
            contadorpuntoj1 ++;
          }
            break;
          case 4:
          if(j1vida==true){
            Dia4j1();
            contadorpuntoj1 ++;
          }
            break;
          case 5:
          if(j1vida==true){
            dia5j1();
            contadorpuntoj1 ++;
          }
            break;
          }
          _getch();
          numale = 0;
          break;
          // Aqui va todo el codigo del juador 1, el cout es namas para ver si funcionaba lo de los turnes jeje
        case false:
        if(j2vida==true){
       cout << "\033[35m\n\nTurno de " << jugador2 << "\033[0m" << endl;
        }
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
          if(j2vida==true){
            J2Capitulo2();
            contadorpuntosj2 =2;
          }
            break;
          case 3:
          if(j2vida==true){
            J2Cap3();
            contadorpuntosj2 ++;
          }
            break;
          case 4:
          if(j2vida==true){
            Dia4j2();
            contadorpuntosj2 ++;
          }
            break;
          case 5:
          if(j2vida==true){
            dia5j2();
            contadorpuntosj2 ++; 
          }
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

      } while (limitedias != 0);
      /*Agregar codigo aca papuh*/
      if(contadorpuntoj1>contadorpuntosj2){
        cout<<jugador1<<" Ganastes\n";
      }else if(contadorpuntosj2>contadorpuntoj1){
       cout<<jugador2<<" Ganastes\n";
      }else{
        cout<<jugador1<<" y "<<jugador2<<" han empatado\n";

      }
    cout<<"Puntos de "<<jugador1<<" "<<contadorpuntoj1<<"\n";
    cout<<"Puntos de "<<jugador2<<" "<<contadorpuntosj2<<"\n";
      do
      {
        cout << "Presiona 1 para volver al menu principal:";
        cin >> resp;
        cout << endl;
      } while (resp != 1);
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



//======================================================================CAP 2=========================================================================================================

void Evento1Dia2(){
int DecisionEvento1Dia2;
int Linterna;

    cout<<"Ves a lo lejos el mar y decides ir.\n";
    cout<<"Ves que hay una variedad de especies de flora y fauna que nunca antes habias visto y ya que estas hambriento piensas que puede ser buena idea agarrar de una fruta misteriosa al lado tuyo.\n";
    cout<<"1. Comer de la fruta misteriosa\n";
    cout<<"2. Puede ser peligroso! Mejor no arriesgarme.\n";
    cin>>DecisionEvento1Dia2;

      switch (DecisionEvento1Dia2)
        {
        case 1:
        FrutaMisteriosa();
           break;
        case 2:
        cout<<"Decides no arriesgarte a comer esa fruta que parecia un poco rara, asi que decides seguir caminando viendo que podrias encontrar\n";
        cout<<"Encuentras un objeto que te podria ser de ayuda mas adelante, es una linterna, no sabes de donde aparecio pero aparece en el momento mas oportuno\n";

           while (true) {
        cout << "Encuentras una linterna en el suelo. Quieres agarrar la linterna?\n";
        cout << "1. Si\n";
        cout << "2. No\n";
        cin >> Linterna;

        if (Linterna == 1) {
            tieneLinterna = true;
            cout << "Has agarrado la linterna.\n";
            inventarioJugador1[objetosRecolectados1++] = "linterna";
            cout << "Esta te sera util mas adelante, decides volver al refugio usandola y teniendo una mejor vision\n";
            cout << "Con ayuda de la linterna te guias hasta el refugio y descansas\n";


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
        } else if (Linterna == 2) {
            tieneLinterna = false;
            cout << "Decides no agarrar la linterna.\n";
            cout << "Se te hace dificil volver a tu refugio, luego de caminar a la detiva un poco encontraste un botiquin.\n";
            inventarioJugador1[objetosRecolectados1++] = "botiquin";
            cout << "Luego de un rato encontraste el camino correcto hacia tu refugio.\n";
            cout << "Llegas demasiado cansado y te quedas dormido.\n";

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
        } else {
            cout << "Opcion no valida, intenta nuevamente.\n";
        }
    }
        break;
        default: 
            cout<<"Opcion no valida, intenta nuevamente.";
            break;
        }
}

void FrutaMisteriosa(){
    int FrutaMisteriosa1, FrutaMisteriosa2, FrutaMisteriosa3, FrutaMisteriosa4;

      cout<<"Oh no! La fruta misteriosa resulto ser una fruta alucinogena, te sientes mareado y muy confundido, puede que lo mejor sea que te sientes y esperes a que pase el efecto\n";
        cout<<"Que quieres hacer?\n";
        cout<<"1. Intentar caminar de vuelta al refugio.\n";
        cout<<"2. Quedarte quieto y esperar a que pase el efecto.\n";
        cin>>FrutaMisteriosa1;

           switch (FrutaMisteriosa1) {
        case 1:
            cout<<"Intentas caminar de vuelta al refugio, pero todo parece moverse a tu alrededor.\n";
            cout<<"1. Seguir avanzando.\n";
            cout<<"2. Sentarte y descansar un poco.\n";
            cin>>FrutaMisteriosa2;
            switch (FrutaMisteriosa2) {
                case 1:
                    cout<<"Sigues avanzando a pesar de las alucinaciones. Ves un rio delante de ti.\n";
                    cout<<"1. Cruzar el rio.\n";
                    cout<<"2. Buscar un lugar seguro cerca del rio.\n";
                    cin>>FrutaMisteriosa3;
                    switch (FrutaMisteriosa3) {
                        case 1:
                            cout<<"Intentas cruzar el rio, pero la corriente es demasiado fuerte. Te arrastra y pierdes el conocimiento.\n";
                            cout<<"Despiertas al otro lado del rio, aun alucinando.\n";
                            cout<<"1. Buscar un camino de vuelta al refugio.\n";
                            cout<<"2. Explorar la nueva area.\n";
                            cin>>FrutaMisteriosa4;
                            switch (FrutaMisteriosa4) {
                                case 1:
                                    cout<<"Encuentras el camino de vuelta al refugio despues de muchas dificultades. Finalmente, te quedas dormido y las alucinaciones comienzan a desvanecerse.\n";
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
                                    cout<<"Exploras la nueva area y encuentras algunas hierbas que parecen aliviar las alucinaciones. Despues de un tiempo, te sientes mejor y decides volver al refugio.\n";
                                    cout << "De camino al refugio encontraste un botiquin atorado en una rama de un arbusto, lo decides tomar y guardar" << endl;
                                    inventarioJugador1[objetosRecolectados1++] = "linterna";
                                    cout<<"Consigues volver al refugio y te quedas dormido.\n";
                                  
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
                                default:
                                    cout<<"Opcion no valida, intenta nuevamente.\n";
                                    break;
                            }
                            break;
                        case 2:
                            cout<<"Encuentras un lugar seguro cerca del rio y decides descansar. Despues de un rato, las alucinaciones empiezan a desvanecerse.\n";
                            cout<<"Te diriges de vuelta al refugio y pasas el resto de la noche alli.\n";
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
                        default:
                            cout<<"Opcion no valida, intenta nuevamente.\n";
                            break;
                    }
                    break;
                case 2:
                    cout<<"Te sientas y descansas un poco. Las alucinaciones comienzan a ser menos intensas.\n";
                    cout<<"Finalmente, te sientes lo suficientemente bien como para volver al refugio.\n";
                    cout<<"No tardas mucho en encontrar tu tu refugio, al llegar te arrecuestas en una roca y te quedas dormido\n";
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
                default:
                    cout<<"Opcion no valida, intenta nuevamente.\n";
                    break;
            }
            break;
        case 2:
            cout<<"Te quedas quieto y esperas a que pase el efecto de la fruta. Despues de un tiempo, las alucinaciones empiezan a desvanecerse.\n";
            cout<<"Finalmente, puedes volver al refugio sin problemas.\n";
            cout<<"De vuelta en el refugio te quedas dormido y te tapas con unas hojas.\n";
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
        default:
            cout<<"Opcion no valida, intenta nuevamente.\n";
            break;
    }


}

void RecolectarMateriales() {
    while (!tieneMadera || !tieneHojas || !tieneCuerda) {
        cout << "Debes recolectar los siguientes materiales:\n";
        if (!tieneMadera) cout << "1. Madera\n";
        if (!tieneHojas) cout << "2. Hojas\n";
        if (!tieneCuerda) cout << "3. Cuerda\n";
        
        int decisionRecolectar;
        cout << "Selecciona el material que quieres recolectar (1-3):\n";
        cin >> decisionRecolectar;

        switch (decisionRecolectar) {
            case 1:
                if (!tieneMadera) {
                    tieneMadera = true;
                    cout << "Has recolectado madera.\n";
                } else {
                    cout << "Ya tienes suficiente madera.\n";
                }
                break;
            case 2:
                if (!tieneHojas) {
                    tieneHojas = true;
                    cout << "Has recolectado hojas.\n";
                } else {
                    cout << "Ya tienes suficientes hojas.\n";
                }
                break;
            case 3:
                if (!tieneCuerda) {
                    tieneCuerda = true;
                    cout << "Has recolectado cuerda.\n";
                } else {
                    cout << "Ya tienes suficiente cuerda.\n";
                }
                break;
            default:
                cout << "Opcion no valida, intentalo de nuevo.\n";
                break;
        }
    }
}

// Función para construir el refugio
void ConstruirRefugio() {
    RecolectarMateriales(); // Verifica si tiene todos los materiales
    
    if (tieneMadera && tieneHojas && tieneCuerda) {
        cout << "Has construido un refugio exitosamente. Ahora podras pasar la noche a salvo.\n";
    } else {
        cout << "No tienes todos los materiales necesarios para construir el refugio.\n";
    }
}

void Dia2(){

    cout<<"Despiertas al dia siguiente y decides salir del lugar, en busca de poder sobrevivir\n";
            cout<<"Decides ir al bosque en busca de materiales ya que no tienes un lugar seguro como para poder pasar el resto de noche.\n";
           ConstruirRefugio();
           Evento1Dia2();
         
}

//========================================================================CAP 3======================================================================================================
void Capitulo3(){
  
    int decisionCap3;
    cout << "Has despertado, sin embargo resultas muy hambriento y de escasos recursos para sobrevivir, necesitas buscar algo urgente para comer o de lo contrario moriras de hambre.\n";
    cout<<"Decides ir a dar un paseo";
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

   void Esqueleto(){
                cout << "Has encontrado un esqueleto, parece tener una nota.\n";
                cout << "Nota: Estoy atrapado en este lugar inhospito y frio, sin ropa, sin comida, sin agua, solamente yo y mi capacidad de poder escribir a pesar de haber sobrevivido\n"; // Esta es la nota que contenia un esqueleto en un bote de la cueva
                cout << "todos estos dias en este infierno, quien habria dicho que aquellos habitantes de esta isla tan alejada de todo serian unos completos enfermos.\n";
                cout << "Tenia la esperanza de encontrar el tesoro que tanto se rumoreaba que habia aqui, pero parece que todo fue un fraude, incluso juraria que fue plan de estos habitantes\n";
                cout << "Por si alguien logra ver esta nota, mis fuerzas para poder moverme se han acabado, pero si alguien esta en mi misma situacion y con un poco de fuerzas, he dejado las llaves de mi lancha\n";
                cout << "En aquel lugar donde solia pasar mis tardes junto a estos seres, donde por un momento en mi inocencia crei que los humanos no eran tan crueles como lo imaginaba\n";
                cout << "Fin de la nota.\n";
                Radio=true;
                cout << "Has encontrado: Radio\n";
                cout << "Has quedado en shock y comienzas a asustarte con tu alrededor, tienes muchas preguntas, decides pasar la noche ahi ya que ha oscurecido y sera muy peligroso salir.";
    }
    void CaminoOso(){
                cout << "Regresas de camino a tu nuevo refugio para llevar las proviciones que has recolectado\n";
                cout << "Ves a lo lejos un animal grande y cafe que se esta moviendo con tranquilidad, se trata de un oso.\n";
                cout << "Das un mal paso y el oso logra escucharte, este se acerca agresivamente hacia ti.\n";
                if (AyudarZorro==true)
                {
                    cout<<"Oh sorpresa! Es el zorro que ayudaste anteriormente a escapar, ahora el te ayuda a ti distrayendo al oso para que tu puedas hacerlo, logras escapar, sin embargo entras a una cueva donde el oso no cabe para poder refugiarte.\n";
                    Esqueleto();
                }
                else{
                    cout<<"Logras escapar, pero has dejado tu comida para que el oso se distraiga, logras adentrarte a una cueva donde el oso no cabe para poder refugiarte, ves que la cueva mas grande de lo que aparenta.\n";
                    Esqueleto();
                }

    }

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
    int opcionSubirArbol; 
    int opcionRaices; 
    int opcionExplorar;

    cout << "Decides explorar el pantano en busca de comida.\n";
    cout << "Encuentras varias opciones para buscar:\n";
    cout << "1. Buscar frutas en los arboles\n";
    cout << "2. Buscar raices comestibles\n";
    cout << "3. Buscar huevos de aves en los arboles\n";
    cout << "Elige una opcion: ";
    cin >> opcionComida;

    switch (opcionComida) {
        case 1:
            cout << "Intentas subir a un arbol para buscar frutas.\n";
            cout << "1. Subir lentamente y con cuidado\n";
            cout << "2. Subir rapidamente\n";
            cout << "3. Buscar otro arbol que parezca mas seguro\n";
            cin >> opcionSubirArbol;

            switch (opcionSubirArbol) {
                case 1:
                    cout << "Subes lentamente y encuentras algunas frutas, pero te lleva mucho tiempo.\n";
                    CaminoOso();
                    break;
                case 2:
                    cout << "Subes rapidamente, pero resbalas y te lastimas.\n";
                    CaminoOso();
                    break;
                case 3:
                    cout << "Encuentras otro arbol que parece mas seguro y subes sin problemas. Recoges algunas frutas.\n";
                    CaminoOso();
                    break;
                default:
                    cout << "No encuentras nada util y decides regresar a tu refugio.\n";
                    CaminoOso();
                    break;
            }
            break;

        case 2:
            cout << "Encuentras raices comestibles y las recolectas con cuidado.\n";
            cout << "1. Examinar las raices detenidamente antes de recolectarlas\n";
            cout << "2. Recolectarlas rapidamente\n";
            cout << "3. Buscar mas raices en el area\n";
            cin >> opcionRaices;

            switch (opcionRaices) {
                case 1:
                    cout << "Examinar las raices detenidamente te permite recolectar las mejores.\n";
                    CaminoOso();
                    break;
                case 2:
                    cout << "Recolectas las raices rapidamente, pero algunas no son comestibles.\n";
                    CaminoOso();
                    break;
                case 3:
                    cout << "Buscas mas raices y encuentras una buena cantidad.\n";
                    CaminoOso();
                    break;
                default:
                    cout << "No encuentras nada util y decides regresar a tu refugio.\n";
                    CaminoOso();
                    break;
            }
            break;

        case 3:
            cout << "Exploras el area en busca de cualquier otra cosa comestible.\n";
            cout << "1. Buscar cerca de una corriente de agua\n";
            cout << "2. Explorar una cueva cercana\n";
            cout << "3. Buscar en el suelo del bosque\n";
            cin >> opcionExplorar;

            switch (opcionExplorar) {
                case 1:
                    cout << "Cerca de la corriente de agua encuentras algunas hierbas comestibles.\n";
                    cout << "Decides regresar a tu refugio con las hierbas.\n";
                    CaminoOso();
                    break;
                case 2:
                    cout << "Exploras la cueva y encuentras algunos hongos comestibles.\n";
                    cout << "Decides regresar a tu refugio con los hongos.\n";
                    CaminoOso();
                    break;
                case 3:
                    cout << "Buscas en el suelo del bosque y encuentras algunas bayas.\n";
                    cout << "Decides regresar a tu refugio con las bayas.\n";
                    CaminoOso();
                    break;
                default:
                    cout << "No encuentras nada util y decides regresar a tu refugio.\n";
                    CaminoOso();
                    break;
            }
            break;

        default:
            cout << "No encuentras nada util y decides regresar a tu refugio.\n";
            CaminoOso();
            break;
    }
}


//Aqui iran las opciones de "Explorar recursos"

    void Pantano(){

            cout << "Sigues tu camino y ves que hay arena movediza, tiras un objeto hacia ella y ves que todo lo que arrojas es rapidamente absorbida por la arena\n";
            cout << "Quieres cruzar por la arena movediza o prefieres desviarte y seguir buscando materiales en otro lugar? Cruzarla se ve mortal.\n";
            cout << "1. Cruzarla\n";
            cout << "2. Seguir por otro camino\n";
            cin >> Arena;

            switch (Arena)
            {
            case 1:
            cout<<"Has decidido cruzar, has muerto";
            boom();
            j1vida=false;
                break;
            case 2: 
            cout<<"Sigues el camino y encuentras un material filoso con el que decides armar un cuchillo, el cual te servira para defenderte y poder cortar cosas.\n";
            tieneCuchillo=true;
            CaminoOso();
            break;
            default:
            cout<<"Opcion no valida, intenta de nuevo.";
                break;
            }
    }
    void Cueva() {
    int decisionAdicional;

    cout << "Te adentras en la cueva y avanzas con cautela.\n";
    cout << "Mientras avanzas, encuentras un camino bifurcado.\n";
    cout << "1. Tomar el camino de la izquierda\n";
    cout << "2. Tomar el camino de la derecha\n";
    cin >> decisionAdicional;

    switch (decisionAdicional) {
        case 1:
            cout << "Decides tomar el camino de la izquierda.\n";
            cout << "Encuentras una pequena fuente de agua subterranea. Bebes un poco y te sientes revitalizado.\n";
            cout << "Decides regresar al cruce y tomar el camino de la derecha.\n";
            Esqueleto();
            break;
        case 2:
            Esqueleto();
            break;
        default:
            cout << "Opcion no valida. Decides seguir avanzando por instinto.\n";
            Esqueleto();
            break;
    }
}

 

/*================================Dia 4=======================================*/
    void Dia4j1(){
      cout << "Te levantas aun un poco desconcertado por la nota que encontraste" << endl;
      cout << "Recuerdas la nota y lo que decia y decides buscar las llaves de la lancha para poder salir de la isla" << endl;
      cout << "Sales de tu refugio para comenzar a buscar el lugar del que hablaba la nota" << endl;
      cout << "Elige a que lugar iras a buscar" << endl;
      cout << "1. Al bosque" << endl;
      cout << "2. A la playa" << endl;
      int a;
      do
      {
      cout << "Elige una opcion: ";
      cin >> a;
       } while (a < 1 || a > 2);

       switch (a)
       {
        /*vas al bosque*/
       case 1:
        bosque();
        break;
        case 2:
        /*vas a la playa*/
        playa();
       
       default:
        break;
       }
    
    }


void bosque() {
    int b;
    cout << "Decides ir al bosque, luego de caminar por 10 minutos te encuentras 2 caminos" << endl;
    cout << "El primer camino parece ser un sendero que se dirige a la parte mas alta del bosque" << endl;
    cout << "El segundo camino es plano y parece que dirige al otro lado de la isla" << endl;
    
    do {
        cout << "1. El primero" << endl;
        cout << "2. El segundo" << endl;
        cout << "Elige una opcion: ";
        cin >> b;  
    } while (b < 1 || b > 2); 

    switch (b) {
        case 1: {
            cout << "Elegiste el sendero que te lleva a la parte mas alta del bosque" << endl;
            cout << "Despues de una caminata de una hora estas exhausto" << endl;
            cout << "Decides revisar el inventario para ver si hay algo util" << endl << endl;

            char invt;
            do {
                cout << "Presiona 'y' para ver el inventario: ";
                cin >> invt;
            } while (invt != 'y');

            if (objetosRecolectados1 == 0) {
                cout << "El inventario esta vacio." << endl;
            } else {
                cout << "Inventario de " << jugador1 << ": ";
                for (int i = 0; i < objetosRecolectados1; i++) {
                    cout << inventarioJugador1[i] << (i < objetosRecolectados1 - 1 ? ", " : "");
                }
                cout << endl;
            }

            // Verificar si hay agua en el inventario
            bool tieneAgua = false;
            for (int i = 0; i < objetosRecolectados1; i++) {
                if (inventarioJugador1[i] == "agua") {
                    tieneAgua = true;
                    for (int j = i; j < objetosRecolectados1 - 1; j++) {
                        inventarioJugador1[j] = inventarioJugador1[j + 1];
                    }
                    objetosRecolectados1--;
                    break;
                }
            }

            if (tieneAgua) {
                cout << "Tienes agua en el inventario. Decides tomarla y sigues caminando." << endl;
                cout << "Continuas caminando y a lo largo ves como se va terminando el camino y te acercas mas a la parte mas alta de la isla" << endl;
                cout << "Luego de mas de una hora de caminar llegas a la parte mas alta de la isla pensando que ahi es donde el que escribio la not veia los atardeceres" << endl;
                cout << "Pero te percatas que no hay ninguna pista o indicio de donde puedan estar las llaves de la lancha" << endl;
                cout << "Parece que perdiste tiempo y esfuerzo al llegar hasta aca" << endl;

                int rp;
                do {
                    cout << "Quieres regresar?" << endl;
                    cout << "1. si" << endl;
                    cout << "2. no, presiento que hay algo mas aqui" << endl;
                    cin >> rp;     
                } while (rp != 1 && rp != 2);

                if (rp == 1) {
                    cout << "Decides volver, una tormenta se acerca" << endl;
                    cout << "Comienza a llover y decides correr" << endl;
                    cout << "Por correr te resbalas en el lodo y te doblas el tobillo" << endl;
                    j1esguince = true;
                    cout << endl << endl;
                    cout << "De camino ves a lo lejos humo provenir de un lado" << endl;
                    cout << "Quieres explorar?" << endl;
                    
                    int t;
                    do {
                        cout << "1. Seguir el humo" << endl;
                        cout << "2. Regresar al refugio" << endl;
                        cout << "Digita tu opcion: ";
                        cin >> t;
                    } while (t != 1 && t != 2);

                    switch (t) {
                        case 1:
                            cout << "Decides seguir el humo pero el esguince dificulta caminar rapido" << endl;
                            cout << "Luego de 15 minutos de caminar cojeando llegas al origen del humo" << endl;
                            cout << "Parece ser un campamento habitado por varias personas" << endl;
                            cout << "Quieres caminar hacia su campamento?" << endl;
                            
                           int y;
    do {
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cout << "Selecciona tu opcion: ";
        cin >> y;
    } while (y != 1 && y != 2);

    if (y == 1) {
        cout << "Decides caminar como puedes hacia su campamento, pero escuchas pasos acercarse rapidamente" << endl;
        cout << "Que decides hacer?" << endl;
        
        int q;
        do {
            cout << "1. Esconderme" << endl;
            cout << "2. Tratar de huir" << endl;
            cout << "Digita tu opcion: ";
            cin >> q;
        } while (q != 1 && q != 2);

        if (q == 1) {
            int limitealeatorio = 2;
            int numale = numrand(limitealeatorio);
            switch (numale) {
                case 1: 
                    cout << "Parece ser que te escondiste bien, lograste librarla\n";
                     volvercamp();
                    break;
                case 2:
                    cout << "Intentaste esconderte lo más rápido que pudiste pero tu esguince no te permitió llegar rápido y algo te vio\n";
                    cout << "Lo que te vio no parece ser humano, intentas correr pero fue en vano, te alcanzó\n";
                     boom();
                     j1vida=false;
                    break;
            }
        } else if (q == 2) {
            cout << "Intentas huir pero el esguince no te deja avanzar, por lo que al intentar correr haces mucho ruido " << endl;
            cout << "por lo que alertas a los seres que habitan ahí, no parecen ser humanos, ves que uno se pone en 4 patas y corre hacia ti" << endl;
             boom();
             j1vida=false;

        }
        
    } else if (y == 2) {
       cout << "Decides irte porque no soportas apoyar el pie y como puedes intentas bajar la colina " << endl;
        volvercamp(); 
    }
                    
                            
                    }
                } else if (rp == 2) {
                  int u;
    cout << "Decides quedarte a investigar " << endl;
    cout << "Ves a tu alrededor y ves una roca que parece que fue movida de su lugar original, al intentarla levantar notas que es una roca falsa " << endl;
    cout << "La levantas sin problema y ves una nota pegada a la parte de abajo de la roca, la tinta esta un poco corroida pero aun asi se logra leer con un poco de dificultad " << endl;
    cout << endl << endl;
    cout << "Nota: " << endl;
    cout << "En esta roca es donde me sentaba a ver los atardeceres cuando me alejaba de los otros seres, era mi lugar feliz" << endl;
    cout << "Enterre una caja fuerte a no mas de 20 metros al norte de aca " << endl;
    cout << "El codigo es: 4636752" << endl<<endl;
    cout << "Presiona 1 para caminar: ";
    cin >> u;

    if (u == 1) {
        cout << string(100, '\n');
        cout << "Caminas 20 metros al norte y comienzas a escarbar" << endl;
        cout << "La encuentras y te solicita el codigo" << endl << endl;
    }

    int intentos = 0;
    bool codigoCorrecto = false;

    while (intentos < 3 && !codigoCorrecto) {
        int code;
        cout << "Digita el codigo: ";
        cin >> code;

        if (code == 4636752) {
            cout << "Codigo correcto! La caja fuerte se abre y encuentras una antena de radio." << endl;
            inventarioJugador1[objetosRecolectados1++] = "antena de radio";
             volvercamp();
            
            codigoCorrecto = true;
        } else {
            intentos++;
            if (intentos < 3) {
                cout << "Codigo incorrecto. Intenta de nuevo." << endl;
            }
        }
    }

    if (!codigoCorrecto) {
      int ago;
    cout << "Has agotado tus intentos." << endl;
    cout << "La caja fuerte comienza a pitar mientras una luz roja parpadea cada vez más rápido." << endl;

    do {
        cout << "Que decides hacer?" << endl;
        cout << "1. La caja fuerte tiene tiempo, seguro sus circuitos se quemaron, no creo que explote" << endl;
        cout << "2. Correr" << endl;
        cout << "Digita tu opcion: ";
        cin >> ago;
    } while (ago != 1 && ago != 2);

 switch (ago) {
        case 1:
            cout << "Decides esperar mientras la caja deja de pitar y parpadear, la luz cada vez parpadea más rápido y el ruido es insoportable" << endl;
            cout << "BOMMMM!!!" << endl;
            boom();
            j1vida=false; 
            break;
        case 2:
            cout << "Decides correr, alejandote lo mas rapido posible de la caja fuerte." << endl;
            cout << "A lo lejos escuchas una explosion" << endl;
            volvercamp(); 
            break;
        default:
            cout << "Opcion invalida." << endl;
            break;
    }
    }
                }
            } else {
                cout << "No tienes agua en el inventario. Sigues caminando, pero ya muy cansado." << endl;
                cout << "El camino aun es largo pero sigues caminando" << endl;
                cout << "Tu cuerpo ya no pudo mas y te desmayaste, te desplomaste y te lastimaste" << endl;
                j1cortada = true;
                cout << "Parece que te abriste la cabeza" << endl;
                cout << "Busca en el inventario si hay algo util" << endl << endl;

                char invt;
                do {
                    cout << "Presiona 'y' para ver el inventario: ";
                    cin >> invt;
                } while (invt != 'y');

                if (objetosRecolectados1 == 0) {
                    cout << "El inventario esta vacio." << endl << endl;
                } else {
                    cout << "Inventario de " << jugador1 << ": ";
                    for (int i = 0; i < objetosRecolectados1; i++) {
                        cout << inventarioJugador1[i] << (i < objetosRecolectados1 - 1 ? ", " : "");
                    }
                    cout << endl;
                }

                
                bool tieneBotiquin = false;
                for (int i = 0; i < objetosRecolectados1; i++) {
                    if (inventarioJugador1[i] == "botiquin") {
                        tieneBotiquin = true;
                        for (int j = i; j < objetosRecolectados1 - 1; j++) {
                            inventarioJugador1[j] = inventarioJugador1[j + 1];
                        }
                        objetosRecolectados1--;
                        break;
                    }
                }

                if (tieneBotiquin) {
                    cout << "Tienes un botiquin en el inventario. Decides usarlo " << endl;
                    cout << "Estas herido por lo que abortas mision e intentas volver al refugio" << endl;
                    volvercamp();
                } else {
                    cout << "No tienes un botiquin en el inventario." << endl;
                    cout << "Por lo que no puedes curarte, la herida fue grave y mueres por hemorragia" << endl;
                    
                    string mensaje = "\033[31mFalleciste\033[0m\n";
                    int retardo = 100; 
                    for (char c : mensaje) {
                        cout << c << flush;
                   
                    }
                }
            }
            break;
        }

        case 2: {
           int n;
    cout << "Elegiste el camino plano que parece dirigir al otro lado de la isla." << endl;
    cout << "Caminas sin mucho esfuerzo ya que es un camino plano" << endl;
    cout << "Al parecer el camino te lleva al otro lado de la playa" << endl;
    cout << "Ves que en la orilla hay peces por lo que decides entrar y pescar" << endl;

    do {
        cout << "Presiona 1 para pescar con las manos" << endl;
        cout << "Digita tu opcion: ";
        cin >> n;
    } while (n != 1);

    if (n == 1) {
        cout << "Parece que agarraste un pez" << endl;

    }

    cout << "¿Quieres seguir pescando?" << endl;
    int p;
    do {
        cout << "1. si" << endl;
        cout << "2. no" << endl;
        cout << "Digita tu opcion: ";
        cin >> p;
    } while (p != 1 && p != 2);

    if (p == 1) {
        cout << "Sales de la orilla y dejas al pez que agarraste encima de una piedra" << endl;
        cout << "Vuelves a la orilla para intentar pescar de nuevo" << endl;

        int f;
        do {
            cout << "Presiona 1 para pescar" << endl;
            cout << "Digita tu opcion: ";
            cin >> f;
        } while (f != 1);

        if (f == 1) {
            cout << "Parece que algo del fondo viene rqpido hacia ti" << endl;
            cout << "ES UN TIBURON!" << endl;
            boom(); 
            j1vida=false;
        }    
            }  
            else
            {
           volvercamp();
            }
            break;
        }

        default:
            cout << "Opcion no valida." << endl;
         break;
    }
}




void playa() {
    cout << "Te diriges a la playa que no está tan lejos del refugio." << endl;
    cout << "Caminas no mucho hasta que escuchas cada vez más cerca el retumbar de las olas." << endl;
    cout << "Llegas hasta la playa y comienzas a preguntarte hacia qué lado ir." << endl;
    cout << "Observas a la derecha y ves un punto blanco a lo lejos." << endl;

    int i;
    do {
        cout << "1. Ir a la izquierda" << endl;
        cout << "2. Ir a la derecha" << endl;
        cin >> i;
    } while (i != 1 && i != 2);

    if (i == 1) {
        cout << "Te vas hacia la izquierda y notas que hay un contenedor de carga saliendo de la arena." << endl;
        cout << "¿Quieres ir y escarbar?" << endl;

        int r;
        do {
            cout << "1. Sí" << endl;
            cout << "2. No creo que haya algo importante ahi" << endl;
            cout << "Digita tu opción: ";
            cin >> r;
        } while (r != 1 && r != 2);

        if (r == 1) {
            cout << "Entre mas te acercas al contenedor, notas que hay una parte rayada del contenedor." << endl;
            cout << "Entre mas te acercas, notas que aquello rayado no solo son líneas, hay un mensaje ahi." << endl;
            cout << "Nota:" << endl << endl;
            cout << "Me encuentro en el lugar donde vengo a despejar mi mente cuando no estoy rodeado de los otros seres." << endl;
            cout << "Aqui es donde paso la mayoría de mis tardes viendo la puesta de sol, encontre una lancha no muy lejos de aca." << endl;
            cout << "Si alguien está leyendo esta nota, quiero que sepa que enterre la llave aqui." << endl;
            cout << "En la arena, donde las olas besan la costa, yace un mensaje para ti. Busca un lugar donde el sol se" << endl;
            cout << "oculta y los menores juegan sin cesar. Alli, entre los granos dorados y la sombra de una vieja palmera" << endl;
            cout << "encontraras una concha. Abre la concha, y hallaras las llaves que buscas." << endl;
            cout << "Fin de la nota." << endl << endl;

            string o;
            cout << "Donde buscarás? (Escribe 'palmera' para buscar en la palmera): ";
            cin >> o;

            if (o == "palmera") {
                cout << "Comienzas a buscar una palmera y notas que hay una sola palmera un poco seca a no más de 20 metros." << endl;
                cout << "Te diriges hacia la palmera, escarbas un poco en la arena y encuentras una concha. La abres y hallas las llaves que buscas." << endl;
                inventarioJugador1[objetosRecolectados1++] = "llaves de lancha";
            } else {
                cout << "Buscas en otro lugar, pero no encuentras nada. Tal vez deberías intentar en otro lugar." << endl;
                int l;
                do {
                    cout << "Que quieres hacer?" << endl;
                    cout << "1. Volver al refugio" << endl;
                    cout << "2. Seguir buscando" << endl;
                    cin >> l;
                } while (l != 1 && l != 2);

                if (l == 1) {
                    volvercamp();
                } else {
                    cout << "Te aferras a seguir buscando y te resignas para buscar en el contenedor." << endl;
                    cout << "Entre mas te acercas al contenedor, notas que hay una parte rayada del contenedor." << endl;
                    cout << "Entre mas te acercas, notas que aquello rayado no solo son lineas, hay un mensaje ahí." << endl;
                    cout << "Nota:" << endl << endl;
                    cout << "Me encuentro en el lugar donde vengo a despejar mi mente cuando no estoy rodeado de los otros seres." << endl;
                    cout << "Aquí es donde paso la mayoría de mis tardes viendo la puesta de sol, encontre una lancha no muy lejos de acá." << endl;
                    cout << "Si alguien está leyendo esta nota, quiero que sepa que enterre la llave aqui." << endl;
                    cout << "En la arena, donde las olas besan la costa, yace un mensaje para ti. Busca un lugar donde el sol se" << endl;
                    cout << "oculta y los menores juegan sin cesar. Alli, entre los granos dorados y la sombra de una vieja palmera" << endl;
                    cout << "encontrarás una concha. Abre la concha, y hallarás las llaves que buscas." << endl;
                    cout << "Fin de la nota." << endl << endl;

                    cout << "Donde buscaras? (Escribe 'palmera' para buscar en la palmera): ";
                    cin >> o;

                    if (o == "palmera") {
                        cout << "Comienzas a buscar una palmera y notas que hay una sola palmera un poco seca a no más de 20 metros." << endl;
                        cout << "Te diriges hacia la palmera, escarbas un poco en la arena y encuentras una concha. La abres y hallas las llaves que buscas." << endl;
                        inventarioJugador1[objetosRecolectados1++] = "llaves de lancha";
                    }
                }
            }
        }
    } else if (i == 2) {
        cout << "Te vas hacia la derecha y sientes que algo te observa." << endl;
        cout << "Que haces?" << endl;

        int e;
        do {
            cout << "1. Buscar donde esconderse" << endl;
            cout << "2. No hacer caso y seguir caminando" << endl;
            cout << "Digita tu opcion: ";
            cin >> e;
        } while (e != 1 && e != 2);

        if (e == 1) {
         limitealeatorio = 2;
         numale = numrand(limitealeatorio);
         switch(numale){
          case 1:
          cout<<"Te salvas\n";
          volvercamp();
          break;
          case 2:
          cout<<"Algo te escucho y acabo contigo\n";
          boom();
          j1vida=false;
          break;
         }
        } else {
            cout << "Decides no hacer caso y aquella mirada que sentiste que te seguia se te presenta enfrente." << endl;
            cout << "Aquello que tienes enfrente parece estar muy hambriento, no tienes mucho que hacer." << endl;
            int x;
            do {
                cout << "Que decides hacer?" << endl;
                cout << "1. Correr" << endl;
                cout << "2. Enfrentar tu destino" << endl;
                cin >> x;
            } while (x != 1 && x != 2);

            if (x == 1) {
                cout << "Decides correr, tratando de escapar de la amenaza." << endl;
                cout << "Pero te alcanza." << endl;
                boom();
                j1vida=false;
            } else if (x == 2) {
                cout << "Decides enfrentar tu destino con valentía." << endl;
                boom();
                j1vida=false;
            }
        }
    }
}



void volvercamp(){
cout << "Como puedes intentas encontrar tu refugio" << endl;
cout << "Luego de caminar un rato encuentras el camino y llegas al refugio a descansar" << endl << endl;
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

}

void boom(){
    string mensaje = "\033[31mFalleciste\033[0m\n";

    for (char c : mensaje) {
        cout << c << flush;
      
 
    }
}

//==================================================================DIA 2 J2==========================================================================================================

void RelajarseYConvivir() {
    int J2Cap2decision1;
    cout << "Decides relajarte y convivir con los aldeanos. Ganas su confianza y aprendes mas sobre sus costumbres.\n";
    cout << "Te ofrecen un lugar acogedor para poder pasar la noche.\n";
    cout << "Que quieres hacer?\n";
    cout << "1. Aceptar la oferta y descansar\n";
    cout << "2. Preguntar mas sobre sus costumbres\n";
    cout << "3. Ofrecerte a ayudar en sus tareas\n";
    cin >> J2Cap2decision1;
  

    if (J2Cap2decision1 == 1) {
        cout << "Aceptas la oferta y descansas en un lugar seguro. Te sientes mucho mejor al dia siguiente.\n";
    } else if (J2Cap2decision1 == 2) {
        cout << "Decides preguntar mas sobre sus costumbres. Los aldeanos te cuentan sobre sus rituales y tradiciones.\n";
        cout << "Aprendes mucho sobre su forma de vida y te sientes mas conectado con ellos.\n";
    } else if (J2Cap2decision1 == 3) {
        cout << "Te ofreces a ayudar en sus tareas. Los aldeanos aprecian tu ayuda.\n";
        cout << "Te sientes mas util y parte de la comunidad.\n";
    }
      cout << "Por confiar en ellos, te obsequian un mapa, el cual te ayudaria a estar al tanto de donde esta cada cosa.\n";
      inventario2();
}

void EncuentroAldeanos();

void J2Capitulo2() {
    int J2Cap2decision1;

    cout << "Luego de una larga noche, decides salir a explorar. Ves que a lo lejos parece haber una aldea que parece estar abandonada. Decides ir a ver que pasa...\n";
    cout << "El ambiente no parece ser optimo, sientes muy malas energias.\n";
    cout << "Te acercas y... Oh sorpresa! Resultan haber aldeanos en esas casas en estado deplorable.\n";
    cout << "Uno de los aldeanos te ha visto!\n";
    cout << "Que decides hacer?\n";
    cout << "1. Acercarte amigablemente\n";
    cout << "2. Huir\n";
    cin >> J2Cap2decision1;

    switch (J2Cap2decision1) {
        case 1:
            cout<<"Llegas saludando amablemente a los aldeanos, ellos te responden muy calida y acogedoramente.\n";
            EncuentroAldeanos();
            break;
        case 2:
            cout << "Intentas huir, sin embargo, los aldeanos te logran rodear\n";
            cout << "Parece que estas en grave peligro...\n";
            cout << "Oh sorpresa! Los aldeanos te reciben con una sonrisa y siendo muy amables.\n";
            EncuentroAldeanos();
            break;
        default:
            cout << "Opcion no valida. Intentalo de nuevo.\n";
            break;
    }
}

using namespace std;

void EncuentroAldeanos() {
    int J2Cap2decision2;
    cout << "Te sientes mas recuperado y tranquilo.\n";
    cout << "Que quieres hacer?\n";
    cout << "1. Preguntar quienes son\n";
    cout << "2. Relajarte y convivir\n";
    cin >> J2Cap2decision2;

    if (J2Cap2decision2 == 1) {
        cout << "Responden: 'Somos sobrevivientes de un naufragio, llevamos aqui muchas decadas tratando de salir pero nadie nos ha encontrado.'\n";
        cout << "Que respondes?\n";
        cout << "1. Preguntar: Como han sobrevivido?\n";
        cout << "2. Agradecerles la hospitalidad\n";
        int J2Cap2decision3;
        cin >> J2Cap2decision3;

        if (J2Cap2decision3 == 1) {
            cout << "Responden: 'Hemos sobrevivido gracias a nuestra union y cooperacion, mientras unos se encargaban de la comida y suministros, otros se encargaban de hacer este ambiente un lugar habitable para los demas.\n";
            cout << "Tenemos areas y servicios de salud medica para estar sanos.\n";
            cout << "Tu pareces estar en mal estado, ven y te ayudaremos a recuperarte.'\n";
            cout << "Que decides hacer?\n";
            cout << "1. Aceptar la ayuda\n";
            cout << "2. Declinar la ayuda\n";
            int J2Cap2decision4;
            cin >> J2Cap2decision4;

            if (J2Cap2decision4 == 1) {
                cout << "Recibes ayuda y atencion medica, te sientes mucho mejor, recibes fisioterapia y tus huesos se sienten mejor.\n";
                cout << "Que quieres hacer ahora?\n";
                cout << "1. Explorar la aldea\n";
                cout << "2. Descansar y recuperarte\n";
                int J2Cap2decision5;
                cin >> J2Cap2decision5;

                if (J2Cap2decision5 == 1) {
                    cout << "Exploras la aldea y descubres areas de cultivo, talleres y una cueva oculta con simbolos extranos.\n";
                    cout << "Que decides hacer?\n";
                    cout << "1. Investigar la cueva\n";
                    cout << "2. Volver con los aldeanos\n";
                    int J2Cap2decision6;
                    cin >> J2Cap2decision6;

                    if (J2Cap2decision6 == 1) {
                        cout << "Investigas la cueva y descubres algo que da muy mala espina, ves varios cadaveres momificados.\n";
                        cout << "Que decides hacer?\n";
                        cout << "1. Confrontar a los aldeanos y preguntarles que significa eso\n";
                        cout << "2. Ignorarlo y pasar de largo\n";
                        int J2Cap2decision7;
                        cin >> J2Cap2decision7;

                        if (J2Cap2decision7 == 1) {
                            cout << "Vas con los aldeanos en busca de respuestas.\n";
                            cout << "Ellos responden: 'Ellos? Son nuestros hermanos caidos en esta lucha por sobrevivir, a lo largo de los anos hemos perdido a muchos de nuestros seres queridos desde que hemos estado aqui, sin embargo, ellos nunca nos abandonaran mientras su alma y su cuerpo esten con nosotros.'\n";
                            cout << "Decides confiar en ellos y piensas que son culturas distintas, te ofrecen pasar la noche en una habitacion y accedes.";
                        } else {
                            cout << "Decides ignorar los cadaveres y seguir explorando la cueva. Te sientes inquieto pero decides seguir adelante.\n";
                        }
                    } else {
                        cout << "Vuelves con los aldeanos y te integras en sus actividades cotidianas.\n";
                        RelajarseYConvivir();
                    }
                } else {
                    cout << "Decides descansar y recuperarte completamente antes de hacer cualquier otra cosa.\n";
                    RelajarseYConvivir();
                }
            } else {
                cout << "Responden: 'Entiendo que puedas tener desconfianza de nosotros, sin embargo, nosotros salimos adelante apoyandonos unos a otros, nada de esto hubiera sido posible sin el companerismo y la capacidad que tenemos de ayudarnos los unos a los otros. Si necesitas algo, no dudes en contar con nosotros.'\n";
                cout << "Que decides hacer?\n";
                cout << "1. Aceptar la hospitalidad y convivir\n";
                cout << "2. Aceptar pero desconfiar de ellos.\n";
                int J2Cap2decision5;
                cin >> J2Cap2decision5;

                if (J2Cap2decision5 == 1) {
                    RelajarseYConvivir();
                    cout << "Te ofrecen un lugar acogedor para poder pasar la noche";
                } else {
                    cout << "A pesar que no confias en ellos, aceptas pasar la noche en su aldea.\n";
                    RelajarseYConvivir();
                    
                }
            }
        }
        else{
            RelajarseYConvivir();
        }
    } else {
    
        cout << "Te ofrecen un lugar acogedor para poder pasar la noche.\n";
            RelajarseYConvivir();
    }
}

//===================================================================DIA 3 J2=======================================================================================================

void J2Cap3() {
    string decisionCuchillo;
    
    cout << "Has despertado luego de una larga noche acogedora y calida debido a que escuchas muchos ruidos afuera de tu habitacion\n";
    cout << "Estas somnoliento y logras ver siluetas entre los arboles con luces\n";

    int decision1cap3;
    cout << "Que decides hacer?\n";
    cout << "1. Acercarse cautelosamente\n";
    cout << "2. Acercarse directamente\n";
    cin >> decision1cap3;

    if (decision1cap3 == 1) {
        cout << "Observas desde una distancia segura y ves a los habitantes realizar rituales extranos.\n";
        cout << "1. Espiar mas tiempo\n";
        cout << "2. Buscar otra entrada\n";
        cin >> decision1cap3;

        if (decision1cap3 == 1) {
            cout << "No puede ser! Estan haciendo un ritual con una persona viva!\n";
            cout << "1. Huir desesperadamente\n";
            cout << "2. No arriesgarse y mantener la calma\n";
            cin >> decision1cap3;

            if (decision1cap3 == 1) {
                cout << "Corres lo mas que puedas, sin embargo, logran escucharte y logran rodearte\n";
                cout << "Ahora te han atrapado y has muerto\n";
                boom();
                j2vida=false;
                return;
            } else {
                cout << "A pesar de que estas muerto de los nervios decides salir sigilosamente, logras hacerlo con exito y una vez estas lo suficientemente lejos corres lo mas que puedas.\n";
                cout << "Te encuentras en medio del bosque, sin embargo, tienes un mapa por el cual te podras guiar y volver a la aldea si asi lo deseas";
                inventario2();
            }
        } else {
            cout << "Encuentras una entrada trasera menos vigilada.\n";
            cout << "Logras escapar a traves de esa entrada.\n";
            cout << "Te encuentras en medio del bosque, sin embargo, tienes un mapa por el cual te podras guiar y volver a la aldea si asi lo deseas\n";
            cout << "pero ya se esta haciendo tarde y la luz del dia se esta acabando, decides acostarte sobre una roca pero por el miedo no puedes dormir" << endl;
            inventario2();

        }

        cout << "Los habitantes te ven y te capturan.\n";
        cout << "Debes intentar escapar.\n";
        cout << "1. Crear una distraccion\n";
        cout << "2. Buscar una salida secreta\n";
        cin >> decision1cap3;

        if (decision1cap3 == 1) {
            cout << "Prendes fuego a algunos suministros y escapas en el caos.\n";
            cout << "Pierdes la mayoria de tus pertenencias pero escapas.\n";
            cout << "Te encuentras en medio del bosque, sin embargo, tienes un mapa por el cual te podras guiar y volver a la aldea si asi lo deseas";
            cout << "pero ya se esta haciendo tarde y la luz del dia se esta acabando, decides acostarte sobre una roca pero por el miedo no puedes dormir" << endl;

        } else {
            cout << "Encuentras un tunel subterraneo que te lleva fuera de la aldea.\n";
            cout << "Logras escapar ileso y te encuentras en medio del bosque, sin tener otro rumbo alguno.\n";
            cout << "sin embargo, tienes un mapa por el cual te podras guiar y volver a la aldea si asi lo deseas";
            cout << "pero ya se esta haciendo tarde y la luz del dia se esta acabando, decides acostarte sobre una roca pero por el miedo no puedes dormir" << endl;
            inventario2();

        }
    } else {
        cout << "Parece que acercarse directamente no fue una buena opcion.\n";
        cout << "Ves que estan haciendo algo que no te puedes imaginar\n";
        cout << "Estan sacrificando a una persona y te han visto a ti\n";
        cout << "Te han agarrado bruscamente.\n";
        if (tieneCuchillo == true) {
            cout << "Parece que tienes un cuchillo en tu inventario, puedes usarlo para defenderte y huir.\n";
            cout << "Quieres usarlo? (Y/N): ";
            cin >> decisionCuchillo;

            if (decisionCuchillo == "Y" || decisionCuchillo == "y") {
                cout << "Has usado el cuchillo para defenderte.\n";
                cout << "Logras huir y te encuentras en medio del bosque.\n";
                cout << "sin embargo, tienes un mapa por el cual te podras guiar y volver a la aldea si asi lo deseas";
                cout << "pero ya se esta haciendo tarde y la luz del dia se esta acabando, decides acostarte sobre una roca pero por el miedo no puedes dormir" << endl;
                inventario1();

            } else {
                cout << "Decides no usar el cuchillo.\n";
                cout << "No tienes nada para defenderte y mueres a manos de los aldeanos.\n";
                boom();
                j2vida = false;
            }
        } else {
            cout << "No tienes nada para defenderte y mueres a manos de los aldeanos.\n";
            boom();
            j2vida = false;
        }
    }
}


void inventario1(){
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

}


void inventario2(){
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
                            cout << inventarioJugador2[i] << (i < objetosRecolectados2   - 1 ? ", " : "");
                        }
                        cout << endl;
                    }
                }
}




/*===========================================DIA 4 J2============================================*/


   void Dia4j2(){
    cout << "El dia anterior no lograste dormir mucho por el miedo que te invadia " << endl;
    cout << "Pero tienes contigo el mapa hacia la aldea" << endl;
    cout << "Quieres investigar?" << endl;
    int q;
      do
      {
      cout << "1. Si, puede que escondan algo que me ayude a salir de aqui" << endl;
      cout << "2. No,puede ser muy riesgoso" << endl;
        cin >> q;
       } while (q < 1 || q > 2);

       switch (q)
       {
       case 1:
        buscarAldea();
        break;
        case 2:
        misionSecundaria();
       
       default:
        break;
       }
    
    }


void buscarAldea() {
    cout << "Decides investigar la aldea apoyandote del mapa, aunque el mapa esta un poco viejo y dificil de leer" << endl;
    cout << "Lograste encontrar la aldea, ves que esta habitada, hay chozas y parece que no hay nadie por el momento" << endl;
    cout << "Quieres investigar?" << endl;

    int s;
    do {
        cout << "1. si" << endl;
        cout << "2. no" << endl;
        cout << "Digita tu opcion: ";
        cin >> s;
    } while (s != 1 && s != 2);

    if (s == 1) {
        cout << "Te armas de valor y entras a la aldea" << endl;
        cout << "Quieres entrar a una choza?" << endl;

        int z;
        do {
            cout << "1. Si, puede haber algo util" << endl;
            cout << "2. No, es muy riesgoso" << endl;
            cout << "Digita tu opcion: ";
            cin >> z;
        } while (z != 1 && z != 2);

        if (z == 1) {
            cout << "Te armas de valor y decides entrar a una choza" << endl;
            cout << "Notas que hay sangre en el suelo y objetos en una mesa" << endl;

            int w;
            do {
                cout << "Presiona 1 para ir a la mesa" << endl;
                cout << "Digita tu opcion: ";
                cin >> w;
            } while (w != 1);

            cout << "Te acercas a la mesa y ves dos objetos en mesa" << endl;

            int a;
            do {
                cout << "1. Tomar una bengala" << endl;
                cout << "2. Tomar un paquete de comida" << endl;
                cout << "Digita tu opcion: ";
                cin >> a;
            } while (a != 1 && a != 2);

            if (a == 1) {
                cout << "Tomaste una bengala que te puede ayudar a enviar una senal de auxilio" << endl;
                inventarioJugador2[objetosRecolectados2++] = "bengala";
            } else {
                cout << "Tomaste la comida, ahora podras sobrevivir un poco mas" << endl;
                inventarioJugador2[objetosRecolectados2++] = "comida";
            }

            cout << "Ahora solo te queda huir de la aldea" << endl;
            cout << "Alto, parece que alguien viene" << endl;

            int f;
            do {
                cout << "1. Esconderme" << endl;
                cout << "2. Huir" << endl;
                cout << "Digita tu opcion: ";
                cin >> f;
            } while (f != 1 && f != 2);

            if (f == 1) {
                cout << "Decidiste esconderte bajo la mesa, si tienes suerte, lograras pasar desapercibido" << endl;

                limitealeatorio = 2;
                numale = numrand(limitealeatorio);
                switch (numale) {
                    case 1:
                        cout << "Parece que lo que sea que haya venido, ya se fue" << endl;
                        cout << "Tu respiracion esta a 1000 por hora, creo que es hora de irse" << endl;

                        int o;
                        do {
                            cout << "Presiona 1 para salir de la mesa" << endl;
                            cin >> o;
                        } while (o != 1);
                        break;
                    case 2:
                        cout << "ALGUIEN TE VIO, parece que estos seres no son civilizados, te toman y te sacrificaran" << endl;
                        boom();
                        j2vida=false;
                        break;
                }
            } else {
                cout << "Decides que es muy riesgoso entrar a una choza, por lo que te limitas a merodear por fuera" << endl;
                cout << "Parece que habitan muchas personas en esta aldea" << endl;
                cout << "El mapa indica que esconden algo importante" << endl;
                cout << "Quieres buscar lo que esconden?" << endl;

                int u;
                do {
                    cout << "1. Si, puede que me ayude a salir de esta isla" << endl;
                    cout << "2. No, mejor lo antes posible" << endl;
                    cout << "Digita tu opcion: ";
                    cin >> u;
                } while (u != 1 && u != 2);

                if (u == 1) {
                    cout << "Tomaste la decision de buscar aquello que esconden, parece que se encuentra atras de la aldea" << endl;
                    cout << "Te diriges al punto que indica el mapa, parece ser un tesoro" << endl;
                    cout << "Lo quieres abrir?" << endl;

                    int t;
                    do {
                        cout << "1. Si" << endl;
                        cout << "2. No" << endl;
                        cout << "Digita tu opcion: ";
                        cin >> t;
                    } while (t != 1 && t != 2);

                    if (t == 1) {
                        cout << "Abres el tesoro y hay una bengala" << endl;
                        inventarioJugador2[objetosRecolectados2++] = "bengala";
                    } else {
                        cout << "Decides no abrir el tesoro y mejor huyes hacia un lugar seguro para pasar la noche" << endl;
                        inventario2();
                    }
                } else {
                    cout << "Tomaste la decision de irte al bosque y buscar un lugar donde dormir" << endl;
                    inventario2();
                }
            }
        }
    } else {
        cout << "Decides que es muy riesgoso investigar la aldea y decides seguir tu camino" << endl;
        cout << "Decides recolectar madera para no volver a pasar una noche fria" << endl;
        int h;
        do
        {
        cout << "presiona 1 para recolectar madera" << endl;
        cin >> h;
        } while (h != 1);

        cout << "Parece que ya recolectaste la madera suficiente" << endl;
        inventarioJugador2[objetosRecolectados2++] = "madera";
        cout << "Ahora puedes hacer una fogata si tienes fosforos en el inventario" << endl;
        inventario2();

            bool tieneFosforos = false;
                for (int i = 0; i < objetosRecolectados2; i++) {
                    if (inventarioJugador2[i] == "fosforos") {
                        tieneFosforos = true;
                        for (int j = i; j < objetosRecolectados2 - 1; j++) {
                            inventarioJugador2[j] = inventarioJugador2[j + 1];
                        }
                        objetosRecolectados2--;
                        break;
                    }
                }
          if (tieneFosforos == true)
          {
            cout << "Parece que tienes fosforos" << endl;
            int w;
            do
            {
              cout << "Presiona 1 para encender la fogata" << endl;
              cout << "Digit tu opcion: ";
            } while (w != 1);
            cout << "Ahora podras pasar la noche dandote calor con el fuego de la fogata" << endl;
            
          }
          else
          {
              cout << "No tienes fosforos por lo que recolectar  madera fue un gasto innecesario de esfuerzo y tiempo" << endl;
              cout << "Ahora pasaras la noche con frio y ademas estas muy cansado y te quedan pocas engergias" << endl;
            
          } 
    }
}

void misionSecundaria() {
    cout << "Decides que es muy riesgoso ir a investigar por lo que comienzas a caminar sin rumbo" << endl;
    cout << "Luego de unos minutos de caminar a la deriva comienzas a escuchar la caida de una cascada" << endl;
    cout << "Haz encontrado un manantial de agua pura" << endl;
    cout << "Quieres darte un chapuzon?" << endl;

    int t;
    do {
        cout << "1. Si, el agua se ve refrescante y llevo mucho tiempo sin ducharme" << endl;
        cout << "2. No, quien sabe que cosas habiten dentro" << endl;
        cout << "Digita tu opcion: ";
        cin >> t;
    } while (t != 1 && t != 2);

    if (t == 1) {
        cout << "Muy bien, parece que te refrescaras, un poco, hay un risco un poco cerca" << endl;
        cout << "Quieres subir y darte un clavado?" << endl;
        
        int y;
        do {
            cout << "1. Si, puede ser divertido, necesito alegria entre tanta tristeza y desesperacion" << endl;
            cout << "2. No, puede ser peligroso ya que no conozoco que tan profundo esta" << endl;
            cout << "Digita tu opcion: ";
            cin >> y;
        } while (y != 1 && y != 2);

        if (y == 1) {
            cout << "Caminas un poco hasta subir al risco y estas listo para tirarte, tomas carrera y te lanzas" << endl;
            cout << "El nivel del agua era de poco menos de un metro, por lo que la caida desde esa altura fue fatal" << endl;
            boom();
            j2vida=false;
        } else {
            cout << "Decides no tirarte y optas por entrar cuidadosamente, el agua esta calida" << endl;
            cout << "Te percatas que no esta tan hondo como pensabas, el nivel del agua es poco mas de un metro por lo que una caida desde el risco hubiese sido fatal" << endl;
            cout << "Hay unos pescados que andan por ahi" << endl;
            cout << "Quieres pescar?" << endl;

            int a;
            do {
                cout << "1. Si, no tengo nada en el estomago" << endl;
                cout << "2. No, puede que esos peces no sean comestibles" << endl;
                cout << "Digita tu respuesta: ";
                cin >> a;
            } while (a != 1 && a != 2);

            if (a == 1) {
                cout << "Presiona 1 para pescar con las manos" << endl;
                int e;
                do {
                    cout << "Digita tu respuesta: ";
                    cin >> e;
                } while (e != 1);

                cout << "Agarraste uno, ahora ya tienes que cenar" << endl;
                inventarioJugador2[objetosRecolectados2++] = "pescado";
                cout << endl << endl;
                cout << "Sales de la cascada y te vas a buscar un lugar para pasar la noche y comer tu pescado" << endl;
                inventario2();
            } else {
                cout << "Decides no pescar y sales del agua, te diriges en busca de un lugar donde pasar la noche" << endl;
                cout << "Al salir del agua te rompes en llanto y te das cuenta que toda posibilidad de salir de la isla cada vez es menos" << endl;
                inventario2();
            }
        }
    } else {
        cout << "Decides no meterte y te reservas solo a sentarte a observar el paisaje" << endl;
        cout << "Un conejo pasa enfrente de ti y se queda observando el panorama contigo" << endl;
        cout << "Lo quieres cazar?" << endl;

        int y;
        do {
            cout << "1. Si, me servira para tener algo en el estomago" << endl;
            cout << "2. No, podre estar muriendo de hambre pero no le arrebatare la vida a ese pobre conejito" << endl;
            cout << "Digita tu opcion: ";
            cin >> y;
        } while (y != 1 && y != 2);

        if (y == 1) {
            cout << "Para intentar cazar al conejo, muevete sigilosamente y toma una piedra" << endl;
            cout << "Solo tienes una oportunidad" << endl;

            int u;
            do {
                cout << "Presiona 1 para tirar la piedra" << endl;
                cin >> u;
            } while (u != 1);

            limitealeatorio = 2;
            numale = numrand(limitealeatorio);
            switch (numale) {
                case 1:
                    cout << "Le diste al conejo, con lagrimas en tus mejillas lo recojes" << endl;
                    inventarioJugador2[objetosRecolectados2++] = "carne de conejo";
                    cout << "Ahora que ya tienes carne de conejo, te diriges en busca de un refugio para pasar la noche e intentar cocinar el conejo" << endl;
                    inventario2();
                    break;
                case 2:
                    cout << "Fallaste, el conejo se asusto y corrio" << endl;
                    cout << "Te levantas y rompes en llanto, no puedes creer hasta donde has llegado" << endl;
                    cout << "Te vas caminando en busca de un lugar donde poder pasar otra solitaria noche" << endl;
                    inventario2();
                    break;
            }
        } else {
            cout << "A pesar de la pesima situacion en la que te encuentras, aun asi no pierdes tus principios y valores" << endl;
            cout << "No te queda nada mas por hacer, tu cuerpo esta debil y necesita descansar, por lo que te vas en busca de un lugar donde pasar la noche" << endl;
            inventario2();
        }
    }
}

/*========================Dia 5====================================================*/

 void dia5j1(){
    cout<<"Despues de todo lo que habias pasado el dia anterior, te despiertas temprano\n";
    cout<<"Que deberias hacer ahora?\n";
    do{
    cout<<"1. Saldre a explorar al bosque\n"<<"2. Ire a la playa\n";
    cin>>desicionp;
    if(desicionp!=1&&desicionp!=2){
      cout<<"Valor no valido, ingrese un valor valido\n";
    }
    }while(desicionp!=1&&desicionp!=2);
    if(desicion==1){
      cout<<"Te adentras en el bosque, avanzas un rato, pero de repente ves como los arboles se mueven por el viento\n";
      cout<<"Que deberias hacer?, seguir avanzando o intentar volver al refugio\n";
      do{
        cout<<"1. Veo algo cerca, mejor me refugio ahi\n"<<"2. Regresemos la cosa se ve fea\n";
        cin>>desicion;
       if(desicionp!=1&&desicionp!=2){
      cout<<"Valor no valido, ingrese un valor valido\n";
       }
      }while(desicion!=1&&desicion!=2);
      if(desicion==1){
       cout<<"Caminas un poco y encuentras una estacion de radio abandonada\n";
       cout<<"Al entrar vez mucho material de radio muy especializado, parece haber sido alguna base militar\n";
       cout<<"Ves una antena en la cual parece que se puede conectar una radio, pero no parece ser compatible para cualquier radio\n";
       if(Radio==1){
        cout<<"Tomas la radio que encontrastes en la cueva y parce conectar a la perfeccion\n";
        cout<<"Intentas buscar ayuda por codigo morse\n";
        cout<<"La lluvia no parece cesar y la esperanza de salir ese dia se van perdiendo\n";
        cout<<"Pero de repente\n";
        cout<<"H...o..la...nos.....e.s...cu....chas...\n";
        cout<<jugador1<<" Hola, hola, SOS, estoy en medio de una isla cerca de Inglaterra, porfavor manden ayuda\n";
        cout<<"No.....te....mu...e..vas...vam...os....en.....c..a.....mi...no\n";
        cout<<"Relajado te sientas, pero cuando menos lo esperabas un rayo impacta en la antena, quemandola y dejandote descomunicado\n";
        cout<<"Que deberias hacer ahora, no pudistes escuchar todas las indicaciones de los militares\n";
        do{
          cout<<"1. Vamos a un lugar alto para que me puedan ver\n"<<"2. Mejor me quedo aqui, puede que no logren ubicarme\n";
          cin>>desicion;
         if(desicion!=1&&desicion!=2){
      cout<<"Valor no valido, ingrese un valor valido\n";
       }
        }while(desicion!=1&&desicion!=2);
      if(desicion==1){
        cout<<"Sales en medio de la tormenta y corres para llegar a una colina que se encuentra cerca\n";
        cout<<"Al subir la colina escuchas el sonido de un hilicoptero y agitas tus manos para llamar la atencion del piloto\n";
        cout<<"Finalmente de varios gritos logras llamar la atencion del piloto, en hora buena te han rescatado\n";
        cout<<"Sobrevivistes, pero piensas en tu amigo que quizas no haya corrido con la misma suerte\n";
      }else{
        cout<<"Te quedas en la estacion de radio\n";
        cout<<"Despues de un rato por la ventana ves dos figuras raras y por la lluvia y la neblina no logras ver que son tan siquiera\n";
        cout<<"Parecen querer entrar a la estacion de radio, que haras?";
        do{
          cout<<"1. Golpeemos primero y preguntemos despues\n"<<"2. Podrian ser las personas que vienen a ayudarme\n";
          cin>>desicion;
         if(desicion!=1&&desicion!=2){
        cout<<"Valor no valido, ingrese un valor valido\n";
         }
        }while(desicion!=1&&desicion!=2);
        if(desicion==1){
         cout<<"Tomas lo primero que tenias a la mano y corres gritando para golpear, lo ultimo que recuerdas fue un disparo\n";
         cout<<"Eran los militares que venian a rescatarte, pero por ese pensamiento de atacar primero y preguntar despues no contaras lo visto en la isla\n";
         boom();
         j1vida=false;
        }else{
          cout<<"Los dos entes entran en la estacion, y resulta que eran los militares que venian a rescatarte\n";
          cout<<"Finalmente logras salir de la isla por helicoptero\n";
          cout<<"Sobrevivistes\n";
        }
      }
       }else{
         cout<<"No posees ninguna radio que sea compatible con la antena, pero parece que rebuscandote en los escombros podrias encontrar algo\n";
         cout<<"Pasa el tiempo y no logras encontrar nada\n";
         cout<<"Derrepente vez una sala detras de unas cajas, deceas abrirla?\n";
         do{
          cout<<"1. Podria haber algo util ahi\n"<<"2. Mejor no\n";
          cin>>desicion;
          if(desicion!=1&&desicion!=2){
         cout<<"Valor no valido, ingrese un valor valido\n";
          }
         }while(desicion!=1&&desicion!=2);
         if(desicion==1){
          cout<<"Abres la puerta\n";
          limitealeatorio = 2;
          numale = numrand(limitealeatorio);
          switch(numale){
            case 1:
            cout<<"Al abrir la puerta encuentras un material brilloso que irradia una gran luz y gran calor\n";
            cout<<"No le das importacia, pero luego de un rato te empiezas a sentir mal\n";
            cout<<"Parece que era un gran cristal de uranio, al fin y al cabo este lugar era una base militar, pero porque tenian uranio en tal cantidad\n";
            boom();
            j1vida=false;
            break;
            case 2:
            cout<<"Abres la puerta y encuentras una radio en perfecto estado, la usas para llamar a alguien\n";
            cout<<"Luego de un rato intentando hablar por morse, recives respuesta\n";
            cout<<"Ho..la.....re...ci...v...imos.....tu...lla....ma..do\n";
            cout<<jugador1<<" hola necesito ayuda, estoy en medio de una isla cerca de Inglaterra\n";
            cout<<"Vam....os..en...cami.....no.....no....t..e...mue....vas\n";
            cout<<"Luego de un rato finalmente te rescatan\n";
            cout<<"Sobrevivistes\n";
          }
         }else{
           cout<<"No abres la puerta, luego de un rato sin saber que hacer sales pero la lluvia es muy fuerte y con tanta niebla te pierdes, finalmente por el cansancio caes\n";
           boom();
           j1vida=false;
         }
       }
         
      }else{
        cout<<"Regresas al refugio, pero en camino te agarra la lluvia, esta comienza a ser cada vez mas furte, y con la neblina empiezas a desorientarte, finalmente por el cansancio caes\n";
        boom();
        j1vida=false;
      }
    }else{
      cout<<"Te dirijes a la playa y cuando ibas de camino ves una gran nube de lluvia, que se acerca poco a poco\n";
      cout<<"Que deberias hacer, regresar o seguir avanzando\n";
      do{
        cout<<"1. Sigamos no creo que sea la gran cosa\n"<<"2. Mejor regresemos\n";
        cin>>desicion;
      if(desicion!=1&&desicion!=2){
        cout<<"Valor no valido, ingrese un valor valido\n";
         }
      }while(desicion!=1&&desicion!=2);
      if(desicion==1){
        cout<<"Sigues caminando y te encuentras con un puerto abandonado\n";
        cout<<"En el puerto hay muchos barcos pero todos parecen estar desmantelados\n";
        cout<<"Avanzas y encuentras una lancha que parece estar en buenas condiciones\n";
        bool tienellaves = false;
        for(int i = 0; i < objetosRecolectados1; i++){
          if (inventarioJugador1[i]== "llaves de lancha"){
            tienellaves = true;
            for(int j= i; j < objetosRecolectados1 - 1; j++){
              inventarioJugador1[j] = inventarioJugador1[j + 1];
            }
            objetosRecolectados1 --;
            break;
          }
        }
      if(tienellaves==1){
        cout<<"Recuerdas la llave que encontrastes\n";
        cout<<"Te subes e intentas arrancar la lancha\n";
        cout<<"Por un momento pensastes que no funcionario\n";
        cout<<"Pero finalmente arranco y lograstes salir de la isla\n";
        cout<<"Sobreviviste\n";
      }else{
        cout<<"La lancha parece estar en buen estado, asi que subes pero parece necesitar una llave para arrancar\n";
        cout<<"Que deberias hacer, intentar forzar el arranque con algo, o mejor investigar el puerto para ver si encuentras algo mas?\n";
        do{
          cout<<"1. Forcemos haber que pasa\n"<<"2. Mejor exploremos\n";
          cin>>desicion;
         if(desicion!=1&&desicion!=2){
        cout<<"Valor no valido, ingrese un valor valido\n";
         }
        }while(desicion!=1&&desicion!=2);
        if(desicion==1){
        limitealeatorio = 2;
        numale = numrand(limitealeatorio);
        switch(numale){
          case 1:
          cout<<"Fuerzas donde va la llave y milagrosamente logras arrancar la lancha\n";
          cout<<"Sobrevivistes\n";
          break;
          case 2:
          cout<<"Fuerzas donde va la llave, pero lo unico que logras es crear un derrame de gasolina de la lancha, pero no te distes cuentas y una flama creada por la friccion del forcejeo creo una gran explosion\n";
          boom();
          j1vida=false;
        }  
        }else{
          cout<<"Sales a investigar y la tormenta no ha parado, asi que esperas en el puerto pero por la tormenta se crea en el mar un gran tifon\n";
          cout<<"Intentas correr pero ya es muy tarde y eres arrastrado por el tifon al mar avierto\n";
          boom();
          j1vida=false;
        }
      }
      }else{
        cout<<"Regresas al refugio, pero en camino te agarra la lluvia, esta comienza a ser cada vez mas furte, y con la neblina empiezas a desorientarte, finalmente por el cansancio caes\n";
        boom();
        j1vida=false;
      }
    }
 }

void dia5j2(){
   cout<<"Despiertas por la madrugada, te levantas, que deberias hacer ahora\n";
   cout<<"Te dirijes a la playa o adentras al bosque\n";
   do{
    cout<<"1. Vamos a la playa\n"<<"2. Adentremonos en el bosque\n";
    cin>>desicionp;
  if(desicionp!=1&&desicionp!=2){
        cout<<"Valor no valido, ingrese un valor valido\n";
         }
   }while(desicionp!=1&&desicionp!=2);
   if(desicionp==1){
    cout<<"Vas de camino a la playa cuando empieza a llover, parece que se pondra peor Quieres regresar?\n";
    do{
        cout<<"1. Sigamos caminando\n"<<"2. Mejor regresemos, podria ser peligroso\n";
      if(desicion!=1&&desicion!=2){
        cout<<"Valor no valido, ingrese un valor valido\n";
         }
    }while(desicion!=1&&desicion!=2);
    if(desicion==1){
       cout<<"Sigues caminando y ves que las olas cada vez se vuelven mas violentas\n";
       cout<<"A lo lejos logras divisar una figura de un barco\n";
       bool tienebengala = false;
       for(int i = 0; i< objetosRecolectados1; i++){
        tienebengala = true;
        for(int j = i; j < objetosRecolectados1 - 1; j++){
            inventarioJugador1[j] = inventarioJugador1[j + 1];
        }
        objetosRecolectados1--;
        break;
       }
    if(tienebengala==true){
       cout<<"Usas la bengala para llamar la atencion del barco\n";
       cout<<"Parece haber visto tu llamado\n";
       cout<<"El barco se acerca\n";
       cout<<"Sobrevivistes\n";
    }else{
        cout<<"Logras ver una gran roca la cual podrias usar para que te vean, subes y saltas para que te vean\n";
        limitealeatorio = 2;
        numale = numrand(limitealeatorio);
        switch(numale){
            case 1:
            cout<<"Por fortuna el barco parece haberte visto y se regresa a la orilla\n";
            cout<<"Te has salvado\n";
            cout<<"Sobrevivistes\n";
            break;
            case 2:
            cout<<"Al saltar te caes y te rompes el cuello\n";
            cout<<"Nunca sabras si te vieron\n";
            boom();
            j2vida=false;
            break;
        }
    }
    }else{
        cout<<"Regresas al refugio, pero en camino te agarra la lluvia, esta comienza a ser cada vez mas furte, y con la neblina empiezas a desorientarte, finalmente por el cansancio caes\n";
        boom();
        j2vida=false;
    }
   }else{
       cout<<"Te dirijes al bosque, pero empieza a llover\n";
       cout<<"Quieres continuar o mejor regresas al tu base\n";
       do{
        cout<<"1. Continuemos es lo mejor\n"<<"2. Mejor regresar\n";
        cin>>desicion;
       if(desicion!=1&&desicion!=2){
        cout<<"Valor no valido, ingrese un valor valido\n";
         }
       }while(desicion!=1&&desicion!=2);
       if(desicion ==1){
        cout<<"Al caminar por un rato, descubre un antiguo hangar abandonado\n";
        cout<<"Parece que no hay otro lugar a donde ir, asi que decides quedarte ahi por la lluvia\n";
        cout<<"Al ingresar al hangar observas una avioneta en un estado aceptable\n";
        cout<<"Crees que sea buena idea intentar hacer funcionar esa cosa?\n";
        do{
        cout<<"1. Intentemos\n"<<"2. Mejor no, podria ser peligroso\n";
        cin>>desicion;
            if(desicion!=1&&desicion!=2){
        cout<<"Valor no valido, ingrese un valor valido\n";
         }
        }while(desicion!=1&&desicion!=2);
        if(desicion==1){
            limitealeatorio = 2;
            numale = numrand(limitealeatorio);
            switch(numale){
                case 1:
                cout<<"Luego de estar intentando logras arrancar el avion\n";
                cout<<"Sales volando del lugar\n";
                cout<<"Sobrevivistes\n";
                break;
                case 2:
                cout<<"Al intentar hacer que arranque, el motor empezo a hacer sonido raros\n";
                cout<<"El avion termino explotando\n";
                cout<<"No quedo mucho de ti\n";
                boom();
                j2vida=false;
                break;
            }
        }else{
            cout<<"Decides esperar a que pase la lluvia\n";
            cout<<"Luego de un tiempo escuchas un avion pasar\n";
            cout<<"Parece que son unos militares\n";
            cout<<"Al aterrizar los soldados te dicen que digas quien eres y que haces ahi\n";
            cout<<"Que deberias hacer?\n";
            do{
                cout<<"1. Explicarles exactamente a detalle todo\n"<<"2. Golpear y despues preguntar\n";
                cin>>desicion;
             if(desicion!=1&&desicion!=2){
            cout<<"Valor no valido, ingrese un valor valido\n";
            }
            }while(desicion!=1&&desicion!=2);
            if(desicion==1){
                cout<<"Les explicas todo y ellos entienden tu situacion, te ayudan y te sacan de la isla\n";
                cout<<"Sobrevivistes\n";
            }else{
                cout<<"Intentas golpear pero te reciven con una bala\n";
                cout<<"La verdad no se que esperabas\n";
                boom();
                j2vida=false;
            }
        }
       }else{
         cout<<"Regresas al refugio, pero en camino te agarra la lluvia, esta comienza a ser cada vez mas furte, y con la neblina empiezas a desorientarte, finalmente por el cansancio caes\n";
        boom();
        j2vida=false;
       }
   }
}