#include <iostream>
using namespace std;

// Definición del nodo
template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;

    Nodo(T valor) : dato(valor), siguiente(nullptr) {}
};

// Definición de la lista circular simple
template <typename T>
class ListaCircular {
private:
    Nodo<T>* head;

public:
    ListaCircular() : head(nullptr) {}

    // Método para agregar un nodo al final de la lista
    void agregar(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        if (!head) {
            head = nuevoNodo;
            head->siguiente = head;  // Enlazamos a sí mismo (único nodo)
        } else {
            Nodo<T>* temp = head;
            while (temp->siguiente != head) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
            nuevoNodo->siguiente = head;  // Último nodo apunta al primero
        }
    }

    // Método para mostrar los elementos de la lista
    void mostrar() {
        if (!head) {
            cout << "La lista está vacía." << endl;
            return;
        }
        Nodo<T>* temp = head;
        do {
            cout << temp->dato << " -> ";
            temp = temp->siguiente;
        } while (temp != head);
        cout << "(circular)" << endl;
    }

    // Método para buscar un elemento en la lista
    bool buscar(T valor) {
        if (!head) return false;
        Nodo<T>* temp = head;
        do {
            if (temp->dato == valor) return true;
            temp = temp->siguiente;
        } while (temp != head);
        return false;
    }

    // Método para eliminar un nodo con un valor dado
    void eliminar(T valor) {
        if (!head) return;

        Nodo<T>* temp = head;
        Nodo<T>* anterior = nullptr;

        // Caso especial: si el nodo a eliminar es el primero
        if (head->dato == valor) {
            if (head->siguiente == head) {
                delete head;  // Si es el único nodo
                head = nullptr;
            } else {
                // Encontrar el último nodo
                while (temp->siguiente != head) {
                    temp = temp->siguiente;
                }
                Nodo<T>* eliminarNodo = head;
                temp->siguiente = head->siguiente;
                head = head->siguiente;
                delete eliminarNodo;
            }
            return;
        }

        // Buscar el nodo a eliminar
        do {
            anterior = temp;
            temp = temp->siguiente;
            if (temp->dato == valor) {
                anterior->siguiente = temp->siguiente;
                delete temp;
                return;
            }
        } while (temp != head);
    }

    // Destructor para liberar memoria
    ~ListaCircular() {
        if (!head) return;
        Nodo<T>* temp = head;
        do {
            Nodo<T>* siguiente = temp->siguiente;
            delete temp;
            temp = siguiente;
        } while (temp != head);
        head = nullptr;
    }
};

// Ejemplo de uso
int main() {
    ListaCircular<int> lista;

    // Agregar elementos a la lista
    lista.agregar(10);
    lista.agregar(20);
    lista.agregar(30);
    lista.agregar(40);

    // Mostrar la lista
    cout << "Lista Circular: ";
    lista.mostrar();

    // Buscar un elemento
    int buscarElemento = 20;
    if (lista.buscar(buscarElemento)) {
        cout << "Elemento " << buscarElemento << " encontrado en la lista." << endl;
    } else {
        cout << "Elemento " << buscarElemento << " no encontrado en la lista." << endl;
    }

    // Eliminar un elemento
    lista.eliminar(30);
    cout << "Lista después de eliminar 30: ";
    lista.mostrar();

    return 0;
}
