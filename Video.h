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
    string titulo;
    string duracion;
    string genero;
    string calificacion;
    string fEstreno;
    //vector <Video *> videos;    //vector de punteros a objetos de tipo video

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
    //double setCalificacion(calif);
};
#endif