#include <iostream>
#include <cstdlib>
#include "Pelicula.h"


Pelicula::Pelicula(){
    _titulo = "";
    _fechaEstreno = Fecha();
    _puntuacion = 0;
}

Pelicula::Pelicula(string titulo, Fecha fechaEstreno, int puntuacion){
    _titulo = titulo;
    _fechaEstreno = fechaEstreno;
    _puntuacion = puntuacion;
}

string Pelicula::getTitulo(){ return _titulo;}
Fecha  Pelicula::getFechaEstreno(){ return _fechaEstreno;}
int    Pelicula::getPuntuacion(){ return _puntuacion;}

void   Pelicula::setTitulo(string titulo){
    _titulo = titulo;
}

void   Pelicula::setFecha(Fecha fechaEstreno){
    _fechaEstreno = fechaEstreno;
}

void   Pelicula::setPuntuacion(int puntuacion){
    _puntuacion = puntuacion;
}

