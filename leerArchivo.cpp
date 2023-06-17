/*
Autor: Mariana Balderrábano Aguilar
Leer el archivo de texto en C++
*/
#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"
#include <iostream>
#include <fstream>  
#include <sstream> 
#include <vector>
using namespace std;
vector<string> separar(string linea);
vector <Video*> videos;

int main(int argc, char const *argv[])
{
    ifstream entrada;

    entrada.open("DatosPeliculas.csv");

    string linea;
    getline(entrada, linea);

    while (getline(entrada, linea))
    {
        vector <string> datos = separar(linea);

        if(datos.size() == 6)
        {
            //cout << "Película: " << endl;
            string id = datos[0];
            string titulo = datos[1];
            string duracion = datos[2];
            string genero = datos[3];
            string calificacion = datos[4];
            string fEstreno = datos[5];

            Pelicula* pelicula = new Pelicula(id, titulo, duracion, genero, calificacion, fEstreno);
            videos.push_back(pelicula);
        }
        else
        {
            //cout<<"Episodio: "<< endl;
            string id = datos[0];
            string titulo = datos[1];
            string genero = datos[2];
            string calificacion = datos[3];
            string duracion = datos[4];
            string fEstreno = datos[5];
            string idE = datos[6];
            string tituloE = datos[7];
            string temporada = datos[8];
            string numEp = datos[9];

            Episodio* episodio = new Episodio(id, titulo, genero, calificacion, duracion, fEstreno, idE,tituloE, temporada, numEp);
            videos.push_back(episodio);
        }
        
    }
    
    entrada.close();

    for (int i = 0; i < videos.size(); i++)
    {
        videos[i]->imprimeDatos();
    }
    return 0;
}

vector <string> separar(string linea) 
{
    vector<string> tokens;  //componentes de la línea

    stringstream entrada(linea);    //flujo de datos a partir de una cadena 
    string dato;    //token individual 
    int numeroTokens = 0;
  while (getline(entrada, dato, ','))
    {
        //cout << dato << endl;
        if (dato != "" && dato != "\n" && dato != "\r")
        {
            //cout << dato << numeroTokens <<endl;
            tokens.push_back(dato); // GUARDA  en el vector
            numeroTokens++;
        }
    }
    //cout << "tokens: " << numeroTokens << endl << endl; comprobar si esta contando correctamente
    
    return tokens;
}