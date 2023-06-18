/*
Autor: Mariana Balderrábano Aguilar 
Definición de subclase Película
*/

#include "Video.h"
#include <iostream>
#include <string>
#include <vector>
#ifndef PELICULA_H
#define PELICULA_H

using namespace std;

class Pelicula : public Video
{
    //Atributos
    protected:
    
    //Métodos
    public:
    Pelicula(string id, string titulo, string genero, string calificacion,string duracion, string fEsreno);
    void imprimeDatos();
};
#endif