// Libro.h

#include <iostream>
using namespace std;

#ifndef LIBRO_H
#define LIBRO_H

#include "LibraryItem.h"


class Libro : public LibraryItem {
private:
    string ISBN;
    string autor;
    string genero;

public:
    Libro(string id, bool estaDisponible, string ISBN, string titulo, string autor, string genero)
        : LibraryItem(titulo, id, estaDisponible), ISBN(ISBN), autor(autor), genero(genero) {}

  
    string getAutor()  { return autor; }
    string getISBN()  { return ISBN; }

    void mostrarDetallesLibro() {
        cout << "Titulo: " << titulo << "\n"
                  << "Autor: " << autor << "\n"
                  << "ISBN: " << ISBN << "\n"
                  << "Género: " << genero << "\n"
                  << "Disponible: " << (estaDisponible ? "Sí" : "No") << "\n";
    }
};

#endif // LIBRO_H
