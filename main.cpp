#include "Libro.h"
#include "Miembro.h"
#include "Biblioteca.h"


#include <iostream>
using namespace std;

main(){
   vector<Libro> libros = {
    Libro("1001", true, "978-0-452-28423-4", "1984", "George Orwell", "Dystopia"),
    Libro("1002", true, "978-3-16-148410-0", "Cien años de soledad", "Gabriel García Márquez", "Fantasia"),
    Libro("1003", true, "978-1-56619-907-9", "Don Quijote de la Mancha", "Miguel de Cervantes", "Clasico"),
    Libro("1004", true, "978-0-14-143951-8", "Orgullo y prejuicio", "Jane Austen", "Romance"),
    Libro("1005", true, "978-0-7432-7356-5", "El gran Gatsby", "F. Scott Fitzgerald", "Ficcion"),
    Libro("1006", true, "978-0-08-107070-4", "La sombra del viento", "Carlos Ruiz Zafón", "Misterio"),
    Libro("1007", true, "978-0-06-112008-4", "Matar a un ruiseñor", "Harper Lee", "Drama"),
    Libro("1008", true, "978-0-06-231500-7", "El alquimista", "Paulo Coelho", "Filosofia"),
    Libro("1009", true, "978-0-545-01022-1", "Harry Potter y la piedra filosofal", "J.K. Rowling", "Fantasia"),
};  
vector<Revista> revistas = {
    Revista("5678", true, "Shape Shifter", "2022", "Vogue"),
    Revista("2345", true, "Time", "2023", "Time Inc."),
    Revista("6789", true, "National Geographic", "2021", "National Geographic Society"),
    Revista("3456", true, "The New Yorker", "2023", "Condé Nast"),
    Revista("7890", true, "Forbes", "2023", "Forbes Media"),
    Revista("1234", true, "Sports Illustrated", "2020", "Maven")
};

    Biblioteca biblio = Biblioteca(libros, revistas); // Crear biblioteca con las listas de los contenidos
    cout << "------------" << endl;
    
    Miembro miembro1("Lucca T",20);
    biblio.registrarMiembro(miembro1);
    Miembro miembro2 = Miembro("Juan Gonzalez", 38);  // crear y agregar los miembros
    biblio.registrarMiembro(miembro2);


    cout << "-----------------" << endl; // todo fue agregado correctamente
    biblio.mostrarItems();
    cout << "-----------------" << endl;
    biblio.mostrarMiembros();
    cout << "-----------------" << endl;
    


    biblio.alquilarLibro(miembro1, libros[3].getId()); //alquilando libros
    biblio.alquilarLibro(miembro1, libros[7].getId());
    cout << "------------" << endl;

    biblio.alquilarRevista(miembro1, revistas[0].getId()); //alquilando revistas
    biblio.alquilarRevista(miembro1, revistas[3].getId());  
    cout << "------------" << endl;

    biblio.alquilarLibro(miembro1, "23123123"); // alquilando libro que no existe
    cout << "------------" << endl;

    miembro1.mostrarItemsPrestados();

    cout << "------------" << endl;
    biblio.alquilarLibro(miembro2, libros[3].getId()); // No se puede porque no esta disponible

    biblio.devolverLibro(miembro1, libros[3].getId()); // Libro fue devuelto

    biblio.alquilarLibro(miembro2, libros[3].getId()); // Libro se puede alquilar
     biblio.alquilarRevista(miembro2, revistas[1].getId());
    biblio.alquilarRevista(miembro2, revistas[4].getId());  
    cout << "---------------------" << endl;
    miembro2.mostrarItemsPrestados();



    
    return 0;
}