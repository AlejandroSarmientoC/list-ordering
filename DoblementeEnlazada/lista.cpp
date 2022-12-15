#pragma once

// .cpp file
#include "lista.h"

template <typename T>
Lista<T>::Lista() : primero(nullptr) {}

template <typename T>
Lista<T>::~Lista() {
  while (primero) {
    Nodo<T> *temp = primero;
    primero = primero->siguiente;
    delete temp;
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
  Nodo<T> *temp1 = primero;
  while (temp1) {
    Nodo<T> *temp2 = temp1->siguiente;
    Nodo<T> *menor = temp1;
    while (temp2) {
      if (temp2->cedula < menor->cedula) {
        menor = temp2;
      }
      temp2 = temp2->siguiente;
    }
    if(menor != temp1){
      int cedula = temp1->cedula;
      std::string nombre = temp1->nombre;
      std::string apellido = temp1->apellido;
      temp1->cedula = menor->cedula;
      temp1->nombre = menor->nombre;
      temp1->apellido = menor->apellido;
      menor->cedula = cedula;
      menor->nombre = nombre;
      menor->apellido = apellido;
    }
    temp1 = temp1->siguiente;
  }
}

template <typename T>
void Lista<T>::OrdenarPorApellido() {
  Nodo<T> *temp1 = primero;
  while (temp1) {
    Nodo<T> *temp2 = temp1->siguiente;
    Nodo<T> *menor = temp1;
    while (temp2) {
      if (temp2->apellido < menor->apellido) {
        menor = temp2;
      }
      temp2 = temp2->siguiente;
    }
    if(menor != temp1){
      int cedula = temp1->cedula;
      std::string nombre = temp1->nombre;
      std::string apellido = temp1->apellido;
      temp1->cedula = menor->cedula;
      temp1->nombre = menor->nombre;
      temp1->apellido = menor->apellido;
      menor->cedula = cedula;
      menor->nombre = nombre;
      menor->apellido = apellido;
    }
    temp1 = temp1->siguiente;
  }
}

template <typename T>
void Lista<T>::Mostrar() {
  Nodo<T> *temp = primero;
  while (temp) {
    std::cout << temp->cedula << " " << temp->nombre << " " << temp->apellido << std::endl;
    temp = temp->siguiente;
  }
}


