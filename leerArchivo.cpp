/*
Autor: Mariana Balderrábano Aguilar
Leer el archivo de texto en C++
*/
#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector<string> separar(string linea);
vector<Video *> videos;
vector<Pelicula *> peliculas;
vector<Episodio *> episodios;

int respuesta;
int res;
string generoo;
string seriee;
double califica;
bool x;

int main(int argc, char const *argv[])
{
    // condición para seguir
    x = true;

    // declara la variable línea para almacenar cada línea
    string linea;
    // crea un objeto ifstream para realizar lectura
    ifstream entrada;
    while (x)

    {
        // muestra menú
        cout << "---------Menú---------" << endl
             << "Opciones\n"
             << "1 cargar el archivo csv\n"
             << "2 Mostrar videos en general con: \n"
             << "3 Mostrar episodios de una serie\n"
             << "4 Mostrar películas con calificación mayor al número ingresado\n"
             << "5 Calificar un video\n"
             << "6 Salir" << endl;
        cout << "Introduzca un número del 1 al 6 de acuerdo con su elección \n"
             << endl;
        // recibe respuesta
        cin >>
            respuesta;
        switch (respuesta)
        {

        // código para cargar el archivo csv
        case 1:

            // abre el archivo
            entrada.open("DatosPeliculas.csv");

            // se descarta la primera línea de información
            getline(entrada, linea);

            // ciclo que lee cada línea del archivo
            while (getline(entrada, linea))
            {
                // se llama a la función separar y divide en tokens la línea
                vector<string> datos = separar(linea);

                // define las condiciones para objetos de tipo película
                if (datos.size() == 6)
                {
                    // cout << "Película: " << endl;
                    string id = datos[0];
                    string titulo = datos[1];
                    string duracion = datos[3];
                    string genero = datos[2];
                    string calificacion = datos[4];
                    string fEstreno = datos[5];

                    // se obtienen los datos dados anteriormente en el mismo orden
                    Pelicula *pelicula = new Pelicula(id, titulo, duracion, genero, calificacion, fEstreno);

                    // Se añade película al vector video
                    videos.push_back(pelicula);

                    // Se añade pelicula al vector peliculas
                    peliculas.push_back(pelicula);
                }
                else if (datos.size() == 10)
                {
                    // se crean las condiciones para episodios
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

                    // se crea episodio con memoria dinámica
                    Episodio *episodio = new Episodio(id, titulo, genero, calificacion, duracion, fEstreno, idE, tituloE, temporada, numEp);

                    // se inserta episodio al vector video
                    videos.push_back(episodio);

                    // se inserta episodio al vector episodio
                    episodios.push_back(episodio);
                }
            }
            // se llama a close para cerrar el archivo
            entrada.close();
            cout << "Archivo cargado con éxito" << endl;
            break;

        case 2:
            cout << "1 mostrar videos con una calificación mayor o igual a un valor tecleado\n";
            cout << "2 mostrar videos con un género tecleado por el usuario" << endl;
            cin >> res;

            if (res == 1)
            {
                cout << "Videos con calificación mayor o igual a: ";
                cin >> califica;

                cout << "Videos con calificación mayor a " << califica << ":\n"
                     << endl;
                for (int i = 0; i < peliculas.size(); i++)
                {

                    if (videos[i]->getCaliDouble() >= califica)
                    {
                        videos[i]->imprimeDatos();
                    }
                }
                break;
            }
            else if (res == 2)
            {
                cout << "Ejemplos de géneros: \nRomance    Accion    Aventura    Drama    Fantasy    Suspenso    Sci-Fi" << endl;
                cout << "Comedia    Misterio    Animacion    Crimen    Drama    Biografia    Familiar" << endl;

                cout << "Género: ";
                cin >> generoo;

                cout << "Videos con género " << generoo << ":" << endl;
                bool encontrado = false;
                for (int i = 0; i < videos.size(); i++)
                {
                    string videoGenero = videos[i]->getGenero();

                    // si encuentra el género lo imprime, de lo contrario, regresa no positiono npos.
                    // npos para no caer en excepción

                    if (videoGenero.find(generoo) != string::npos)
                    {
                        videos[i]->imprimeDatos();
                        encontrado = true;
                    }
                }

                if (!encontrado)
                {
                    cout << "Género, no encontrado, favor de introducirlo igual al señalado en el Ejemplos de géneros" << endl;
                }
            }
            break;

        /*
        case 3:
        {
            bool encontrado = false;
            string seriee;
            cout << "Game Of Thrones    The Big Bang Theory    Memories Of The Alhambra    Death Note    Fate Zero    Unbreakable Kimmy Schmidt" << endl;
            cout << "Black Mirror    Chilling Aventura of Sabrina    Stranger Things    Maniac    The Simpsons    The 100    Modern Familiar    Friends" << endl;

            cout << "Introduzca una serie de la que quiere ver los datos de sus episodios: ";
            cin.ignore();
            getline(cin, seriee);

            for (int i = 0; i < episodios.size(); i++)
            {
                Episodio *epi = dynamic_cast<Episodio *> (videos[i]);
                if(epi != 0)
                {
                    episodios[i]->imprimeDatos();
                    encontrado = true;
                }
            }
            if (!encontrado)
            {
                cout << "Serie no encontrada, favor de escribir otra o escribirla correctamente" << endl;
            }
            break;
        }
        break;
        */
        case 6:
            x = false;
            break;

        default:
            cout << "argumento no válido" << endl;
            break;
        }
    }
}

vector<string> separar(string linea)
{
    // almacena tokens
    vector<string> tokens; // componentes de la línea

    stringstream entrada(linea); // flujo de datos a partir de una cadena
    string dato;                 // token individual
    int numeroTokens = 0;        // define contador de tokens

    // se realiza la separación usando la coma
    while (getline(entrada, dato, ','))
    {
        // Si el token está vacío, se va a la siguiente línea
        if (dato != "" && dato != "\n" && dato != "\r")
        {
            // inserta el token al vector
            tokens.push_back(dato); // GUARDA  en el vector
            // suma 1 al número de tokens
            numeroTokens++;
        }
    }

    // regresa el vector de tokens
    return tokens;
}
