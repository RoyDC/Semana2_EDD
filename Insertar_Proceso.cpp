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

// Angel Goicochea - Lista Enlazada: insertar proceso

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


