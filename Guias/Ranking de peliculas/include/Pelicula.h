#ifndef PELICULA_H
#define PELICULA_H
#include <string>
#include "Fecha.h"

using namespace std;


class Pelicula{
    private:
        string _titulo;
        Fecha _fechaEstreno;
        int _puntuacion;
    public:
        Pelicula();
        Pelicula(string titulo, Fecha fechaEstreno, int puntuacion);
        void Cargar();
        void Mostrar();

        string getTitulo();
        Fecha getFechaEstreno();
        int getPuntuacion();

        void setTitulo(string titulo);
        void setFecha(Fecha fechaEstreno);
        void setPuntuacion(int puntuacion);




};

#endif // PELICULA_H
