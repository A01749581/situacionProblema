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
#include <string>

using namespace std;
vector<string> separar(string linea);
vector<string> separarAmp(string linea);
vector<Video *> videos;
vector<Pelicula *> peliculas;
vector<Episodio *> episodios;
double califi;
double respuesta;
string genero;
string ser;

int main(int argc, char const *argv[])
{
    while (true)
    {
        cout << "---------Menú---------" << endl
             << endl
             << "Opciones\n"
             << "1 cargar y mostrar el archivo csv\n"
             << "2.1 muestra videos con calificación mayor o igual a la tecleada\n"
             << "2.2 género tecleado por usuario\n"
             << "3 Mostrar episodios de una serie\n"
             << "4 Mostrar películas con calificación mayor al número ingresado\n"
             << "5 Calificar un video\n"
             << "6 Salir" << endl;

        cin >> respuesta;
        if (respuesta == 1)
        {
            ifstream entrada;
            entrada.open("DatosPeliculas.csv");

            string linea;
            getline(entrada, linea);

            while (getline(entrada, linea))
            {
                vector<string> datos = separar(linea);

                if (datos.size() == 6)
                {
                    // cout << "Película: " << endl;
                    string id = datos[0];
                    string titulo = datos[1];
                    string duracion = datos[2];
                    string genero = datos[3];
                    string calificacion = datos[4];
                    string fEstreno = datos[5];

                    Pelicula *pelicula = new Pelicula(id, titulo, duracion, genero, calificacion, fEstreno);
                    videos.push_back(pelicula);
                    peliculas.push_back(pelicula);
                }
                else
                {
                    // cout<<"Episodio: "<< endl;
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

                    Episodio *episodio = new Episodio(id, titulo, genero, calificacion, duracion, fEstreno, idE, tituloE, temporada, numEp);
                    videos.push_back(episodio);
                    episodios.push_back(episodio);
                }
            }
            entrada.close();
            for (int i = 0; i < videos.size(); i++)
            {
                videos[i]->imprimeDatos();
            }
            
        }
        
        if(respuesta == 2.1)
        {
            /*
            cout >> "Teclee un género" >> endl;
            cin << gro;
            for (int i = 0; i < videos.size(); i++)
            {
                if(videos[i]->getGenero() == gro)
                {
                    videos[i] -> imprimeDatos();
                }
            }
            */
        }

        if (respuesta == 2.2)
        {
            cout << "Videos por calificación mayor a (calificaciones de 1 a 7): " << endl;
            cin >> califi;

            for (int i = 0; i < videos.size(); i++)
            {
                if(videos[i]->getCaliDouble() >= califi)
                {
                    videos[i] -> imprimeDatos();
                }
                
            }
        }

        if (respuesta == 3)
        {
            /*
            cout << "Serie de la que quieres ver los episodios: " << endl;
            cin >> ser;
            for(int i = 0; i < episodios.size(); i++)
            {
                if(episodios[i] -> getTitulo == ser)
                {
                    episodios[i] -> imprimeDatos();
                }
            }
            */
        }

        if (respuesta == 4)
        {
            cout << "Videos por calificación mayor a (calificaciones de 1 a 7): " << endl;
            cin >> califi;
            for (int i = 0; i < peliculas.size(); i++)
            {
                if(peliculas[i]->getCalificacion() >= califi)
                {
                    peliculas[i] -> imprimeDatos();
                }
                
            }

        }

        if (respuesta == 5)
        {
            cout << "Calificar un video (calificaciones de 1 a 7): " << endl;
            cin >> califi;
            for (int i = 0; i < videos.size(); i++)
            {
                if(peliculas[i]->getCalificacion() >= califi)
                {
                    peliculas[i] -> imprimeDatos();
                }
                
            }

        }

        if (respuesta == 6)
        {
            break;
        }
    }
}
vector<string> separar(string linea)
{
    vector<string> tokens; // componentes de la línea

    stringstream entrada(linea); // flujo de datos a partir de una cadena
    string dato;                 // token individual
    int numeroTokens = 0;
    while (getline(entrada, dato, ','))
    {
        // cout << dato << endl;
        if (dato != "" && dato != "\n" && dato != "\r")
        {
            // cout << dato << numeroTokens <<endl;
            tokens.push_back(dato); // GUARDA  en el vector
            numeroTokens++;
        }
    }
    // cout << "tokens: " << numeroTokens << endl << endl; comprobar si esta contando correctamente

    return tokens;
}
vector<string> separarAmp(string linea)
{
    vector<string> tokens; // componentes de la línea

    stringstream entrada(linea); // flujo de datos a partir de una cadena
    string dato;                 // token individual
    int numeroTokens = 0;
    while (getline(entrada, dato, '&'))
    {
        // cout << dato << endl;
        if (dato != "" && dato != "\n" && dato != "\r")
        {
            // cout << dato << numeroTokens <<endl;
            tokens.push_back(dato); // GUARDA  en el vector
            numeroTokens++;
        }
    }
    // cout << "tokens: " << numeroTokens << endl << endl; comprobar si esta contando correctamente

    return tokens;
}
