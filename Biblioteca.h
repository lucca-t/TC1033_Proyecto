#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Libro.h"
#include "Miembro.h"
#include <vector>
#include <iostream>
using namespace std;

class Biblioteca {
private:
    vector<Libro> libros;        // Lista de libros en la biblioteca
    vector<Miembro> miembros;    // Lista de miembros de la biblioteca

public:
    Biblioteca() {
        cout << "Biblioteca creada sin libros iniciales." << endl;
    }

    // Constructor con lista de libros
    Biblioteca(vector<Libro> librosIniciales) : libros(librosIniciales) {
        cout << "Biblioteca creada con " << librosIniciales.size() << " libros iniciales." << endl;
    }


    // Método para añadir un libro a la biblioteca
    void agregarLibro(Libro libro) {
        libros.push_back(libro);
        cout << "Libro agregado: " << libro.getTitulo() << " por " << libro.getAutor() << endl;
    }

    // Método para registrar un miembro
    void registrarMiembro(Miembro miembro) {
        miembros.push_back(miembro);
        cout << "Miembro registrado: " << miembro.getNombre() << endl;
    }

    // Método para alquilar un libro a un miembro
    void alquilarLibro(const string& nombreMiembro, const string& isbnLibro) {
        // Buscar el miembro por nombre
        for (auto& miembro : miembros) {
            if (miembro.getNombre() == nombreMiembro) {
                // Buscar el libro por ISBN
                for (auto& libro : libros) {
                    if (libro.getIsbn() == isbnLibro) {
                        miembro.alquilarLibro(libro);
                        return;
                    }
                }
                cout << "No se encontró un libro con el ISBN proporcionado." << endl;
                return;
            }
        }
        cout << "No se encontró un miembro con el nombre proporcionado." << endl;
    }

    // Método para devolver un libro
    void devolverLibro(const string& nombreMiembro, const string& isbnLibro) {
        // Buscar el miembro por nombre
        for (auto& miembro : miembros) {
            if (miembro.getNombre() == nombreMiembro) {
                // Buscar el libro por ISBN
                for (auto& libro : libros) {
                    if (libro.getIsbn() == isbnLibro) {
                        miembro.devolverLibro(libro);
                        return;
                    }
                }
                cout << "No se encontró un libro con el ISBN proporcionado." << endl;
                return;
            }
        }
        cout << "No se encontró un miembro con el nombre proporcionado." << endl;
    }

    // Método para mostrar todos los libros en la biblioteca
    void mostrarLibros() const {
        cout << "Libros en la biblioteca:" << endl;
        for (Libro libro : libros) {
            cout << "Título: " << libro.getTitulo() 
                 << ", Autor: " << libro.getAutor() 
                 << ", ISBN: " << libro.getIsbn()
                 << ", Disponible: " << (libro.getEstaDisponible() ? "Sí" : "No") << endl;
        }
    }

    // Método para mostrar todos los miembros registrados
    void mostrarMiembros() const {
        cout << "Miembros de la biblioteca:" << endl;
        for (Miembro miembro : miembros) {
            miembro.mostrarDetalles();
            cout << "------------" << endl;
        }
    }
};

#endif