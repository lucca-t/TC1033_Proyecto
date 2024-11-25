#ifndef MIEMBRO_H
#define MIEMBRO_H

#include "Libro.h"
#include "LibraryItem.h"
#include "Revista.h"
#include <vector>
#include <iostream>
using namespace std;

class Miembro {
private:
    string nombre;                // Nombre del miembro
    int edad;                     // Edad del miembro
    vector<Libro> librosPrestados;   // Libros que ha alquilado el miembro
    vector<Revista> revistasPrestadas; // Revistas que ha alquilado el miembro

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
        librosPrestados.push_back(libro);
        cout << nombre << " ha alquilado el libro: " << libro.getTitulo() << endl;
    }

    // Método para alquilar una revista
    void alquilarRevista(Revista revista) {
        revistasPrestadas.push_back(revista);
        cout << nombre << " ha alquilado la revista: " << revista.getTitulo() << endl;
    }

    // Método para devolver un libro
    void devolverLibro(Libro libro) {
        // Aquí buscamos y eliminamos el libro de la lista
        for (auto it = librosPrestados.begin(); it != librosPrestados.end(); ++it) {
            if (it->getId() == libro.getId()) {
                librosPrestados.erase(it);
                cout << nombre << " ha devuelto el libro: " << libro.getTitulo() << endl;
                return;
            }
        }
        cout << "No se encontró el libro: " << libro.getTitulo() << endl;
    }

    // Método para devolver una revista
    void devolverRevista(Revista revista) {
        // Aquí buscamos y eliminamos la revista de la lista
        for (auto it = revistasPrestadas.begin(); it != revistasPrestadas.end(); ++it) {
            if (it->getId() == revista.getId()) {
                revistasPrestadas.erase(it);
                cout << nombre << " ha devuelto la revista: " << revista.getTitulo() << endl;
                return;
            }
        }
        cout << "No se encontró la revista: " << revista.getTitulo() << endl;
    }

    // Mostrar los libros y revistas alquilados
    void mostrarItemsPrestados() {
        cout << "Libros prestados a " << nombre << ":" << endl;
        for (Libro libro : librosPrestados) {
            libro.mostrarDetallesLibro();
            cout << "------------" << endl;
        }

        cout << "Revistas prestadas a " << nombre << ":" << endl;
        for (Revista revista : revistasPrestadas) {
            revista.mostrarDetallesRevista();
            cout << "------------" << endl;
        }
    }

    void mostrarDetalles() const {
        cout << "Detalles del miembro:" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }
};

#endif
