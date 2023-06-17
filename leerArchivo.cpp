/*
Autor: Mariana Balderrábano Aguilar
Leer el archivo de texto en C++
*/
#include <iostream>
#include <fstream> //para ifstream
#include <sstream> //para stringstream
#include <vector>
using namespace std;


vector<string> separar(string linea);


int main(int argc, char const *argv[])
{
    ifstream entrada;


    // Excepciones
    // monutoreando el bit para saber
    // entrada.flags(ios_base::failbit);
    entrada.exceptions(ifstream::failbit);


    // try catch
    try
    {
        entrada.open("DatosPeliculas.csv");
        // para verificar que fue correcta
        // manejo normal del error
       
        if (entrada.fail())
        {
            cout << "No puedo leer el archivo... " << endl;
            return -1; //si regresa un valor diferente de 0, termina con un error
        }

        string linea;
        vector<video *> videos;

        int numLinea = 1;

        while (getline(entrada, linea))
        {   
            cout << (numLinea++);


            if (datos.size() == 6)
            {
                //cout << "Pelcula: ";// << endl;
                string id = datos[0]
                string titulo = datos[1];
                double duracion = stod(datos[2]);
                string genero = datos[3];
                double calificacion = stod(datos[4]);
                string fEstreno = datos[5];

                Pelicula* pelicula = new Pelicula(id, titulo, duracion, genero, calificacion, fEstreno);
                videos.push_back(pelicula);
            }
            else
            {
                //cout << "Episodio: ";// << endl;
                string id = datos[0]
                string titulo = datos[1];
                double duracion = stod(datos[2]);
                string genero = datos[3];
                double calificacion = stod(datos[4]);
                string fEstreno = datos[5];
                string idE = datos[6]
                string tituloE = datos[7];
                int temporada = stoi(datos[8]);
                int numEp = stoi(datos[9]);

                Episodio* episodio = new Episodio(id, titulo, duracion, genero, calificacion, fEstreno, idE, tituloE, temporada, numEp);
                videos.push_back(episodio);
            }
            cout << endl;
             
        }
    }
    catch (ifstream::failure &e)
    {
        cout << "ERROR excepción al abrir el archivo" << endl;
        return -1;
    }


    /*
    try{
    entrada.close();
    }
    catch (ifstream::failure &e)
    {
    }
    */
    return 0;
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
/*
    bool incorrecto = true;
    while (incorrecto)
    {


        // cout << "tokens: " << numeroTokens << endl << endl; comprobar si esta contando correctamente
       
        try
        {
            cout << "tokens: " << tokens.at(tokens.size()) << endl;
            incorrecto = false;
        }
        catch (out_of_range &e)
        {
            cout << "indice incorrecto";
            incorrecto = true;
        }
        return tokens;
    }
    */
}
