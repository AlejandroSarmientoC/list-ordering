#include <iostream>
#include "lista.h"

using namespace std;

int main(){

    CircularDoublyLinkedList lista;

    lista.insert(12345678, "Juan", "Perez");
    lista.insert(87654321, "Maria", "Gomez");
    lista.insert(11111111, "Pedro", "Gonzalez");
    lista.insert(22222222, "Jose", "Rodriguez");
    lista.insert(33333333, "Luis", "Martinez");

    lista.show();

    cout << "Ordenando por cédula..." << endl;
    lista.sortByCedula();
    lista.show();

    cout << "Ordenando por apellido..." << endl;
    lista.sortByApellido();
    lista.show();


    return 0;
}