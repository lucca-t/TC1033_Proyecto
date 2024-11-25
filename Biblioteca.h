#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Libro.h"
#include "Revista.h"
#include "Miembro.h"
#include <vector>
#include <iostream>
using namespace std;

class Biblioteca {
private:
    vector<Libro> libros;        // Lista de libros en la biblioteca
    vector<Revista> revistas;    // Lista de revistas en la biblioteca
    vector<Miembro> miembros;    // Lista de miembros de la biblioteca

public:
    Biblioteca() {
        cout << "Biblioteca creada sin objetos iniciales." << endl;
    }

    // Constructor con lista de libros y revistas
    Biblioteca(vector<Libro> librosIniciales, vector<Revista> revistasIniciales) 
        : libros(librosIniciales), revistas(revistasIniciales) {
        cout << "Biblioteca creada con " << librosIniciales.size() << " libros y " 
             << revistasIniciales.size() << " revistas." << endl;
    }

    // Método para añadir un libro a la biblioteca
    void agregarLibro(Libro libro) {
        libros.push_back(libro);
        cout << "Libro agregado: " << libro.getTitulo() << endl;
    }

    // Método para añadir una revista a la biblioteca
    void agregarRevista(Revista revista) {
        revistas.push_back(revista);
        cout << "Revista agregada: " << revista.getTitulo() << endl;
    }

    // Método para registrar un miembro
    void registrarMiembro(Miembro miembro) {
        miembros.push_back(miembro);
        cout << "Miembro registrado: " << miembro.getNombre() << endl;
    }

    // Método para alquilar un libro a un miembro
    void alquilarLibro(Miembro& miembro, string id) {
        for (Libro& libro : libros) {
            if (libro.getId() == id) {
                if (libro.getDisponibilidad()) {
                    miembro.alquilarLibro(libro);
                    libro.alquilarItem();
                    cout << "Libro '" << libro.getTitulo() << "' alquilado a " << miembro.getNombre() << endl;
                    return;
                } else {
                    cout << "El libro '" << libro.getTitulo() << "' no está disponible." << endl;
                    return;
                }
            }
        }
        cout << "No se encontró un libro con el ID: " << id << endl;
    }

    // Método para alquilar una revista a un miembro
    void alquilarRevista(Miembro& miembro, string id) {
        for (Revista& revista : revistas) {
            if (revista.getId() == id) {
                if (revista.getDisponibilidad()) {
                    miembro.alquilarRevista(revista);
                    revista.alquilarItem();
                    cout << "Revista '" << revista.getTitulo() << "' alquilada a " << miembro.getNombre() << endl;
                    return;
                } else {
                    cout << "La revista '" << revista.getTitulo() << "' no está disponible." << endl;
                    return;
                }
            }
        }
        cout << "No se encontró una revista con el ID: " << id << endl;
    }

    // Método para devolver un libro
    void devolverLibro(Miembro& miembro, string id) {
        for (Libro& libro : libros) {
            if (libro.getId() == id) {
                miembro.devolverLibro(libro);
                libro.devolverItem();
                cout << "Libro '" << libro.getTitulo() << "' devuelto por " << miembro.getNombre() << endl;
                return;
            }
        }
        cout << "No se encontró un libro con el ID: " << id << endl;
    }

    // Método para devolver una revista
    void devolverRevista(Miembro& miembro, string id) {
        for (Revista& revista : revistas) {
            if (revista.getId() == id) {
                miembro.devolverRevista(revista);
                revista.devolverItem();
                cout << "Revista '" << revista.getTitulo() << "' devuelta por " << miembro.getNombre() << endl;
                return;
            }
        }
        cout << "No se encontró una revista con el ID: " << id << endl;
    }

    // Método para mostrar todos los libros en la biblioteca
    void mostrarLibros() const {
        cout << "Libros en la biblioteca:" << endl;
        for (Libro libro : libros) {
            libro.mostrarDetallesLibro();
        }
    }

    // Método para mostrar todas las revistas en la biblioteca
    void mostrarRevistas() const {
        cout << "Revistas en la biblioteca:" << endl;
        for (Revista revista : revistas) {
            revista.mostrarDetallesRevista();
        }
    }

    // Método para mostrar todos los miembros registrados
    void mostrarMiembros() const {
        cout << "Miembros de la biblioteca:" << endl;
        for (const Miembro& miembro : miembros) {
            miembro.mostrarDetalles();
            cout << "------------" << endl;
        }
    }
    void mostrarItems() {
        cout << "Libros en la biblioteca" << endl;
        for (Libro libro : libros) {
            libro.mostrarDetallesLibro();
            cout << "------------" << endl;
        }
        cout << "------------" << endl;

        cout << "Revistas en la biblioteca" << endl;
        for (Revista revista : revistas) {
            revista.mostrarDetallesRevista();
            cout << "------------" << endl;
        }
    }

    //Getter para lista de libros
    vector<Libro> getLibros() const {
    return libros;
    }
    //Getter para lista de revistas
    vector<Revista> getRevistas() const {
        return revistas;
    }


};

#endif
