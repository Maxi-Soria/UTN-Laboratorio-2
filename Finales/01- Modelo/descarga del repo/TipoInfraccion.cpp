#include <iostream>
#include <cstring>
using namespace std;
#include "TipoInfraccion.h"


/*Crear una clase llamada TipoInfraccion que permita registrar un Tipo de Infracci�n. Debe poder registrar el ID de tipo de infracci�n, la descripci�n del tipo de infracci�n,el costo base de la infracci�n y el nivel de severidad de la infracci�n.

Crear un constructor que reciba par�metros para cada atributo de la clase
Crear un constructor vac�o para la clase que establezca 0 a los valores num�ricos y vac�o a los de texto.
Crear setters y getters para cada atributo de la clase
*/

TipoInfraccion::TipoInfraccion()
{
    _idTipoInfraccion=0;
    strcpy(_descripcion, "");
    _costo=0;
    _nivelSeveridad=0;

}

TipoInfraccion::TipoInfraccion(int idTipoInfraccion,string descripcion,float costo,int nivelSeveridad)
{
    _idTipoInfraccion=idTipoInfraccion;
    strcpy(_descripcion, descripcion.c_str());
    _costo=costo;
    if (nivelSeveridad>0&&nivelSeveridad<=10)
    {_nivelSeveridad=nivelSeveridad;}
    else
    {
        cout<<"El nivel de Severidad no es correcto";
    }

}
void TipoInfraccion:: setIdTipoInfraccion(int idTipoInfraccion)
{
    _idTipoInfraccion=idTipoInfraccion;
}
void TipoInfraccion::setDescripcion (string descripcion)
{
    strcpy(_descripcion, descripcion.c_str());
}
void TipoInfraccion::setCosto (float costo)
{
    _costo=costo;
}
void TipoInfraccion:: setNivelSeveridad (int nivelSeveridad)
{
    if (nivelSeveridad>0&&nivelSeveridad<=10)
    {_nivelSeveridad=nivelSeveridad;}
    else
    {
        cout<<"El nivel de Severidad no es correcto";
    }
}
int TipoInfraccion::getIdTipoInfraccion()
{
    return _idTipoInfraccion;
}
string TipoInfraccion:: getDescripcion()
{

    string descripcion;
    descripcion = _descripcion;
    return descripcion;
}


int TipoInfraccion::getNivelSeveridad()
{
    return _nivelSeveridad;
}
