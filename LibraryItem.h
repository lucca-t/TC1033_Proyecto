
#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H

#include <iostream>
using namespace std;

class LibraryItem {
protected:
    string id;
    bool estaDisponible;
    string titulo;

public:
    LibraryItem(string titulo, string id, bool estaDisponible) {
            this->titulo = titulo;
            this->id = id;
            this->estaDisponible = estaDisponible;
        }

    string getId()  { return id; }
    bool getDisponibilidad()  { return estaDisponible; }

    void setId(string newId) { id = newId; }
    void setDisponibilidad(bool disponibilidad) { estaDisponible = disponibilidad; }

    void alquilarItem(){
        this-> estaDisponible = false;
    }; 
    void devolverItem(){
        this-> estaDisponible = true;
    };


    void setTitulo(string titulo){this->titulo = titulo;}
    string getTitulo(){return titulo;}

};

#endif // LIBRARY_ITEM_H
