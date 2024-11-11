#include "Libro.h"
#include "Miembro.h"
#include "Biblioteca.h"
#include <iostream>
using namespace std;

main(){
   vector<Libro> libros = {
        Libro("1984", "George Orwell", "978-0-452-28423-4"),
        Libro("Cien años de soledad", "Gabriel García Márquez", "978-3-16-148410-0"),
        Libro("Don Quijote de la Mancha", "Miguel de Cervantes", "978-1-56619-907-9"),
        Libro("Orgullo y prejuicio", "Jane Austen", "978-0-14-143951-8"),
        Libro("El gran Gatsby", "F. Scott Fitzgerald", "978-0-7432-7356-5"),
        Libro("La sombra del viento", "Carlos Ruiz Zafón", "978-0-08-107070-4"),
        Libro("Matar a un ruiseñor", "Harper Lee", "978-0-06-112008-4"),
        Libro("El alquimista", "Paulo Coelho", "978-0-06-231500-7"),
        Libro("Harry Potter y la piedra filosofal", "J.K. Rowling", "978-0-545-01022-1")
    };
    Biblioteca biblio = Biblioteca(libros);

    cout << "------------" << endl;
    Miembro miembro1("Lucca T",20);


    biblio.registrarMiembro(miembro1);
    miembro1.mostrarDetalles();
    cout << "------------" << endl;
    libros[0].mostrarDetallesLibro();


    miembro1.alquilarLibro(libros[0]);
    miembro1.alquilarLibro(libros[1]);
    miembro1.alquilarLibro(libros[2]);
    miembro1.alquilarLibro(libros[3]);
    cout << "------------" << endl;
    miembro1.mostrarLibrosPrestados();
    cout << "------------" << endl;
    miembro1.devolverLibro(libros[2]);
    cout << "------------" << endl;
    miembro1.mostrarLibrosPrestados();
    cout << "------------" << endl;

    Miembro miembro2 = Miembro("Juan Gonzalez", 38);
    biblio.registrarMiembro(miembro2);
    cout << "------------" << endl;
    biblio.mostrarMiembros();
    
    biblio.mostrarLibros();






    

    return 0;
}