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

        int numLinea = 1;

        while (getline(entrada, linea))
        {
            vector<string> datos = separar(linea);

            cout << (numLinea++);

            if (datos.size() == 6)
            {
                cout << "Pelcula: ";// << endl;
                // new Pelicula(datos)
            }
            else
            {
                cout << "Episodio: ";// << endl;
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
    
}