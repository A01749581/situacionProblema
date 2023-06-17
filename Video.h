/*
Autor: Mariana Balderrábano Aguilar 
Definición de superclase Video
*/

#include <iostream>
#include <string>
#include <vector>
#ifndef FIGURA_H
#define FIGURA_H
using namespace std;

class Video
{
    //Atributos
    protected:
    string Id;
    string titulo;
    string genero;
    double calificacion;
    double duracion;
    string fEstreno;

    //Métodos
    public:
    vector lee();
    Video();
    Video(string id, string titulo, string genero, double calificacion,double duracion, string fEsreno);
    string getId();
    string getTitulo();
    string getGenero();
    double getCalificacion();
    double getDuracion();
    string getFecha();
    virtual void imprimeDatos();
};
#endif