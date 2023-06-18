/*
Autor: Mariana Balderrábano Aguilar
Implementación de superclase Video
*/

#include "Video.h"
#include <fstream>
#include <string>


Video::Video(string id, string titulo, string genero, string calificacion, string duracion, string fEsreno) 
{
    this-> id = id;
    this -> titulo = titulo;
    this -> genero = genero; 
    this -> calificacion =calificacion;
    this -> duracion = duracion;
    this -> fEstreno = fEstreno;

}

string Video::getId()
{
    return id;
}

string Video::getTitulo()
{
    return titulo;
}

string Video::getGenero()
{
    return genero;
}

string Video::getCalificacion()
{
    return calificacion;
}


string Video::getDuracion()
{
    return duracion;
}

string Video::getFecha()
{
    return fEstreno;
}

double Video::CaliDouble()
{
    return stod(calificacion);
}
