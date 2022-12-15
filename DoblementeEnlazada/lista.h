// .h file
#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <string>

template <typename T>
class Lista {
 public:
  Lista();
  ~Lista();

  void Insertar(int cedula, std::string nombre, std::string apellido);
  void OrdenarPorCedula();
  void OrdenarPorApellido();
  void Mostrar();

 private:
  template <typename U>
  class Nodo {
   public:
    int cedula;
    std::string nombre;
    std::string apellido;
    Nodo<U> *siguiente;
    Nodo<U> *anterior;

    Nodo(int cedula, std::string nombre, std::string apellido)
        : cedula(cedula),
          nombre(nombre),
          apellido(apellido),
          siguiente(nullptr),
          anterior(nullptr) {}
  };

  Nodo<T> *primero;
};

#include "lista.cpp"

#endif
