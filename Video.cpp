/*
Autor: Mariana Balderrábano Aguilar
Implementación de superclase Video
*/

#include "Video.h"
#include <fstream>
#include <string>

//Constructor de la clase Video que inicializa valores
Video::Video(string id, string titulo, string genero, string calificacion, string duracion, string fEsreno) 
{
    this-> id = id;
    this -> titulo = titulo;
    this -> genero = genero; 
    this -> calificacion =calificacion;
    this -> duracion = duracion;
    this -> fEstreno = fEstreno;

}

//Método con el que se obtiene el Id
string Video::getId()
{
    return id;
}

//Método con el que se obtiene el título del video 
string Video::getTitulo()
{
    return titulo;
}

//Método con el que se obtiene el género del video en string
string Video::getGenero()
{
    return genero;
}

//Método con el que se obtiene la calificación en string
string Video::getCalificacion()
{
    return calificacion;
}

//Método con el que se obtiene la duración en string
string Video::getDuracion()
{
    return duracion;
}

//Método con el que se obtiene la fecha de estreno en string
string Video::getFecha()
{
    return fEstreno;
}

//Método con el que se obtiene la calificación en double
double Video::getCaliDouble()
{
    double c = stod(calificacion);
    return c;
}
