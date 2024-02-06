#include <iostream>
using namespace std;
#include "TipoInfraccionArchivo.h"
#include "TipoInfraccion.h"


/*Crear un método que permita guardar un registro de la clase TipoInfraccion en un archivo llamado tiposinfracciones.dat. Crear otro método que permita leer un registro de la clase TipoInfraccion a partir de la posición en el archivo tiposinfracciones.dat.*/
int TipoInfraccionArchivo::getCantidadRegistros()
{
    FILE *p=fopen("tiposinfracciones.dat","rb");
    if (p==NULL)
    {
        return 0;
    }

    fseek (p,0,SEEK_END);
    int bytes=ftell(p);
    fclose(p);
    return bytes/sizeof(TipoInfraccion);

}


bool TipoInfraccionArchivo::guardar(TipoInfraccion reg)
{
    FILE *p= fopen("tiposinfracciones.dat","ab");
    if (p==NULL)
    {
        return false;
    }

    bool pudoEscribir = fwrite (&reg,sizeof(TipoInfraccion),1,p);
    fclose(p);
    return pudoEscribir;

}

TipoInfraccion TipoInfraccionArchivo::leer(int nroRegistro)
{
    TipoInfraccion aux;
    FILE *p= fopen("tiposinfracciones.dat","rb");
    if (p==NULL)
    {
        return aux;
    }

    fseek(p,nroRegistro*sizeof(TipoInfraccion),0);
        fread(&aux,sizeof(TipoInfraccion),1,p);
    fclose(p);
    return aux;
}

