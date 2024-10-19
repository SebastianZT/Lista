#include <iostream>

// Estructura para un nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Función para agregar un nodo al final de la lista
void agregarNodo(Nodo*& cabeza, int valor) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;

    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
    } else {
        Nodo* temp = cabeza;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

// Función para eliminar el primer nodo de la lista
void eliminarPrimero(Nodo*& cabeza) {
    if (cabeza != nullptr) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

// Función para imprimir los elementos de la lista
void imprimirLista(Nodo* cabeza) {
    Nodo* temp = cabeza;
    while (temp != nullptr) {
        std::cout << temp->dato << " ";
        temp = temp->siguiente;
    }
    std::cout << std::endl;
}

// Función para liberar la memoria de todos los nodos de la lista
void liberarLista(Nodo*& cabeza) {
    while (cabeza != nullptr) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

int main() {
    // Declaración de la lista usando nodos
    Nodo* miLista = nullptr;

    // Agregar elementos a la lista
    agregarNodo(miLista, 10);
    agregarNodo(miLista, 20);
    agregarNodo(miLista, 30);

    // Imprimir los elementos de la lista
    std::cout << "Elementos de la lista: ";
    imprimirLista(miLista);

    // Eliminar el primer elemento de la lista
    eliminarPrimero(miLista);

    // Imprimir nuevamente los elementos de la lista
    std::cout << "Elementos de la lista despues de eliminar el primero: ";
    imprimirLista(miLista);

    // Liberar la memoria utilizada por la lista
    liberarLista(miLista);

    return 0;
}


/*#include <iostream>
#include <list>

int main() {
    // Declaración de una lista de enteros
    std::list<int> miLista;

    // Agregar elementos a la lista
    miLista.push_back(10);
    miLista.push_back(20);
    miLista.push_back(30);

    // Imprimir los elementos de la lista
    std::cout << "Elementos de la lista: ";
    for (int elemento : miLista) {
        std::cout << elemento << " ";
    }

    std::cout << std::endl;

    // Encontrar y eliminar el elemento 20
    for (auto it = miLista.begin(); it != miLista.end(); ++it) {
        if (*it == 20) {
            miLista.erase(it);
            break;  // Salimos del bucle después de eliminar el elemento
        }
    }

    // Imprimir los elementos de la lista después de eliminar el 20
    std::cout << "Elementos de la lista después de eliminar el 20: ";
    for (int elemento : miLista) {
        std::cout << elemento << " ";
    }

    return 0;
}
*/