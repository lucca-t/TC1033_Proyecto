#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
using namespace std;

class Libro {
private:
    string titulo;       // Título del libro
    string autor;        // Autor del libro
    string isbn;         // Número ISBN del libro
    bool estaDisponible; // Indica si el libro está disponible para prestar

public:
    // Constructor
    Libro(string titulo, string autor, string isbn) {
        this->titulo = titulo;
        this->autor = autor;
        this->isbn = isbn;
        this->estaDisponible = true;  // Por defecto, el libro está disponible
    }

    // Métodos Getters
    // Métodos Getters
    string getTitulo() { return titulo; }
    string getAutor() { return autor; }
    string getIsbn() { return isbn; }
    bool getEstaDisponible() { return estaDisponible; }

    // Métodos Setters
    void setTitulo(string titulo) { this->titulo = titulo; }
    void setAutor(string autor) { this->autor = autor; }
    void setIsbn(string isbn) { this->isbn = isbn; }
    void setEstaDisponible(bool estaDisponible) { this->estaDisponible = estaDisponible; }

    // Método para verificar disponibilidad

        // Método para alquilar un libro
    void alquilarLibro() {
        if (estaDisponible) {
            estaDisponible = false;
        } else {
            cout << "El libro '" << titulo << "' ya está alquilado." << endl;
        }
    }
    void devolverLibro() {
        estaDisponible = true;
    }

    // Método para mostrar los detalles del libro (lo definiremos más adelante)
    void mostrarDetallesLibro() const {
        cout << "Título: " << titulo << ", Autor: " << autor << ", ISBN: " << isbn;
        if (estaDisponible)
            cout << " (Disponible)" << endl;
        else
            cout << " (No disponible)" << endl;
    }
};

#endif
