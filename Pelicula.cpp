
#include "Pelicula.h"

Pelicula::Pelicula(string id, string titulo, string genero, string calificacion, string duracion, string fEsreno): Video(id,titulo,genero,calificacion,duracion,fEsreno)
{
}

void Pelicula::imprimeDatos()
{
    cout << "Id película: " << getId() << endl;
    cout << "Título película: " << getTitulo() << endl;
    cout << "Género de la película: " << getGenero() << endl;
    cout << "Calificación de la película: " << getCalificacion() << endl;
    cout << "Duración de la película: " << getDuracion() << endl;
    cout << "Fecha de estreno de la película: " << getFecha() << endl;
}
