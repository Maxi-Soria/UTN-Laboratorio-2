#ifndef RANKINGDEPELICULAS_H
#define RANKINGDEPELICULAS_H
#include "Pelicula.h"


class RankingDePeliculas{

    private:
        Pelicula _peliculas[5];
        int _cantPeliculas;
        void ordenar();
        string _titulos[5];///############################
    public:
        RankingDePeliculas();
        void Agregar(Pelicula peli);
        void Mostrar();
        void puntuarPelicula(int eleccion);
        void mostrarTitulos();

};

#endif // RANKINGDEPELICULAS_H
