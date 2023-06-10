/*
Autor: Mariana Balderrábano Aguilar
Leer el archivo de texto en C++
*/
#include <iostream>
#include <fstream>  //para ifstream
#include <sstream>  //para stringstream
#include <vector>
using namespace std;

vector <string> separar(string linea);

int main(int argc, char const *argv[])
{
    ifstream entrada;
    entrada.open("DatosPeliculas.csv");

    string linea;

    int numLinea = 1;

    while (getline(entrada, linea))
    {
        vector <string> datos = separar(linea);

        cout << (numLinea ++);

        if(datos.size() == 6)
        {
            cout << "Pelcula: " << endl;
            //new Pelicula(datos)
        }
        else
        {
            cout<<"Episodio: "<< endl;
        }
        cout << endl;
    }

    entrada.close();
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