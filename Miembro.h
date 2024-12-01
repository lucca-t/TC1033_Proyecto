#ifndef MIEMBRO_H
#define MIEMBRO_H

#include "Libro.h" // Importando archivos necesarios
#include "LibraryItem.h"
#include "Revista.h"

#include <vector>
#include <iostream>
using namespace std;

class Miembro
{
private:
    string nombre;                     // Nombre del miembro
    int edad;                          // Edad del miembro
    vector<Libro> librosPrestados;     // Libros que ha alquilado el miembro
    vector<Revista> revistasPrestadas; // Revistas que ha alquilado el miembro

public:
    // Constructor
    Miembro(string nombre, int edad) : nombre(nombre), edad(edad){}

    // Getters
    int getEdad()
    {
        return edad;
    }

    string getNombre()
    {
        return nombre;
    }

    // Setters
    void setEdad(int edad)
    {
        this->edad = edad;
    }

    void setNombre(string nombre)
    {
        this->nombre = nombre;
    }

    // Método para alquilar un libro
    void alquilarLibro(Libro libro)
    {
        librosPrestados.push_back(libro);   // Agregar a lista
        cout << nombre << " ha alquilado el libro: " << libro.getTitulo() << endl;  // Print que se alquilo con exito
    }

    // Método para alquilar una revista
    void alquilarRevista(Revista revista)
    {
        revistasPrestadas.push_back(revista);   // Agregar a lista
        cout << nombre << " ha alquilado la revista: " << revista.getTitulo() << endl;  // Print que se alquilo con exito
    }

    // Método para devolver un libro
    void devolverLibro(Libro libro)
    {
        // Buscamos y eliminamos el libro de la lista
        for (auto it = librosPrestados.begin(); it != librosPrestados.end(); ++it)
        {
            if (it->getId() == libro.getId())   // Si ID == ID
            {
                librosPrestados.erase(it);  // Borrar de lista
                cout << nombre << " ha devuelto el libro: " << libro.getTitulo() << endl;   // Desplegar que se borro con exito
                return;
            }
        }
        cout << "No se encontró el libro: " << libro.getTitulo() << endl;   // Desplegar que no se borro
    }

    // Método para devolver una revista
    void devolverRevista(Revista revista)
    {
        // Buscamos y eliminamos la revista de la lista
        for (auto it = revistasPrestadas.begin(); it != revistasPrestadas.end(); ++it)
        {
            if (it->getId() == revista.getId()) // Si ID == ID
            {
                revistasPrestadas.erase(it);    // Borrar de lista
                cout << nombre << " ha devuelto la revista: " << revista.getTitulo() << endl;   // Desplegar que se borro con exito
                return;
            }
        }
        cout << "No se encontró la revista: " << revista.getTitulo() << endl;   // Desplegar que no se borro 
    }

    // Mostrar los libros y revistas alquilados
    void mostrarItemsPrestados()
    {
        cout << "Libros prestados a " << nombre << ":" << endl;
        for (Libro libro : librosPrestados)     // Desplegar todos los libros prestados
        {
            libro.mostrarDetallesLibro();
            cout << "------------" << endl;
        }

        cout << "Revistas prestadas a " << nombre << ":" << endl;
        for (Revista revista : revistasPrestadas)   // Desplegar todos los libros prestados
        {
            revista.mostrarDetallesRevista();
            cout << "------------" << endl;
        }
    }
    
    // Mostrar los detalles del miembro
    void mostrarDetalles() const
    {
        cout << "Detalles del miembro:" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }
};

#endif
