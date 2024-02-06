#ifndef TIPOINFRACCIONARCHIVO_H
#define TIPOINFRACCIONARCHIVO_H
#include "TipoInfraccion.h"
//Crear un m�todo que permita guardar un registro de la clase TipoInfraccion en un archivo llamado tiposinfracciones.dat. Crear otro m�todo que permita leer un registro de la clase TipoInfraccion a partir de la posici�n en el archivo tiposinfracciones.dat.

class TipoInfraccionArchivo
{
public:
    int getCantidadRegistros();
    bool guardar(TipoInfraccion reg);

    TipoInfraccion leer(int nroRegistro);

private:
};

#endif // TIPOINFRACCIONARCHIVO_H
