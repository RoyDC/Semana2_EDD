
// ---------------- FUNCIONES DE COLA (CPU) ----------------

// Función para encolar un proceso a la CPU
void encolarProcesoCPU() {
    NodoCola* nuevo = new NodoCola();  // Se crea un nuevo nodo para el proceso

    // Solicita y valida el ID del proceso
    cout << "Ingrese ID del proceso: ";
    cin >> nuevo->dato.id;
    if (nuevo->dato.id < 0) {
        cout << "ID inválido.\n";
        return;
    }

    // Solicita el nombre del proceso
    cout << "Ingrese nombre del proceso: ";
    cin >> nuevo->dato.nombre;

    // Solicita y valida la prioridad del proceso
    cout << "Ingrese prioridad: ";
    cin >> nuevo->dato.prioridad;
    if (nuevo->dato.prioridad < 0) {
        cout << "Prioridad inválida.\n";
        return;
    }

    // Solicita y valida la memoria requerida por el proceso
    cout << "Ingrese memoria: ";
    cin >> nuevo->dato.memoria;
    if (nuevo->dato.memoria < 0) {
        cout << "Memoria inválida.\n";
        return;
    }

    nuevo->sig = NULL;  // El siguiente del nuevo nodo apunta a NULL

    // Si la cola está vacía, el nuevo nodo será el frente y el fin
    if (frente == NULL) {
        frente = fin = nuevo;
    } else {
        // Si no, se agrega al final de la cola
        fin->sig = nuevo;
        fin = nuevo;
    }

    cout << "Proceso encolado a la CPU.\n";
}

// Función para desencolar (ejecutar) un proceso de la CPU
void desencolarProcesoCPU() {
    if (frente == NULL) {
        // Si la cola está vacía, se informa al usuario
        cout << "La cola está vacía.\n";
        return;
    }

    // Se muestra el proceso que se va a ejecutar
    cout << "Ejecutando proceso: " << frente->dato.nombre << "\n";

    // Se elimina el proceso del frente de la cola
    NodoCola* temp = frente;
    frente = frente->sig;
    delete temp;

    // Si la cola quedó vacía, se actualiza el puntero fin
    if (frente == NULL) {
        fin = NULL;
    }
}

// Función para mostrar todos los procesos en la cola de la CPU
void mostrarColaCPU() {
    NodoCola* aux = frente;
    cout << "Cola de procesos (CPU):\n";
    while (aux != NULL) {
        // Muestra los datos de cada proceso en la cola
        cout << "ID: " << aux->dato.id
             << ", Nombre: " << aux->dato.nombre
             << ", Prioridad: " << aux->dato.prioridad
             << ", Memoria: " << aux->dato.memoria << "\n";
        aux = aux->sig;
    }
}

// ---------------- MENÚ PRINCIPAL ----------------

int main() {
    int opcion;

    // Menú principal con ciclo do-while para gestionar múltiples operaciones
    do {
        cout << "\n--- SISTEMA DE GESTIÓN DE PROCESOS ---\n";
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
        cout << "Seleccione una opción: ";
        cin >> opcion;

        // Estructura switch para ejecutar la opción seleccionada
        switch(opcion) {
            case 1: insertarProceso(); break;         // Función para insertar en lista (no incluida aquí)
            case 2: mostrarProcesos(); break;         // Función para mostrar lista
            case 3: buscarProceso(); break;           // Buscar proceso por ID
            case 4: actualizarPrioridad(); break;     // Actualizar prioridad en lista
            case 5: ordenarPorPrioridad(); break;     // Ordenar lista por prioridad
            case 6: asignarMemoria(); break;          // Asignar memoria con pila
            case 7: liberarMemoria(); break;          // Liberar memoria con pila
            case 8: mostrarMemoria(); break;          // Mostrar bloques de memoria
            case 9: encolarProcesoCPU(); break;       // Encolar proceso en la cola de CPU
            case 10: desencolarProcesoCPU(); break;   // Ejecutar (desencolar) proceso de CPU
            case 11: mostrarColaCPU(); break;         // Mostrar todos los procesos en cola de CPU
            case 0: cout << "Saliendo del programa...\n"; break;
            default: cout << "Opción no válida.\n";    // Mensaje para opción incorrecta
        }

    } while (opcion != 0); // El menú se repite hasta que el usuario elija salir

    return 0;
}
