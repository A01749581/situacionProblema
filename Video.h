/*
Autor: Mariana Balderrábano Aguilar 
Definición de superclase Video (clase abstracta)
*/

#include <iostream>
#include <string>
#include <vector>
#ifndef VIDEO_H
#define VIDEO_H

using namespace std;

//Declara clase video
class Video
{
    //Atributos de video
    protected:
    string id;      
    string titulo;      //nombre de video
    string duracion;
    string genero;
    string calificacion;
    string fEstreno;    //fecha de estreno
    

    //Métodos de video
    public:
    Video(string id, string titulo,string duracion, string genero, string calificacion, string fEsreno);
    string getId();
    string getTitulo();
    string getGenero();
    string getCalificacion();
    string getDuracion();
    string getFecha();

    //método abstracto que imprime datos
    virtual void imprimeDatos() = 0;
    //regresa calificación en double
    double getCaliDouble();
    //establece el valor de calificación con el dato en el parámetro 
    double setCalificacion(double calif);
};
#endif