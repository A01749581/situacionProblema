#include "Video.h"
#include <iostream>
#include <string>
#include <vector>
#ifndef EPISODIO_H
#define EPISODIO_H
using namespace std;


class Episodio : public Video
{
    //Atributos
    protected:
    string idE;
    string tituloE;
    string temporada;
    string numEp;
    
    //Métodos
    public:
    Episodio(string id, string titulo, string genero, string calificacion,string duracion, string fEsreno, string idE,string tituloE,string temporada,string numEp);
    void imprimeDatos();
};
#endif