/*
Autor: Mariana Balderrábano Aguilar 
Definición de superclase Video
*/

#include <iostream>
#include <string>
#include <vector>
#ifndef VIDEO_H
#define VIDEO_H

using namespace std;

class Video
{
    //Atributos
    protected:
    string id;
    string titulo;
    string genero;
    string calificacion;
    string duracion;
    string fEstreno;
    vector <Video *> videos;

    //Métodos
    public:
    Video(string id, string titulo, string genero, string calificacion,string duracion, string fEsreno);
    string getId();
    string getTitulo();
    string getGenero();
    string getCalificacion();
    string getDuracion();
    string getFecha();

    virtual void imprimeDatos() = 0;
    double CaliDouble();
};
#endif