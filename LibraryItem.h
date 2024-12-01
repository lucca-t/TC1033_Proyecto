#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H

#include <iostream>
using namespace std;

class LibraryItem {
protected:
    string id;               // Identificador único del ítem
    bool estaDisponible;     // Estado de disponibilidad del ítem
    string titulo;           // Título del ítem

public:
    // Constructor con parámetros
    LibraryItem(string titulo, string id, bool estaDisponible) {
        this->titulo = titulo;              // Asignar título al ítem
        this->id = id;                      // Asignar ID al ítem
        this->estaDisponible = estaDisponible; // Asignar disponibilidad al ítem
    }

    // Obtener el ID del ítem
    string getId() { 
        return id; 
    }

    // Obtener el estado de disponibilidad
    bool getDisponibilidad() { 
        return estaDisponible; 
    }

    // Establecer un nuevo ID para el ítem
    void setId(string newId) { 
        id = newId; 
    }

    // Establecer el estado de disponibilidad
    void setDisponibilidad(bool disponibilidad) { 
        this->estaDisponible = disponibilidad; 
    }

    // Marcar el ítem como alquilado (no disponible)
    void alquilarItem() {
        this->estaDisponible = false; // Cambiar disponibilidad a false
    }

    // Marcar el ítem como devuelto (disponible)
    void devolverItem() {
        this->estaDisponible = true; // Cambiar disponibilidad a true
    }

    // Establecer un nuevo título para el ítem
    void setTitulo(string titulo) { 
        this->titulo = titulo; 
    }

    // Obtener el título del ítem
    string getTitulo() { 
        return titulo; 
    }
};

#endif // LIBRARY_ITEM_H
