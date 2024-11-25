#include <iostream>
using namespace std;

#ifndef REVISTA_H
#define REVISTA_H

#include "LibraryItem.h"



class Revista : public LibraryItem {
private:
    string editor;
    string edicion;

public:
    Revista(string id, bool estaDisponible, string titulo, string edicion, string editor)
        : LibraryItem(titulo, id, estaDisponible), editor(editor), edicion(edicion){}

    void mostrarDetallesRevista()  {
        cout << "Revista: " << titulo << " Edicion: " << edicion << " | Editor: " << editor;
        cout << (getDisponibilidad() ? " (Disponible)" : " (No disponible)") << endl;
    }

    string getEditor(){return editor;}
    string getEdicion(){return edicion;}

    
    void setEditor(string editor){ this-> editor = editor;}
    void setEdicion(string edicion){ this-> edicion = edicion;}
};

#endif