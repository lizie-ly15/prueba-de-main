#include<iostream>
#include "mostrarAyuda.hpp"


using namespace std;
int main(){
   
   int opt;

  cout <<"Bienvenido al juego de ahorcado"<<endl;


do
{
    cout<<"1-Jugadores"<<endl;
    cout<<"2-Mostrar ganadores"<<endl;
    cout<<"3-Ayuda"<<endl;
    cout<<"4-Mostrar integrantes"<<endl;
    cout<<"5-Salir"<<endl;
    cout<<"opcion";
    cin>>opt;


switch (opt)
{
 case 1:
    cout<<"Jugadores"<<endl;  
    break;

    case 2:
    cout <<"Mostrarganadores"<<endl;
    break;

    case 3:
       cout<<"Ayuda"<<endl;
       break;

       case 4:
       cout<<"Mostrarintegrantes"<<endl;
       break;

       case 5:
       cout<<"Adios"<<endl;
       break;
    default:
    cout<<"Opcion no valida"<<endl;
    break;

}
}while (opt != 5);

 
 
 
 return 0;
}