#include <iostream>
#include "ModeloParcial.h"
#include "MultaManager.h"
using namespace std;

int main(){
    ModeloParcial obj;

    cout << "Cantidad de agentes sin multas en el anio 2022: ";
    cout << obj.Punto1();
    cout << endl;
    obj.Punto2();
    cout << endl;
    obj.Punto3();
    cout << endl;
    obj.Punto4();
    cout << endl;

    return 0;
}
