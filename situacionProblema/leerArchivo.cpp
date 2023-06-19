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

//Vector para separar una línea
vector<string> separar(string linea);

//Vectores que almacenan videos, películas y episodios
vector<Video *> videos;
vector<Pelicula *> peliculas;
vector<Episodio *> episodios;

//variables usadas
int respuesta;
int res;
string generoo;
string seriee;
double califica;
bool x;

//main
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
             << "1 Cargar el archivo csv\n"
             << "2 Mostrar videos en general con: \n"
             << "3 Mostrar episodios de una serie\n"
             << "4 Mostrar películas con calificación mayor al número ingresado\n"
             << "5 Calificar un video\n"
             << "6 Calcula el promedio de la calificación de una serie\n"
             << "7 Salir" << endl;
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
                    // Condiciones para episodios
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

        //muestra videos con calificación mayor o igual a la que recibe o por género
        case 2:
            cout << "1 mostrar videos con una calificación mayor o igual a un valor tecleado\n";
            cout << "2 mostrar videos con un género tecleado por el usuario" << endl;
            //recibe respuesta
            cin >> res;

            if (res == 1)
            {
                cout << "Videos con calificación mayor o igual a: ";
                cin >> califica;

                cout << "Videos con calificación mayor a " << califica << ":\n"
                     << endl;
                
                //recorre el vector de videos e imprime los que tienen calificación mayor o igual a la recibida
                for (int i = 0; i < videos.size(); i++)
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
                //Muestra ejemplos de géneros dentro del archivo
                cout << "Ejemplos de géneros: \nRomance    Accion    Aventura    Drama    Fantasy    Suspenso    Sci-Fi" << endl;
                cout << "Comedia    Misterio    Animacion    Crimen    Drama    Biografia    Familiar" << endl;

                cout << "Género: ";
                //guarda el género tecleado por el usuario
                cin >> generoo;

                cout << "Videos con género " << generoo << ":" << endl;
                bool encontrado = false;

                // Recorre vector video e imprime los que coinciden con el  género introducido
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

                //display error
                if (!encontrado)
                {
                    cout << "Género, no encontrado, favor de introducirlo igual al señalado en el Ejemplos de géneros" << endl;
                }
            }
            break;

        // código que muestra los episodios de una serie.
        case 3:
            {
                bool serieEncontrada = false;
                cout << "Game Of Thrones    The Big Bang Theory    Memories Of The Alhambra    Death Note    Fate Zero    Unbreakable Kimmy Schmidt" << endl;
                cout << "Black Mirror    Chilling Aventura of Sabrina    Stranger Things    Maniac    The Simpsons    The 100    Modern Familiar    Friends" << endl;

                cout << "Introduzca una serie de la que quiere ver los datos de sus episodios: ";
                cin.ignore(); 
                getline(cin, seriee); //pide serie

                //recorre videos y muestra los episodios de la serie definida 
                for (int i = 0; i < videos.size(); i++)
                {
                    Episodio *epi = dynamic_cast<Episodio *>(episodios[i]);
                    if (epi != nullptr && epi->getTitulo() == seriee)
                    {
                        epi->imprimeDatos();
                        serieEncontrada = true;
                    }
                }
                //display error
                if (!serieEncontrada)
                {
                    cout << "Serie no encontrada, intente otra vez" << endl;
                }
                break;
            }
        
        //código que imprime películas con calificación mayor a la introducida por el usuario
        case 4:
        {
            cout << "Películas con calificación mayor a: " << endl;
            cin >> califica; //guarda la calificación 
            bool peliculasEncontradas = false;

            //recorre el vector películas que imprime calificaciones de películas mayores o iguales a la calificación ingresada
            for (int i = 0; i < peliculas.size(); i++)
            {
                if (peliculas[i]->getCaliDouble() >= califica)
                {
                    peliculas[i]->imprimeDatos();
                    peliculasEncontradas = true;
                }
            }

            //despliega error
            if (!peliculasEncontradas)
            {
                cout << "No se encontraron películas con una calificación mayor a " << califica << endl;
            }

            break;
        }

        //código para calificar un video y modifica la calificación
        case 5:
        {
            string tituloVideo;
            double nuevaCalificacion;

            cout << "Ingrese el título de la película o nombre del capítulo de la serie a calificar: ";
            cin.ignore();
            getline(cin, tituloVideo);
            //pide y almacena el título del video

            bool videoEncontrado = false;

            //recorre vector video y verifica que los objetos sean de tipo episodio para después compararlo con el título
            for (int i = 0; i < videos.size(); i++)
            {
                Episodio *epis = dynamic_cast<Episodio *>(videos[i]);
                if (epis != nullptr)
                {
                    //compáralo con el código
                    if (epis->getTituloE() == tituloVideo)
                    {
                        videoEncontrado = true;
                        cout << "Ingresa la nueva calificación (del 1 al 7): ";
                        cin >> nuevaCalificacion;
                        //define el rango válido de calificación
                        if (nuevaCalificacion >= 1 && nuevaCalificacion <= 7)
                        {
                            epis->setCalificacion(nuevaCalificacion);

                            cout << "Calificación actualizada correctamente " << endl;
                            break;
                        }
                    }
                }

                // verifica que es película y si el titulo coincide con el título ingresado
                else if (videos[i]->getTitulo() == tituloVideo)
                {
                    videoEncontrado = true;
                    cout << "Ingresa la nueva calificación(del 1 al 7): ";
                    cin >> nuevaCalificacion;

                    //valida calificaciones 
                    if (nuevaCalificacion >= 1 && nuevaCalificacion <= 7)
                    {
                        videos[i]->setCalificacion(nuevaCalificacion);
                        cout << "Calificación actualizada correctamente " << endl;
                        break;
                    }
                }
            }
            // display error 
            if (!videoEncontrado)
            {
                cout << "No se encuentra el título o la calificación no está en el rango del 1 al 7" << endl;
            }

            break;
        }

        //calcula promedio de serie
        case 6:
        {
            cout << "Game Of Thrones    The Big Bang Theory    Memories Of The Alhambra    Death Note    Fate Zero    Unbreakable Kimmy Schmidt" << endl;
            cout << "Black Mirror    Chilling Aventura of Sabrina    Stranger Things    Maniac    The Simpsons    The 100    Modern Familiar    Friends" << endl;

            cout << "Nombre de la serie de la que desea obtener el promedio: " << endl;
            cin.ignore();
            getline(cin, seriee);

            bool serieEncontrada = false;
            double suma = 0;
            int ep = 0;

            //recorre vector de  videos y calcula la suma de las calificaciones 
            for (int i = 0; i < videos.size(); i++)
            {
                Episodio *epi = dynamic_cast <Episodio *> (videos[i]);
                if (epi != nullptr && epi->getTitulo() == seriee)
                {
                    suma = suma + stod(videos[i]->getCalificacion());
                    ep++;
                    serieEncontrada = true;
                }
            }

            //obtiene promedio
            if (serieEncontrada)
            {
                double promedio;
                promedio = suma / ep;

                cout << "El promedio de las calificaciones de la serie " << seriee << " es de: " << promedio << endl;
            }

            //despliga error
            else 
            {
                cout << "Serie no encontrada, intente otra vez" << endl;
            }
            break;
        }

        //salir
        case 7:
            cout << "Ha salido, hasta pronto :)"<<endl;
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
