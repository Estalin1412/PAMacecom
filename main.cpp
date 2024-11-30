//
// Created by jemd2 on 6/11/2024.
//
#include <iostream>
#include <windows.h>

using std::endl;
using std::cout;
using std::cin;
using std::string;

#define MENU_DE_OPCIONES  0
#define INGRESE_OPCION  1
#define OP1CAMBIAR_VALOR_COMUN  2
#define OP2CAMBIAR_VALOR_PUNTERO  3
#define OP3CAMBIAR_PUNTERO_CAMBIANTE  4
#define OP4TERMINAR_PROCESO  5
int Menu();
int Menu(int a);

string diccionary[]={
    "Menu de opciones.",
    "Ingrese la opcion que desea: ",
    "1) Cambiar datos de la memoria.",
    "2) Leer variable que cambia.",
    "3) Leer puntero varible.",
    "4) Terminar proceso."
};

int main (){

    return 0;
}



/*FUNCIONES-------------------------------------------------------------------------------*/
//Mostrar menu
int Menu() {
    cout<<diccionary[MENU_DE_OPCIONES]<<endl;
    cout<<diccionary[OP1CAMBIAR_VALOR_COMUN]<<endl;
    cout<<diccionary[OP2CAMBIAR_VALOR_PUNTERO]<<endl;
    cout<<diccionary[OP3CAMBIAR_PUNTERO_CAMBIANTE]<<endl;
    cout<<diccionary[OP4TERMINAR_PROCESO]<<endl;
    int a = 0;
    cin>>a;
    return a;
}

int Menu(int a) {
    cout<<diccionary[MENU_DE_OPCIONES]<<endl;
    cout<<diccionary[OP1CAMBIAR_VALOR_COMUN]<<endl;
    cout<<diccionary[OP2CAMBIAR_VALOR_PUNTERO]<<endl;
    cout<<diccionary[OP3CAMBIAR_PUNTERO_CAMBIANTE]<<endl;
    cout<<diccionary[OP4TERMINAR_PROCESO]<<endl;
    cin>>a;
    return a;
}




