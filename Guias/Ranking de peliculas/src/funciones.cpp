#include <iostream>
#include "funciones.h"
#include <string>

using namespace std;
Pelicula CargarPelicula(){
    string titulo;
    int dia, mes, anio;
    Pelicula peli;

    cout << "Ingrese el titulo de la pelicula: ";
    cin.ignore();
    getline(cin,titulo);
    cout << endl;
    cout << "Ingrese el dia de la publicacion: ";
    cin >> dia;
    cout << "Ingrese el mes de la publicacion: ";
    cin >> mes;
    cout << "Ingrese el anio de la publicacion: ";
    cin >> anio;

    peli.setTitulo(titulo);
    peli.setFecha(Fecha(dia,mes,anio));


    return peli;
}

int elegirPelicula(){
    int opc;
    cout << "Seleccione que el numero de pelicula: " << endl;
    cin >> opc;
    return opc;
}
