#include <iostream>
using namespace std;

#ifndef LIBRO_H
#define LIBRO_H

#include "LibraryItem.h"

class Libro : public LibraryItem
{
private:
    string ISBN;    // Numero de identifiacion 
    string autor;   // Quien escribio el libro
    string genero;  // Genero del libro

public:
    // Constructor
    Libro(string id, bool estaDisponible, string ISBN, string titulo, string autor, string genero)
        : LibraryItem(titulo, id, estaDisponible), ISBN(ISBN), autor(autor), genero(genero) {}
    // Getters 
    string getAutor()
    {
        return autor;
    }
    string getISBN()
    {
        return ISBN;
    }
    string getGenero(){
        return genero;
    }
    // Setters
    void setAutor(string autor){
        this->autor = autor;
    }
    void setGenero(string genero){
        this->genero = genero;
    }
    void setISBN(string ISBN){
        this->ISBN = ISBN;
    }
    // Mostrar todos los detalles del libro
    void mostrarDetallesLibro()
    {
        cout << "Titulo: " << titulo << "\n"
             << "Autor: " << autor << "\n"
             << "ISBN: " << ISBN << "\n"
             << "Género: " << genero << "\n"
             << "Disponible: " << (estaDisponible ? "Sí" : "No") << "\n";
    }
};

#endif // LIBRO_H
