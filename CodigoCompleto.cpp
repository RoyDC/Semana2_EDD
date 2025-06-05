#include <iostream>
#include <string>
using namespace std;

// ---------------- ESTRUCTURAS ----------------

struct Proceso {
    int id;
    string nombre;
    int prioridad;
    int memoria;
};

struct Nodo {
    Proceso dato;
    Nodo* sig;
};

struct NodoMemoria {
    int bloque;
    NodoMemoria* sig;
};

struct NodoCola {
    Proceso dato;
    NodoCola* sig;
};

// ---------------- VARIABLES GLOBALES ----------------

Nodo* lista = NULL;
NodoMemoria* pila = NULL;
NodoCola* frente = NULL;
NodoCola* fin = NULL;

// ---------------- FUNCIONES DE LISTA ----------------

void insertarProceso() {
    Nodo* nuevo = new Nodo();

    cout << "Ingrese ID del proceso: ";
    cin >> nuevo->dato.id;
    if (nuevo->dato.id < 0) {
        cout << "ID invalido. Debe ser positivo.\n";
        return;
    }

    cout << "Ingrese nombre del proceso: ";
    cin >> nuevo->dato.nombre;

    cout << "Ingrese prioridad del proceso (1 = Alta): ";
    cin >> nuevo->dato.prioridad;
    if (nuevo->dato.prioridad < 0) {
        cout << "Prioridad invalida. Debe ser positiva.\n";
        return;
    }

    cout << "Ingrese cantidad de memoria requerida: ";
    cin >> nuevo->dato.memoria;
    if (nuevo->dato.memoria < 0) {
        cout << "Memoria invalida. Debe ser positiva.\n";
        return;
    }

    nuevo->sig = NULL;

    if (lista == NULL) {
        lista = nuevo;
    } else {
        Nodo* aux = lista;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }

    cout << "Proceso agregado correctamente.\n";
}

void mostrarProcesos() {
    Nodo* aux = lista;
    cout << "\n--- LISTA DE PROCESOS ---\n";
    while (aux != NULL) {
        cout << "ID: " << aux->dato.id
             << " Nombre: " << aux->dato.nombre
             << " Prioridad: " << aux->dato.prioridad
             << " Memoria: " << aux->dato.memoria << "\n";
        aux = aux->sig;
    }
}

void buscarProceso() {
    int id;
    cout << "Ingrese ID del proceso a buscar: ";
    cin >> id;
    if (id < 0) {
        cout << "ID invalido. Debe ser positivo.\n";
        return;
    }

    Nodo* aux = lista;
    while (aux != NULL) {
        if (aux->dato.id == id) {
            cout << "Proceso encontrado: " << aux->dato.nombre << "\n";
            return;
        }
        aux = aux->sig;
    }
    cout << "Proceso no encontrado.\n";
}

void actualizarPrioridad() {
    int id, nueva;
    cout << "Ingrese ID del proceso a actualizar: ";
    cin >> id;
    if (id < 0) {
        cout << "ID invalido. Debe ser positivo.\n";
        return;
    }

    cout << "Ingrese nueva prioridad: ";
    cin >> nueva;
    if (nueva < 0) {
        cout << "Prioridad invalida. Debe ser positiva.\n";
        return;
    }

    Nodo* aux = lista;
    while (aux != NULL) {
        if (aux->dato.id == id) {
            aux->dato.prioridad = nueva;
            cout << "Prioridad actualizada correctamente.\n";
            return;
        }
        aux = aux->sig;
    }
    cout << "Proceso no encontrado.\n";
}

void intercambiar(Proceso &a, Proceso &b) {
    Proceso temp = a;
    a = b;
    b = temp;
}

void ordenarPorPrioridad() {
    Nodo* i = lista;
    while (i != NULL) {
        Nodo* j = i->sig;
        while (j != NULL) {
            if (i->dato.prioridad > j->dato.prioridad) {
                intercambiar(i->dato, j->dato);
            }
            j = j->sig;
        }
        i = i->sig;
    }
    cout << "Lista ordenada por prioridad.\n";
}

// ---------------- FUNCIONES DE PILA ----------------

void asignarMemoria() {
    NodoMemoria* nuevo = new NodoMemoria();
    cout << "Ingrese bloque de memoria: ";
    cin >> nuevo->bloque;
    if (nuevo->bloque < 0) {
        cout << "Bloque invalido. Debe ser positivo.\n";
        return;
    }

    nuevo->sig = pila;
    pila = nuevo;
    cout << "Bloque asignado.\n";
}

void liberarMemoria() {
    if (pila == NULL) {
        cout << "No hay memoria asignada.\n";
        return;
    }
    cout << "Bloque liberado: " << pila->bloque << "\n";
    NodoMemoria* temp = pila;
    pila = pila->sig;
    delete temp;
}

void mostrarMemoria() {
    NodoMemoria* aux = pila;
    cout << "Bloques de memoria (pila): ";
    while (aux != NULL) {
        cout << aux->bloque << " ";
        aux = aux->sig;
    }
    cout << "\n";
}

// ---------------- FUNCIONES DE COLA (CPU) ----------------

void encolarProcesoCPU() {
    NodoCola* nuevo = new NodoCola();

    cout << "Ingrese ID del proceso: ";
    cin >> nuevo->dato.id;
    if (nuevo->dato.id < 0) {
        cout << "ID inv?lido.\n";
        return;
    }

    cout << "Ingrese nombre del proceso: ";
    cin >> nuevo->dato.nombre;

    cout << "Ingrese prioridad: ";
    cin >> nuevo->dato.prioridad;
    if (nuevo->dato.prioridad < 0) {
        cout << "Prioridad invalida.\n";
        return;
    }

    cout << "Ingrese memoria: ";
    cin >> nuevo->dato.memoria;
    if (nuevo->dato.memoria < 0) {
        cout << "Memoria invalida.\n";
        return;
    }

    nuevo->sig = NULL;

    if (frente == NULL) {
        frente = fin = nuevo;
    } else {
        fin->sig = nuevo;
        fin = nuevo;
    }

    cout << "Proceso encolado a la CPU.\n";
}

void desencolarProcesoCPU() {
    if (frente == NULL) {
        cout << "La cola est? vac?a.\n";
        return;
    }
    cout << "Ejecutando proceso: " << frente->dato.nombre << "\n";
    NodoCola* temp = frente;
    frente = frente->sig;
    delete temp;
    if (frente == NULL) {
        fin = NULL;
    }
}

void mostrarColaCPU() {
    NodoCola* aux = frente;
    cout << "Cola de procesos (CPU):\n";
    while (aux != NULL) {
        cout << "ID: " << aux->dato.id
             << ", Nombre: " << aux->dato.nombre
             << ", Prioridad: " << aux->dato.prioridad
             << ", Memoria: " << aux->dato.memoria << "\n";
        aux = aux->sig;
    }
}

// ---------------- MENU PRINCIPAL ----------------

int main() {
    int opcion;
    do {
        cout << "\n--- SISTEMA DE GESTION DE PROCESOS ---\n";
        cout << "1. Insertar proceso (lista)\n";
        cout << "2. Mostrar procesos (lista)\n";
        cout << "3. Buscar proceso por ID (lista)\n";
        cout << "4. Actualizar prioridad (lista)\n";
        cout << "5. Ordenar por prioridad (lista)\n";
        cout << "6. Asignar bloque de memoria (pila)\n";
        cout << "7. Liberar bloque de memoria (pila)\n";
        cout << "8. Mostrar memoria (pila)\n";
        cout << "9. Encolar proceso en CPU (cola)\n";
        cout << "10. Ejecutar proceso CPU (desencolar)\n";
        cout << "11. Mostrar cola CPU\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: insertarProceso(); break;
            case 2: mostrarProcesos(); break;
            case 3: buscarProceso(); break;
            case 4: actualizarPrioridad(); break;
            case 5: ordenarPorPrioridad(); break;
            case 6: asignarMemoria(); break;
            case 7: liberarMemoria(); break;
            case 8: mostrarMemoria(); break;
            case 9: encolarProcesoCPU(); break;
            case 10: desencolarProcesoCPU(); break;
            case 11: mostrarColaCPU(); break;
            case 0: cout << "Saliendo del programa...\n"; break;
            default: cout << "Opcion no valida.\n";
        }
    } while (opcion != 0);

    return 0;
}
