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

//Clase Pelicula que hereda de video 
class Pelicula : public Video
{
    //Atributos
    private:
    
    //Métodos
    public:
    Pelicula(string id, string titulo, string duracion, string genero, string calificacion, string fEsreno);
    //double getCaliDouble();
    //Sobreescribe el método
    void imprimeDatos();
};
#endif