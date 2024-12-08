#include <cstdint>
#include <iostream>

using namespace std;

string diccionary[] = {
    "Menu de opciones.",
    "Ingrese la opcion que desea: ",
    "1) Cambiar datos de la memoria.",
    "2) Leer variable que cambia.",
    "3) Leer puntero varible.",
    "4) Encontrar precesos."
    };

class DiccionarioJose{
  public:
      string *diccionario;
    string *nameProcesos;
    uint8_t *IDprocesos;
    uint32_t    *direccionesProcesos;
     DiccionarioJose(){
          this->diccionario = diccionary;
      };

};

