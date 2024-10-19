#include <iostream>
using namespace std;

// Definición del nodo de la lista enlazada
//Nodo: Se define la estructura del nodo con un campo de dato (int dato) y un puntero al siguiente nodo (Nodo* siguiente).
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Función para insertar un nodo al inicio de la lista
void insertarInicio(Nodo*& cabeza, int valor) {
    Nodo* nuevoNodo = new Nodo(); // Crear un nuevo nodo
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = cabeza; // El nuevo nodo apunta al nodo actual
    cabeza = nuevoNodo;            // Actualizar la cabeza de la lista
}

// Función para imprimir la lista
void imprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    cout << "NULL" << endl;
}

int main() {
    Nodo* lista = nullptr; // Inicializar la lista vacía

    // Insertar algunos elementos
    insertarInicio(lista, 10);
    insertarInicio(lista, 20);
    insertarInicio(lista, 30);

    // Imprimir la lista
    imprimirLista(lista);

    return 0;
}
