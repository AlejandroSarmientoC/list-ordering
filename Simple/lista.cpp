#pragma once

// .cpp file
#include "lista.h"

template <typename T>
Lista<T>::Lista() : primero(nullptr) {}

template <typename T>
Lista<T>::~Lista() {
  Nodo<T> *actual = primero;
  while (actual != nullptr) {
    Nodo<T> *borrar = actual;
    actual = actual->siguiente;
    delete borrar;
  }
}

template <typename T>
void Lista<T>::Insertar(int cedula, std::string nombre, std::string apellido) {
  Nodo<T> *nuevo = new Nodo<T>(cedula, nombre, apellido);
  if (primero == nullptr) {
    primero = nuevo;
  } else {
    Nodo<T> *actual = primero;
    while (actual->siguiente != nullptr) {
      actual = actual->siguiente;
    }
    actual->siguiente = nuevo;
  }
}

template <typename T>
void Lista<T>::OrdenarPorCedula() {
  Nodo<T> *actual = primero;
  while (actual != nullptr) {
    Nodo<T> *siguiente = actual->siguiente;
    while (siguiente != nullptr) {
      if (actual->cedula > siguiente->cedula) {
        int cedula = actual->cedula;
        std::string nombre = actual->nombre;
        std::string apellido = actual->apellido;
        actual->cedula = siguiente->cedula;
        actual->nombre = siguiente->nombre;
        actual->apellido = siguiente->apellido;
        siguiente->cedula = cedula;
        siguiente->nombre = nombre;
        siguiente->apellido = apellido;
      }
      siguiente = siguiente->siguiente;
    }
    actual = actual->siguiente;
  }
}

template <typename T>
void Lista<T>::OrdenarPorApellido() {
  Nodo<T> *actual = primero;
  while (actual != nullptr) {
    Nodo<T> *siguiente = actual->siguiente;
    while (siguiente != nullptr) {
      if (actual->apellido > siguiente->apellido) {
        int cedula = actual->cedula;
        std::string nombre = actual->nombre;
        std::string apellido = actual->apellido;
        actual->cedula = siguiente->cedula;
        actual->nombre = siguiente->nombre;
        actual->apellido = siguiente->apellido;
        siguiente->cedula = cedula;
        siguiente->nombre = nombre;
        siguiente->apellido = apellido;
      }
      siguiente = siguiente->siguiente;
    }
    actual = actual->siguiente;
  }
}

template <typename T>
void Lista<T>::Mostrar() {
  Nodo<T> *actual = primero;
  while (actual != nullptr) {
    std::cout << actual->cedula << " " << actual->nombre << " " << actual->apellido << std::endl;
    actual = actual->siguiente;
  }
  std::cout << std::endl;
}