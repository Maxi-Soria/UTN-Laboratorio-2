#include <iostream>
#include "RecuperatorioPrimerParcial.h"
#include "ClasesParticularesArchivo.h"

using namespace std;

int main(){

    RecuperatorioPrimerParcial obj;
    ClasesParticularesArchivo archClp;
    ClaseParticular regClp;
    int tam = archClp.getCantidad();

    for (int i=0 ; i<tam ; i++ ){
        regClp = archClp.leer(i);
        if(regClp.getLegajoProfesor() == 1032){
            cout << regClp.getLegajoAlumno() << endl;
        }
    }
    cout << endl << endl;

    //cout << "CURSOS CON MAYOR AYUDA" << endl;
    //obj.cursoConMayorAyuda();
    //cout << endl;
    //cout << "LOS ALUMNOS CON CLASES MENORES A 1 HORA "<<endl;
    //obj.alumnosConPocaAyuda();
    //cout << endl;
    //cout << "RECAUDACION POR CURSO" << endl;
    //obj.generarEstadistica();
    //cout << endl;
    //obj.mostrarEstadistica();
    cout << endl;
    obj.nuncaRecibioAyuda(1032);
    cout << endl;
    return 0;
}
