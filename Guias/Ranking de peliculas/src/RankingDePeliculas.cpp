#include <iostream>
#include <cstdlib>
#include "RankingDePeliculas.h"


using namespace std;


RankingDePeliculas::RankingDePeliculas(){
    _cantPeliculas = 0;
}

void RankingDePeliculas::Agregar(Pelicula peli){
    string t;
    if (_cantPeliculas < 5){
        _peliculas[_cantPeliculas] = peli;
        _titulos[_cantPeliculas] = peli.getTitulo(); ///ACA AGREGO CADA TITULO AL VECTOR
        _cantPeliculas++;
    }

}

void RankingDePeliculas::ordenar(){
    Pelicula aux;
    for (int i=0 ; i<_cantPeliculas ; i++ ){
        for (int j=0 ; j<_cantPeliculas-1 ; j++ ){
            if(_peliculas[j].getPuntuacion() < _peliculas[j+1].getPuntuacion()){
                aux = _peliculas[j];
                _peliculas[j] = _peliculas[j+1];
                _peliculas[j+1] = aux;
            }
        }
    }

}
void RankingDePeliculas::Mostrar(){

    ordenar();
    for (int i=0 ; i<_cantPeliculas ; i++ ){
        cout << i+1 << "- " << _peliculas[i].getTitulo() << "    " << _peliculas[i].getFechaEstreno().toString() << "    " <<  _peliculas[i].getPuntuacion() << endl;
    }

}

void RankingDePeliculas::puntuarPelicula(int eleccion){
    int punt;
    for (int i=0 ; i< _cantPeliculas; i++ ){
        if(_peliculas[i].getTitulo() == _titulos[eleccion-1]){
            punt = _peliculas[i].getPuntuacion()+1;
            _peliculas[i].setPuntuacion(punt);
        }
    }

}

void RankingDePeliculas::mostrarTitulos(){ ///CON ESTE METODO MUESTRO LOS TITULOS ANTES DE VOTAR
    for (int i=0 ; i<_cantPeliculas ; i++ ){

        cout << i+1 << "- " << _titulos[i] << endl;
    }

}
