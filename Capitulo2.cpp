#include <iostream>
using namespace std;


//Esto es todo el dia 2, con sus respectivos eventos aleatorios.
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
            cout<<"Decides hacer un mini refugio, ahora podras estar a salvo por el resto de la noche";
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

//Aqui empiezan los eventos aleatorios del dia 2, este es el primero.


int main(){
    Dia2();

return 0;
}