//
// Created by jemd2 on 6/11/2024.
//
#include <iostream>
#include <windows.h>
/*Para trabajar con las instancias de procesos*/
#include <tlhelp32.h>
#include "diccionario.cpp"

using std::endl;
using std::cout;
using std::cin;
using std::string;

#define OPMENU_OPCIONES 0
#define OPMEN_INGRESEOPCIONES
#define OP1CAMBIAR_VALOR_COMUN  2
#define OP2CAMBIAR_VALOR_PUNTERO  3
#define OP3CAMBIAR_PUNTERO_CAMBIANTE  4
#define OP4ENCONTRAR_PROCESSO  5


/*Encabezado de funciones*/
int Menu();
int Menu(int &a);
void funEscanearMemoria(HANDLE gestionar, int targetValue);
DWORD getProcesoID(char * processName);


/*DEFINICION DE FUNCIONES------------------------------------------------------------*/
void funListarProcesos(){
    /*Objeto de datos de procesos para 32 bytes*/
    PROCESSENTRY32 entradaProcesos;
    /*Ingreso que tipo de tamaño quiero que lea*/
    entradaProcesos.dwSize = sizeof(PROCESSENTRY32);
    //Tomamos una instantánea de todos los procesos en ejecución
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
    CloseHandle(instancia);
}

/*MAINXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
int main() {
    int op;
    do {
        op = Menu(op);
        switch (op) {
            case 1: {
                cout << "Ingrese el nombre del proceso: ";
                char nameProceso[100];
                cin >> nameProceso;

                DWORD procesosID = getProcesoID(nameProceso);
                if (procesosID == 0) {
                    cout << "No hay procesos"<< nameProceso <<endl;
                    break;
                }

                HANDLE handleDelProceso = OpenProcess(PROCESS_VM_READ | PROCESS_QUERY_INFORMATION, FALSE, procesosID);
                if(handleDelProceso == NULL){
                    cout<< GetLastError() << endl;
                    break;}

                cout <<procesosID << endl;
                int valorObjetivo;
                cin >> valorObjetivo;
                funEscanearMemoria(handleDelProceso, valorObjetivo);
                CloseHandle(handleDelProceso);
                break;
            }
            case 2: {
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                funListarProcesos();
            }
        }
    }while (0 <= op< 4);


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
    cout<<diccionary[OPMENU_OPCIONES]<<endl;
    cout<<diccionary[OP1CAMBIAR_VALOR_COMUN]<<endl;
    cout<<diccionary[OP2CAMBIAR_VALOR_PUNTERO]<<endl;
    cout<<diccionary[OP3CAMBIAR_PUNTERO_CAMBIANTE]<<endl;
    cout<<diccionary[OP4ENCONTRAR_PROCESSO]<<endl;
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
    cout<<diccionary[OPMENU_OPCIONES]<<endl;
    cout<<diccionary[OP1CAMBIAR_VALOR_COMUN]<<endl;
    cout<<diccionary[OP2CAMBIAR_VALOR_PUNTERO]<<endl;
    cout<<diccionary[OP3CAMBIAR_PUNTERO_CAMBIANTE]<<endl;
    cout<<diccionary[OP4ENCONTRAR_PROCESSO]<<endl;
    cout<<"Ingrese la opcion deseada: "<<endl;
    cin>>a;
    return a;
}

DWORD getProcesoID(char * processName) {
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




