/*
Autor: Mariana Balderrábano Aguilar 
Definición de superclase Video
*/

#include <iostream>
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
    Video();
    Video(string id, string titulo, string genero, double calificacion,double duracion, string fEsreno);
    string getId();
    string getTitulo();
    string getGenero();
    double getCalificacion();
    double getDuracion();
    virtual void imprimeDatos();
};
#endif