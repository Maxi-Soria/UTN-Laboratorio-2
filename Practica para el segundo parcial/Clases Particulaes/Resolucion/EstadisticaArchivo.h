#ifndef ESTADISTICAARCHIVO_H
#define ESTADISTICAARCHIVO_H
#include "Estadistica.h"


class ArchivoEstadistica{
private:
    char nombre[15];
public:
    ArchivoEstadistica();
    bool guardar(Estadistica reg);
    Estadistica leer(int pos);
    int getCantidad();
    void vaciar();

};

#endif // ESTADISTICAARCHIVO_H
