
#include "Pelicula.h"
#include <string>

Pelicula::Pelicula(string id, string titulo, string genero, string calificacion, string duracion, string fEsreno): Video(id,titulo,genero,calificacion,duracion,fEsreno)
{
}

void Pelicula::imprimeDatos()
{
    cout << "Id película: " << Video::getId() << endl;
    cout << "Título película: " << Video::getTitulo() << endl;
    cout << "Género de la película: " << Video::getGenero() << endl;
    cout << "Calificación de la película: " << Video::getCalificacion() << endl;
    cout << "Duración de la película: " << Video::getDuracion() << endl;
    cout << "Fecha de estreno de la película: " << Video::getFecha() << endl;
}
