#include <iostream>
using namespace std;
#include "Examen.h"
#include "TipoInfraccionArchivo.h"
#include "AgenteArchivo.h"
#include "MultaArchivo.h"

/*Hacer un método llamado Punto3 que solicite un ID Tipo de Infracción por teclado. Luego verifique
si el mismo existe en el archivo de tiposinfracciones.dat. De existir, listar la cantidad
de agentes distintos que hayan realizado al menos una multa para este tipo de infracción.
De lo contrario no mostrar nada.

*/
void Examen::Punto3()
{
    TipoInfraccionArchivo archivoTipoInfraccion;
    TipoInfraccion tipoInfraccion;
    AgenteArchivo archivoAgente;
    Agente agente;
    MultaArchivo archivoMulta;
    Multa multa;


    int idPorTeclado;
    int cantAgentes=archivoAgente.getCantidadRegistros();
    int cantTipoInfracciones=archivoTipoInfraccion.getCantidadRegistros();
    int cantMultas=archivoMulta.getCantidadRegistros();

    cout<< "Ingrese un ID Tipo de Infraccion ";
    cin>>idPorTeclado;

    int contador=0;

    for (int i=0; i<cantTipoInfracciones; i++)
    {
        tipoInfraccion=archivoTipoInfraccion.leer(i);
        if (tipoInfraccion.getIdTipoInfraccion()==idPorTeclado)
        {
            for (int j=0; j<cantAgentes; j++)
            {
                agente=archivoAgente.leer(j);
                bool primeravez=true;
                for (int x=0; x<cantMultas; x++)
                {
                    multa=archivoMulta.leer(x);
                    if (agente.getIdAgente()==multa.getIDAgente()&&multa.getTipoInfraccion()==idPorTeclado)
                    {
                        if(primeravez)
                        {primeravez=false;
                        contador++;}
                    }
                }

            }

        }
    }
    if (contador !=0)
    {
        cout<<"La cantidad de agentes distintos que realizaron al menos una multa para este tipo de infracción son ";
        cout<< contador;
    }



}
