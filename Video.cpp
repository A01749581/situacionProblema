/*
Autor: Mariana Balderrábano Aguilar 
Implementación de superclase Video
*/

#include "Video.h"

Video::Video()
{
}

Video::Video(string id, string titulo, string genero, double calificacion, double duracion, string fEsreno): 
Id(Id), titulo(titulo), genero(genero), calificacion(calificacion), duracion(duracion), fEsreno(fEsreno)
{
}

string Video::getId()
{
    return Id();
}

string Video::getTitulo()
{
    return titulo();
}

string Video::getGenero()
{
    return genero;
}

double Video::getCalificacion()
{
    return calificacion;
}

double Video::getDuracion()
{
    return duracion;
}

void Video::imprimeDatos()
{
}
