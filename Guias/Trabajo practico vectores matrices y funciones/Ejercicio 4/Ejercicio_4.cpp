#include <iostream>
#include <cstdlib>

using namespace std;

/*
Hacer un programa que permita cargar un vector de 10 números enteros en el cual
ninguno de los valores de sus elementos pueda repetirse.
*/

void cargar_vector_sin_repetidos(int vec[], int tam){
    int num;
    bool repet;
    for (int i = 0; i< tam ; i++){

        do{
           cout << "Ingrese el numero para la posicio " << i << " :" ;
           cin >> num;
           repet = false;
           for (int j = 0; j< i ; j++){
                if (vec[j] == num){
                    repet = true;
                    cout << "El numero " << num << " ya esta repetido\n";
                }
           }
        }while(repet);
        vec[i] = num;
    }
    cout << "Vector completo " << endl;
}

int main(){
    setlocale (LC_ALL, "Spanish");
    int const TAM = 5;
    int vec[TAM];

    cargar_vector_sin_repetidos(vec, TAM);

    for(int x = 0; x < TAM; x++){
        cout << vec[x] << " ";
    }

    return 0;
}
