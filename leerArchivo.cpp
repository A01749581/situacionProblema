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

vector<Video *> videos;
vector<Pelicula *> peliculas;
vector<Episodio *> episodios;

double calificle;
double califi;
double respuesta;
string genero;
string ser;

int main(int argc, char const *argv[])
{
    //condición para seguir
    while (true)
    {
        //muestra menú
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

        //recibe respuesta
        cin >> respuesta;

        //código para cargar y mostrar el archivo csv
        if (respuesta == 1)
        {
            //crea un objeto ifstream para realizar lectura
            ifstream entrada;
            //abre el archivo
            entrada.open("DatosPeliculas.csv");

            //declara la cariable línea para almacenar cada línea
            string linea;
            //se descarta la primera línea de información
            getline(entrada, linea);

            //ciclo que lee cada línea del archivo
            while (getline(entrada, linea))
            {
                //se llama a la función separar y divide en tokens la línea
                vector<string> datos = separar(linea);

                //define las condiciones para objetos de tipo película
                if (datos.size() == 6)
                {
                    // cout << "Película: " << endl;
                    string id = datos[0];
                    string titulo = datos[1];
                    string duracion = datos[2];
                    string genero = datos[3];
                    string calificacion = datos[4];
                    string fEstreno = datos[5];

                    //se obtienen los datos dados anteriormente en el mismo orden
                    Pelicula *pelicula = new Pelicula(id, titulo, duracion, genero, calificacion, fEstreno);
                    //Se añade película al vector videos
                    videos.push_back(pelicula);

                    //Se añade pelicula al vector peliculas
                    peliculas.push_back(pelicula);
                }
                else
                {
                    //se crean las condiciones para episodios
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

                    //se crea episodio con memoria dinámica
                    Episodio *episodio = new Episodio(id, titulo, genero, calificacion, duracion, fEstreno, idE, tituloE, temporada, numEp);

                    //se inserta episodio al vector video
                    videos.push_back(episodio);

                    //se inserta episodio al vector episodio
                    episodios.push_back(episodio);
                }
            }
            //se llama a close para cerrar el archivo
            entrada.close();
            //se imprimen los videos disponibles con formato
            for (int i = 0; i < videos.size(); i++)
            {
                videos[i]->imprimeDatos();
            }
            
        }
        //código para mostrar los videos con una calificación mayor o igual a la dada
        if(respuesta == 2.1)
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

        //código para mostrar los videos con una género tecleado por el usuario
        if (respuesta == 2.2)
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

        //Código para mostrar todos los episodios de una serie
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

        //Código para mostrar películas con una calificación mayor a la dada por el usuario
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

        //Código para calificar un video 
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

        //Código para salir del ciclo 
        if (respuesta == 6)
        {
            break;
        }
        //Si meten un número que no sea 1,2,3,4,5 o 6, arroja este error
        else 
        {
            cout << "argumento no válido" << endl;
        }
    }
}
vector<string> separar(string linea)
{
    //almacena tokens
    vector<string> tokens; // componentes de la línea

    stringstream entrada(linea); // flujo de datos a partir de una cadena
    string dato;                 // token individual
    int numeroTokens = 0;        // define contador de tokens

    //se realiza la separación usando la coma
    while (getline(entrada, dato, ','))
    {
        //Si el token está vacío, se va a la siguiente línea  
        if (dato != "" && dato != "\n" && dato != "\r")
        {
            // inserta el token al vector 
            tokens.push_back(dato); // GUARDA  en el vector
            //suma 1 al número de tokens
            numeroTokens++;
        }
    }

    // regresa el vector de tokens
    return tokens;
}

