#pragma once

#include <iostream>

using namespace std;

struct Node {
  int cedula;
  string nombre;
  string apellido;
  Node *next;
  Node *prev;
};

class CircularDoublyLinkedList {
  private:
    Node *head;

  public:
    CircularDoublyLinkedList() {
      head = NULL;
    }

    void insert(int cedula, string nombre, string apellido) {
      Node *newNode = new Node;
      newNode->cedula = cedula;
      newNode->nombre = nombre;
      newNode->apellido = apellido;

      if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
      } else {
        Node *current = head;
        while (current->next != head) {
          current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        newNode->next = head;
        head->prev = newNode;
      }
    }

    void show() {
      Node *current = head;
      do {
        cout << "Cedula: " << current->cedula << endl;
        cout << "Nombre: " << current->nombre << endl;
        cout << "Apellido: " << current->apellido << endl;
        current = current->next;
      } while (current != head);
    }

    void sortByCedula() {
      Node *current = head;
      Node *index;
      int tempCedula;
      string tempNombre;
      string tempApellido;

      if (head == NULL) {
        return;
      }

      do {
        index = current->next;

        while (index != head) {
          if (current->cedula > index->cedula) {
            tempCedula = current->cedula;
            tempNombre = current->nombre;
            tempApellido = current->apellido;

            current->cedula = index->cedula;
            current->nombre = index->nombre;
            current->apellido = index->apellido;

            index->cedula = tempCedula;
            index->nombre = tempNombre;
            index->apellido = tempApellido;
          }

          index = index->next;
        }

        current = current->next;
      } while (current != head);
    }

    void sortByApellido() {
      Node *current = head;
      Node *index;
      int tempCedula;
      string tempNombre;
      string tempApellido;

      if (head == NULL) {
        return;
      }

      do {
        index = current->next;

        while (index != head) {
          if (current->apellido > index->apellido) {
            tempCedula = current->cedula;
            tempNombre = current->nombre;
            tempApellido = current->apellido;

            current->cedula = index->cedula;
            current->nombre = index->nombre;
            current->apellido = index->apellido;

            index->cedula = tempCedula;
            index->nombre = tempNombre;
            index->apellido = tempApellido;
          }

          index = index->next;
        }

        current = current->next;
      } while (current != head);
    }
};
