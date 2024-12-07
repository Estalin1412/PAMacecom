//
// Created by jemd2 on 6/11/2024.
//
#include <iostream>
#include <windows.h>
/*Para trabajar con las instancias de procesos*/
#include <tlhelp32.h>

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
#define OP5PROCESSO_PROCESSO  6

/*Encabezado de funciones*/
int Menu();
int Menu(int &a);
void funEscanearMemoria(HANDLE gestionar, int targetValue);
DWORD getProcessID(char * processName);

string diccionary[]={
    "Menu de opciones.",
    "Ingrese la opcion que desea: ",
    "1) Cambiar datos de la memoria.",
    "2) Leer variable que cambia.",
    "3) Leer puntero varible.",
    "4) Terminar proceso."
};

/*DEFINICION DE FUNCIONES------------------------------------------------------------*/
void ListAllProcesses() {
    PROCESSENTRY32 entradaProcesos;
    entradaProcesos.dwSize = sizeof(PROCESSENTRY32);
    // Tomamos una instantánea de todos los procesos en ejecución
    HANDLE instancia = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (instancia == INVALID_HANDLE_VALUE) {
        cout << "No carga instancia" << GetLastError() << endl;
        return;
    }
    // Iteramos por los procesos encontrados
    if (Process32First(instancia, &entradaProcesos)) {
        do {
            cout << "Proceso: " << entradaProcesos.szExeFile
                 << "ID:  " << entradaProcesos.th32ProcessID << endl;
        } while (Process32Next(instancia, &entradaProcesos));
    } else {
        cout << "Error en la primera entrada" << GetLastError() << endl;
    }
    // Cerramos el handle de la instantánea
    CloseHandle(instancia);
}


int main() {
    int op;
    op = Menu(op);
    ListAllProcesses();

    const char* proceso= "age2.exe";



    return 0;
}

/*FUNCIONES-------------------------------------------------------------------------------*/
//Función para menu de opciones
/*
 * Te muestre el menu de opciones
 * Te pide que ingrese una opcion
 * Te devuelve la opcion ingresada
 */
int Menu() {
    cout<<diccionary[MENU_DE_OPCIONES]<<endl;
    cout<<diccionary[OP1CAMBIAR_VALOR_COMUN]<<endl;
    cout<<diccionary[OP2CAMBIAR_VALOR_PUNTERO]<<endl;
    cout<<diccionary[OP3CAMBIAR_PUNTERO_CAMBIANTE]<<endl;
    cout<<diccionary[OP4TERMINAR_PROCESO]<<endl;
    int a = 0;
    cout<<"Ingrese la opcion deseada: "<<endl;
    cin>>a;
    return a;
}
/*
 * Entrada: Ingresa un valor donde quieres guardar el valor
 * Te muestre el menu de opciones
 * Te pide que ingrese una opcion
 * Guarda la opcion ingresada
 * Te devuelve la opcion ingresada
 */
int Menu(int & a){
    cout<<diccionary[MENU_DE_OPCIONES]<<endl;
    cout<<diccionary[OP1CAMBIAR_VALOR_COMUN]<<endl;
    cout<<diccionary[OP2CAMBIAR_VALOR_PUNTERO]<<endl;
    cout<<diccionary[OP3CAMBIAR_PUNTERO_CAMBIANTE]<<endl;
    cout<<diccionary[OP4TERMINAR_PROCESO]<<endl;
    cout<<"Ingrese la opcion deseada: "<<endl;
    cin>>a;
    return a;
}

DWORD getProcessID(char * processName) {
    DWORD procesoId = 0;
    PROCESSENTRY32 entrada;
    entrada.dwSize = sizeof(PROCESSENTRY32);
    HANDLE instancia = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if(Process32First(instancia, &entrada)) {
        do {
            if(strcmp(entrada.szExeFile, processName) == 0) {
                procesoId = entrada.th32ProcessID;
                break;
            }
        } while (Process32Next(instancia, &entrada));
    }
    CloseHandle(instancia);
    return procesoId;
}

void funEscanearMemoria(HANDLE gestionar, int targetValue) {
    SYSTEM_INFO inforSistema;
    GetSystemInfo(&inforSistema);

    LPCVOID inicio = inforSistema.lpMinimumApplicationAddress;
    LPCVOID fin= inforSistema.lpMaximumApplicationAddress;
    MEMORY_BASIC_INFORMATION inforMemoria;
    for(LPCVOID address = inicio; address < fin; ) {
        if(VirtualQueryEx(gestionar, address,&inforMemoria, sizeof(inforMemoria)) == 0) {
            break;
        }

        //Verificamos
        if(inforMemoria.State == MEM_COMMIT && (inforMemoria.Protect == PAGE_READWRITE || inforMemoria.Protect == PAGE_EXECUTE_READWRITE) ) {
            BYTE* buffer = new BYTE[inforMemoria.RegionSize];
            SIZE_T byteLeido;

            if(ReadProcessMemory(gestionar, address, buffer,inforMemoria.RegionSize, &byteLeido)) {
                for(SIZE_T i = 0; i < byteLeido - sizeof(int); i++) {
                    int value = *(int*)(buffer+i);
                    if(value == targetValue) {
                        cout<<"Se encuentra: "<<value<<" en : "<<static_cast<void*>((BYTE*)address+i)<<endl;
                    }
                }
            }
            delete[] buffer;
        }
        address = (BYTE*)inforMemoria.BaseAddress + inforMemoria.RegionSize;
    }
}




