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
    // Constructor sin parametros
    Biblioteca() {
        cout << "Biblioteca creada sin objetos iniciales." << endl; // Mensaje de inicialización
    }

    // Constructor con lista de libros y revistas
    Biblioteca(vector<Libro> librosIniciales, vector<Revista> revistasIniciales) 
        : libros(librosIniciales), revistas(revistasIniciales) {
        cout << "Biblioteca creada con " << librosIniciales.size() << " libros y " 
             << revistasIniciales.size() << " revistas." << endl; // Mensaje de inicialización
    }

    // Método para añadir un libro a la biblioteca
    void agregarLibro(Libro libro) {
        libros.push_back(libro);    // Agregar libro a la lista
        cout << "Libro agregado: " << libro.getTitulo() << endl;    // Confirmación
    }

    // Método para añadir una revista a la biblioteca
    void agregarRevista(Revista revista) {
        revistas.push_back(revista); // Agregar revista a la lista
        cout << "Revista agregada: " << revista.getTitulo() << endl; // Confirmación
    }

    // Método para registrar un miembro
    void registrarMiembro(Miembro miembro) {
        miembros.push_back(miembro); // Agregar miembro a la lista
        cout << "Miembro registrado: " << miembro.getNombre() << endl; // Confirmación
    }

    // Método para alquilar un libro a un miembro
    void alquilarLibro(Miembro& miembro, string id) {
        for (Libro& libro : libros) {
            if (libro.getId() == id) {  // Comprobar si el ID coincide
                if (libro.getDisponibilidad()) {
                    miembro.alquilarLibro(libro);   // Agregar el libro como alquilado al miembro
                    libro.alquilarItem();          // Marcar el libro como no disponible
                    cout << "Libro '" << libro.getTitulo() << "' alquilado a " << miembro.getNombre() << endl;
                    return;
                } else {
                    cout << "El libro '" << libro.getTitulo() << "' no está disponible." << endl; // Mensaje de error
                    return;
                }
            }
        }
        cout << "No se encontró un libro con el ID: " << id << endl; // Mensaje de error si no se encuentra
    }

    // Método para alquilar una revista a un miembro
    void alquilarRevista(Miembro& miembro, string id) {
        for (Revista& revista : revistas) {
            if (revista.getId() == id) {    // Comprobar si el ID coincide
                if (revista.getDisponibilidad()) {
                    miembro.alquilarRevista(revista); // Agregar la revista como alquilada al miembro
                    revista.alquilarItem();          // Marcar la revista como no disponible
                    cout << "Revista '" << revista.getTitulo() << "' alquilada a " << miembro.getNombre() << endl;
                    return;
                } else {
                    cout << "La revista '" << revista.getTitulo() << "' no está disponible." << endl; // Mensaje de error
                    return;
                }
            }
        }
        cout << "No se encontró una revista con el ID: " << id << endl; // Mensaje de error si no se encuentra
    }

    // Método para devolver un libro
    void devolverLibro(Miembro& miembro, string id) {
        for (Libro& libro : libros) {   
            if (libro.getId() == id) {  // Comprobar si el ID coincide
                miembro.devolverLibro(libro); // Quitar el libro de la lista de alquilados del miembro
                libro.devolverItem();         // Marcar el libro como disponible
                cout << "Libro '" << libro.getTitulo() << "' devuelto por " << miembro.getNombre() << endl;
                return;
            }
        }
        cout << "No se encontró un libro con el ID: " << id << endl; // Mensaje de error si no se encuentra
    }

    // Método para devolver una revista
    void devolverRevista(Miembro& miembro, string id) {
        for (Revista& revista : revistas) { 
            if (revista.getId() == id) {    // Comprobar si el ID coincide
                miembro.devolverRevista(revista); // Quitar la revista de la lista de alquilados del miembro
                revista.devolverItem();          // Marcar la revista como disponible
                cout << "Revista '" << revista.getTitulo() << "' devuelta por " << miembro.getNombre() << endl;
                return;
            }
        }
        cout << "No se encontró una revista con el ID: " << id << endl; // Mensaje de error si no se encuentra
    }

    // Método para mostrar todos los libros en la biblioteca
    void mostrarLibros() const {
        cout << "Libros en la biblioteca:" << endl;
        for (Libro libro : libros) { // Iterar por todos los libros
            libro.mostrarDetallesLibro(); // Mostrar detalles del libro
        }
    }

    // Método para mostrar todas las revistas en la biblioteca
    void mostrarRevistas() const {
        cout << "Revistas en la biblioteca:" << endl;
        for (Revista revista : revistas) { // Iterar por todas las revistas
            revista.mostrarDetallesRevista(); // Mostrar detalles de la revista
        }
    }

    // Método para mostrar todos los miembros registrados
    void mostrarMiembros() const {
        cout << "Miembros de la biblioteca:" << endl;
        for (const Miembro& miembro : miembros) { // Iterar por todos los miembros
            miembro.mostrarDetalles();           // Mostrar detalles del miembro
            cout << "------------" << endl;
        }
    }

    // Método para mostrar todos los libros y revistas en la biblioteca
    void mostrarItems() {
        cout << "Libros en la biblioteca:" << endl;
        for (Libro libro : libros) { // Iterar por todos los libros
            libro.mostrarDetallesLibro(); // Mostrar detalles del libro
            cout << "------------" << endl;
        }
        cout << "Revistas en la biblioteca:" << endl;
        for (Revista revista : revistas) { // Iterar por todas las revistas
            revista.mostrarDetallesRevista(); // Mostrar detalles de la revista
            cout << "------------" << endl;
        }
    }

    // Getter para la lista de libros
    vector<Libro> getLibros() const {
        return libros;
    }

    // Getter para la lista de revistas
    vector<Revista> getRevistas() const {
        return revistas;
    }
};

#endif
