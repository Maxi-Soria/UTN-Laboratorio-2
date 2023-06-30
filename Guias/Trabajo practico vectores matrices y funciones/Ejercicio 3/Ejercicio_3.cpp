#include <iostream>
#include <cstdlib>

using namespace std;

/*
Hacer una funci�n que reciba como par�metros un vector de enteros, su tama�o y un valor entero a buscar y que devuelva en
qu� posici�n se encuentra el valor dentro del vector. En caso de no encontrarlo, devolver -1.
*/

int buscar_posicion(int vec[], int tam, int valor){

    for (int i = 0; i < tam; i++){
        if(vec[i] == valor){
            return i;
        }
    }
    return -1;

}

int main(){
    setlocale (LC_ALL, "Spanish");

    int const TAM = 5;
    int vect[TAM] = {2,-6,-12,10,0};

    cout << "La posicion del numero es: " << buscar_posicion(vect, TAM, 10);

    return 0;
}
