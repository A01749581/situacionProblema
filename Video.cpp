/*
Autor: Mariana Balderrábano Aguilar
Implementación de superclase Video
*/

#include "Video.h"
#include <fstream>

Video::lee()
{
    entrada.open("DatosPeliculas.csv");
    string linea;
    int numLinea = 1;

    vector<string> vectorVideo;
        while (getline(entrada, linea))
        {
            vectorVideo.push_back(linea);
        }
    
}

Video::Video()
{
}

Video::Video(string id, string titulo, string genero, double calificacion, double duracion, string fEsreno) : Id(Id), titulo(titulo), genero(genero), calificacion(calificacion), duracion(duracion), fEsreno(fEsreno)
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

string Video::getFecha()
{
    return fEstreno();
}

void Video::imprimeDatos()
{
    cout << "Id video: " << getId() << endl;
    cout << "Título del video: " << getTitulo() << endl;
    cout << "Género del video: " << getGenero() << endl;
    cout << "Calificación del video: " << getCalificacion() << endl;
    cout << "Duración del video: " << getDuracion() << endl;
    cout << "Fecha de estreno del video: " << getFecha() << endl;
}
