/*
Autor: Mariana Balderrábano Aguilar 
Implementación de subclase Episodio
*/

#include "Episodio.h"
#include <string>

//Constructor de la clase episodio que llama al constructos de la clase base Video  e inicializa idE, tituloE, temporada y numEp
Episodio::Episodio(string id, string titulo, string duracion, string genero, string calificacion,  string fEsreno, string idE,string tituloE,string temporada,string numEp):Video(id,titulo,duracion,genero,calificacion,fEsreno)
{
    this-> idE = idE;
    this-> tituloE = tituloE;
    this-> temporada = temporada;
    this-> numEp = numEp;
}

/*
double Episodio::getCaliDouble()
{
    return stod(calificacion);
}
*/

//Método sobreescrito que imprime los datos con formato de episodio
void Episodio::imprimeDatos()
{
    cout << "Id serie: " << Video::getId() << endl;
    cout << "Título serie: " << Video::getTitulo() << endl;
    cout << "Duración del episodio: " << Video::getDuracion() << endl;
    cout << "Género de la serie: " << Video::getGenero() << endl;
    cout << "Calificación del episodio: " << Video::getCalificacion() << endl;
    cout << "Fecha de estreno del episodio: " << Video::getFecha() << endl;
    cout << "Id del episodio: " << idE << endl;
    cout << "Título del episodio: " << tituloE << endl;
    cout << "Temporada: " << temporada << endl;
    cout << "Número del episodio: " << numEp << endl;
}

