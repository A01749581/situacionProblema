#include "Episodio.h"

Episodio::Episodio(string id, string titulo, string genero, string calificacion, string duracion, string fEsreno, string idE,string tituloE,string temporada,string numEp):Video(id,titulo,genero,calificacion,duracion,fEsreno)
{
    this-> idE = idE;
    this-> tituloE = tituloE;
    this-> temporada = temporada;
    this-> numEp = numEp;
}

void Episodio::imprimeDatos()
{
    cout << "Id serie: " << getId() << endl;
    cout << "Título serie: " << getTitulo() << endl;
    cout << "Género de la serie: " << getGenero() << endl;
    cout << "Calificación del episodio: " << getCalificacion() << endl;
    cout << "Duración del episodio: " << getDuracion() << endl;
    cout << "Fecha de estreno del episodio: " << getFecha() << endl;
    cout << "Id del episodio: " << idE << endl;
    cout << "Título del episodio: " << tituloE << endl;
    cout << "Temporada: " << temporada << endl;
    cout << "Número del episodio: " << numEp << endl;
}

