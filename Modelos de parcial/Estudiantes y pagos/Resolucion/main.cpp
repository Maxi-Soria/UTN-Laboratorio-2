#include <iostream>
#include "PrimerParcial.h"
#include "PagosArchivo.h"
using namespace std;

int main() {


    PrimerParcial obj;
    cout << "LISTA DE RECAUDACION: " << endl;
    obj.listarRecaudacion();
    cout << endl;
    cout << "LISTA DE ALUMNOS NO MOROSOS " << endl;
    obj.listarAlumnosNoMorosos();
    cout << endl;
    cout << "ALUMNOS QUE SOLO PAGARON UN CURSO EN 2021" << endl;
    obj.soloUnCurso();
    cout << endl;
    cout << "CURSOS CON MAYOR PAGO INDIVIDUAL DEL ALUMNO " << endl;
    obj.cursosPremium(1021);
    cout << endl;
    obj.generarEstadistica();
    obj.mostrarEstadistica();

  return 0;
}
