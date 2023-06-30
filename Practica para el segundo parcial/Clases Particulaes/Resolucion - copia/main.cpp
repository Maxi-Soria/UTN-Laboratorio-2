#include <iostream>
#include "RecuperatorioPrimerParcial.h"
#include "ClasesParticularesArchivo.h"

using namespace std;

int main(){

    RecuperatorioPrimerParcial obj;


    cout << "CURSOS CON MAYOR AYUDA" << endl;
    obj.cursoConMayorAyuda();
    cout << endl;
    cout << "LOS ALUMNOS CON CLASES MENORES A 1 HORA "<<endl;
    obj.alumnosConPocaAyuda();
    cout << endl;
    cout << "RECAUDACION POR CURSO" << endl;
    obj.generarEstadistica();
    cout << endl;
    obj.mostrarEstadistica();
    cout << endl;
    obj.nuncaRecibioAyuda(1032);
    cout << endl;
    return 0;
}
