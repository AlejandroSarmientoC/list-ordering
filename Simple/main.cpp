#include <iostream>
#include "lista.h"
#include "lista.cpp"

using namespace std;

int main(){

    Lista<int> lista;

    lista.Insertar(1771722388, "Jose", "Perez");
    lista.Insertar(1802813921, "Juan", "Perez");
    lista.Insertar(1751722387, "Pedro", "Gomez");
    lista.Insertar(1802813920, "Maria", "Gomez");
    
    lista.OrdenarPorCedula();

    lista.Mostrar();

    lista.OrdenarPorApellido();

    lista.Mostrar();

    return 0;
}