#ifndef MIEMBRO_H
#define MIEMBRO_H

#include "Libro.h"
#include <vector>
#include <iostream>
using namespace std;

class Miembro {
private:
    string nombre;               // Nombre del miembro
    int edad;

    vector<Libro> librosPrestados; // Libros que ha alquilado el miembro

public:
    // Constructor
    Miembro(string nombre, int edad) {
        this->nombre = nombre;
        this->edad = edad;
    }

    // Métodos Getters y Setters
    void setEdad(int edad) {
        this->edad = edad;
    }

    int getEdad() {
        return edad;
    }

    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    string getNombre() {
        return nombre;
    }

    // Método para alquilar un libro
    void alquilarLibro(Libro libro) {
        if (libro.getEstaDisponible()) {
            libro.alquilarLibro();
            librosPrestados.push_back(libro);
            cout << nombre << " ha alquilado '" << libro.getTitulo() << "'" << endl;
        } else {
            cout << "El libro '" << libro.getTitulo() << "' no está disponible para alquilar." << endl;
        }
    }

    // Método para devolver un libro
    void devolverLibro(Libro& libro) {
        // Buscar el libro en los libros prestados
        for (auto it = librosPrestados.begin(); it != librosPrestados.end(); ++it) {
            if (it->getIsbn() == libro.getIsbn()) {
                libro.devolverLibro();
                librosPrestados.erase(it);
                cout << nombre << " ha devuelto '" << libro.getTitulo() << "'" << endl;
                return;
            }
        }
        cout << "Este libro no ha sido alquilado por " << nombre << endl;
    }

    // Mostrar los libros alquilados
    void mostrarLibrosPrestados() const {
        cout << nombre << " ha alquilado los siguientes libros: " << endl;
        for (Libro libro : librosPrestados) {
            cout << "Título: " << libro.getTitulo() 
                 << ", Autor: " << libro.getAutor() 
                 << ", ISBN: " << libro.getIsbn() << endl;
        }
    }
    void mostrarDetalles() const {
        cout << "Detalles del miembro:" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }
};

#endif
