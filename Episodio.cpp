#include "Episodio.h"
#include <string>

Episodio::Episodio(string id, string titulo, string genero, string calificacion, string duracion, string fEsreno, string idE,string tituloE,string temporada,string numEp):Video(id,titulo,genero,calificacion,duracion,fEsreno)
{
    this-> idE = idE;
    this-> tituloE = tituloE;
    this-> temporada = temporada;
    this-> numEp = numEp;
}

void Episodio::imprimeDatos()
{
    cout << "Id serie: " << Video::getId() << endl;
    cout << "Título serie: " << Video::getTitulo() << endl;
    cout << "Género de la serie: " << Video::getGenero() << endl;
    cout << "Calificación del episodio: " << Video::getCalificacion() << endl;
    cout << "Duración del episodio: " << Video::getDuracion() << endl;
    cout << "Fecha de estreno del episodio: " << Video::getFecha() << endl;
    cout << "Id del episodio: " << idE << endl;
    cout << "Título del episodio: " << tituloE << endl;
    cout << "Temporada: " << temporada << endl;
    cout << "Número del episodio: " << numEp << endl;
}

