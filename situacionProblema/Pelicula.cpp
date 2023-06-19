/*
Autor: Mariana Balderrábano Aguilar 
Implementación de subclase Película
*/

#include "Pelicula.h"
#include <string>

//Constructor de la clase Película que llama al constructor de la clase base Video
Pelicula::Pelicula(string id, string titulo, string duracion, string genero, string calificacion, string fEsreno): Video(id,titulo,duracion,genero,calificacion,fEsreno)
{
}

//Método sobreescrito para imprimir datos en formato de Película con los datos de Película
void Pelicula::imprimeDatos()
{
    cout << "Id película: " << Video::getId() << endl;
    cout << "Título película: " << Video::getTitulo() << endl;
    cout << "Duración de la película: " << Video::getDuracion() << endl;
    cout << "Género de la película: " << Video::getGenero() << endl;
    cout << "Calificación de la película: " << Video::getCalificacion() << endl;
    cout << "Fecha de estreno de la película: " << Video::getFecha() << endl;
}
