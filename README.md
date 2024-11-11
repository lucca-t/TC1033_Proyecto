TC1033 Proyecto Final - Sistema de Gestión de Biblioteca

Este proyecto es un sistema de gestión de biblioteca diseñado para facilitar el manejo de libros y el proceso de alquiler y devolución para los miembros registrados. La biblioteca permite registrar libros en su inventario, agregar miembros y gestionar el estado de los libros alquilados, todo dentro de un enfoque de programación orientada a objetos. Este sistema proporciona métodos para que los miembros puedan alquilar libros si están disponibles y devolverlos una vez terminados, manteniendo así un registro actualizado de los recursos de la biblioteca.

Contexto
Este sistema representa una biblioteca que administra un inventario de libros y un registro de miembros. Cada libro tiene atributos como título, autor, ISBN, y disponibilidad, mientras que los miembros tienen información básica como nombre, edad, y una lista de libros alquilados. A través de este sistema, los miembros pueden alquilar y devolver libros, y la biblioteca puede actualizar la disponibilidad de los mismos, proporcionando un modelo básico de administración de una biblioteca.

Funcionalidad
El sistema ofrece las siguientes funcionalidades principales:

Gestión de Libros: Registra y administra un inventario de libros en la biblioteca, verificando la disponibilidad y controlando su estado de alquiler.
Registro de Miembros: Administra una lista de miembros registrados que pueden alquilar libros.
Alquiler y Devolución de Libros: Permite a los miembros alquilar libros disponibles y devolverlos una vez que han terminado, actualizando el inventario de la biblioteca.
El programa funciona en la consola y proporciona un menú simple que permite a los usuarios realizar estas operaciones básicas de gestión.

Consideraciones
Este proyecto está diseñado para funcionar en la consola y utiliza C++ estándar, lo que lo hace compatible con múltiples sistemas operativos. No cuenta con funcionalidades avanzadas como bases de datos, multiusuario, o notificaciones de vencimiento de alquiler, ya que es un modelo de demostración de conceptos básicos de programación orientada a objetos.

Compilación
Para compilar el proyecto, se puede utilizar el siguiente comando:

g++ Libro.h Miembro.h Biblioteca.h main.cpp -o main

Ejecución en Windows

main.exe

Mejoras y Correcciones
Para mejorar la funcionalidad y organización del sistema, se realizaron las siguientes modificaciones:

Validaciones de Alquiler: Se corrigió el manejo de la disponibilidad de libros en la función alquilarLibro para evitar duplicaciones en la lista de libros alquilados