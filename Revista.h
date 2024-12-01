#ifndef REVISTA_H
#define REVISTA_H

#include "LibraryItem.h"  // Herencia de LibraryItem

#include <iostream>
using namespace std;

class Revista : public LibraryItem  // Extendiendo LibraryItem
{
private:
    string editor;      // Nombre del editor de la revista
    string edicion;     // Nombre de la edicion

public:
    // Constructor
    Revista(string id, bool estaDisponible, string titulo, string edicion, string editor)
        : LibraryItem(titulo, id, estaDisponible), editor(editor), edicion(edicion) {}

    // Getters
    string getEditor()
    {
        return editor;
    }
    string getEdicion()
    {
        return edicion;
    }
    // Setters
    void setEditor(string editor)
    {
        this->editor = editor;
    }
    void setEdicion(string edicion)
    {
        this->edicion = edicion;
    }

    // Mostrar toda la informacion
    void mostrarDetallesRevista()
    {
        cout << "Revista: " << titulo << " Edicion: " << edicion << " | Editor: " << editor;    // Incluir toda la informacion
        cout << (getDisponibilidad() ? " (Disponible)" : " (No disponible)") << endl;           // Checar y desplegar disponibilidad
    }

};

#endif