#include <iostream>
#include <cstdlib>

using namespace std;

/*
Hacer una funci�n que reciba como par�metros un vector de enteros y un n�mero entero que
indica la cantidad de componentes del vector, y que devuelva el valor m�nimo contenido en ese vector.
*/

int buscar_menor (int vec[], int TAM){
    int minimo = vec[0];
    for (int i = 1; i < TAM; i++){
        if (vec[i] < minimo){
            minimo = vec[i];
        }
    }
    return minimo;
}

int main(){
    setlocale (LC_ALL, "Spanish");
    int const TAM = 5;
    int vect[TAM] = {2,-6,-12,8,0};

    cout << buscar_menor(vect, TAM);


    return 0;
}
