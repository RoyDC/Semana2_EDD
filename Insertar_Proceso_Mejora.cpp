#include <iostream>
#include <string>
#include <vector>
#include <cstddef> 
using namespace std;

struct Proceso {
    int id;
    string nombre;
    int prioridad;
};

struct NodoProceso {
    Proceso dato;
    NodoProceso* siguiente;
};

NodoProceso* listaProcesos = NULL;

// Ángel Goicochea - Lista Enlazada: insertar proceso


void insertarProceso(Proceso p) {
    NodoProceso* nuevo = new NodoProceso{p, NULL};
    if (!listaProcesos) {
        listaProcesos = nuevo;
    } else {
        NodoProceso* actual = listaProcesos;
        while (actual->siguiente)
            actual = actual->siguiente;
        actual->siguiente = nuevo;
    }
    cout << "[Angel] Proceso insertado en la lista enlazada.\n";
}

// Menú principal (fragmento) - Angel conecta insertarProceso


int main() {
    int opcion;
    do {
        cout << "\n====== MENU DEL SISTEMA ======\n";
        cout << "1. Insertar proceso\n";
        cout << "2. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            Proceso p;
            cout << "ID: "; cin >> p.id;
            cout << "Nombre: "; cin >> p.nombre;
            cout << "Prioridad: "; cin >> p.prioridad;
            insertarProceso(p);
        }

    } while (opcion != 2);

    cout << "Fin del programa.\n";
    return 0;
}
